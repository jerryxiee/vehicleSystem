#include "musicwindow.h"
#include "ui_musicwindow.h"

MusicWindow::MusicWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MusicWindow)
{
    ui->setupUi(this);
    //创建进程
    this->process = new QProcess;
    this->process->setProcessChannelMode(QProcess::MergedChannels);
    mp_path="/bin/mplayer";
    //创建定时器
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MusicWindow::onTimeout);

    //listwidget 设置
    ui->lrc->verticalScrollBar()->setValue(10);
    ui->lrc->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  //设置关闭listwidget的滚动条
    ui->lrc->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  //设置关闭listwidget的滚动条
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    ui->label->setStyleSheet("color:rgb(255, 255, 255)");
//    ui->mp3name->setStyleSheet("color:rgb(255, 255, 255)");
//    ui->singer->setStyleSheet("color:rgb(255, 255, 255)");
//    ui->album->setStyleSheet("color:rgb(255, 255, 255)");
    ui->lrc_change->setSingleStep(10);
    ui->vol_change->setRange(-100,50);
    ui->vol_change->hide();

}

MusicWindow::~MusicWindow()
{
    delete ui;
}

void MusicWindow::on_commandLinkButton_clicked()
{
    this->process->kill();
    //恢复初始ui
    icon.addFile(QString::fromUtf8(":/music/music/play.png"));
    ui->play->setIcon(icon);
    ui->play->setIconSize(QSize(60, 60));
    ui->play->setCheckable(true);
    ui->lrc_change->setValue(0);
    ui->len->setText("00:00:00");
    ui->pos->setText("00:00:00");
    ui->listWidget->clear();
    ui->lrc->clear();
    ui->mp3name->clear();
    ui->album->clear();
    ui->singer->clear();

    this->parentWidget()->show();
    this->hide();
}

void MusicWindow::music_play(QString music)     //音乐播放
{
    this->process->kill();
    this->process=new QProcess;

    QStringList cmd;
    cmd << music << "-slave"<<"-quiet" <<"-zoom" << "x11" ;
//    this->process = new QProcess;
    this->process->setProcessChannelMode(QProcess::MergedChannels);
    this->process->start(mp_path,cmd);
     //timer->start(1000);
    connect(this->process,SIGNAL(readyReadStandardOutput()),this,SLOT(music_data()));
    ui->lrc->clear();
    //显示歌词
    lrc_show(music);

}

void MusicWindow::on_addfiles_clicked()         //添加mp3和lrc文件
{
    int flag=0;
    //打开音乐文件
    musicFile = QFileDialog::getOpenFileNames(this, tr("添加视频文件"),"/JR/project1", tr("Images (*.mp3)"));

    //添加到listWidget列表中
    if(ui->listWidget->count() != -1)
    {
        for(QStringList::iterator at = musicFile.begin();at != musicFile.end();at++)
        {
            for(int i=0;i<ui->listWidget->count();i++)
            {
                if(*at == ui->listWidget->item(i)->text())
                {
                    flag=1;
                    continue;
                }
            }
            if(flag==0)
                ui->listWidget->addItem(*at);
            else
                flag=0;
        }
    }
    else
        if(musicFile.count() !=0)
        {
            ui->listWidget->addItems(musicFile);
        }

    //添加MP3文件后自动添加lrc文件
    QStringList pf;
    QStringList path;
    QDir dir("/JR/project1");    //打开目录
    QStringList filters;        //解析lrc

    path<<"/JR/project1/";
    lrcFile.clear();
    filters << "*.lrc";             //歌词文件
    pf= dir.entryList(filters);     //添加列表

    for(int i=0;i<pf.size();i++)
    {
        lrcFile<<path.at(0)+pf.at(i);  //拼接路径和文件名
        //qDebug() <<"lrcFile"<<lrcFile;
    }
}

void MusicWindow::lrc_show(QString mp3name)         //歌词显示
{
    mp3name.chop(3);
    QString lrcname = mp3name + "lrc";          //歌词文件名
    qDebug() << "lrc:" << lrcname;
    //迭代器
    QStringList::const_iterator it;
    it = qFind(lrcFile,lrcname);
    if(it == lrcFile.end())     //没有找到对应歌曲的歌词
    {
        //清空列表
        ui->lrc->clear();
        return ;
    }
    timeList.clear();    //清空时间列表
    lrcList.clear();
    ui->lrc->clear();
    ui->lrc->verticalScrollBar()->setSliderPosition(0);      //设置listwidget的滚动条
    //写入歌词到listwidget中
    QFile lrc(lrcname);
    lrc.open( QIODevice::ReadOnly|QIODevice::Truncate);                 //打开歌词文件
    QTextStream textStream(&lrc);
    textStream.setCodec("GBK");                     //设置编码格式
    while (true)
    {
        QString line = textStream.readLine();       //一次读取一行数据存入line中
        if (line.isNull())
            break;
        else
        {
            line.remove("\n");
            lrcList<<line;            //每一行都追加到lrcList中
        }                                           //此时数据为时间+歌词
    }

    QString ti = lrcList.at(0).mid(4).remove("]");
    QString ar = lrcList.at(1).mid(4).remove("]").remove(" ");
    QString al = lrcList.at(2).mid(4).remove("]").remove(" ");
    qDebug()<<"ti"<<ti;ui->mp3name->setText(ti);    //歌名
    qDebug()<<"ar"<<ar;ui->singer->setText(ar);     //专辑
    qDebug()<<"al"<<al;ui->album->setText(al);      //歌手
    qDebug()<<lrcList.at(0);

    for (int i =4; i<lrcList.size(); i++)  //跳过前四行,处理秒数和歌词
    {
        QString lrc_at = lrcList.at(i).mid(10);        //歌词
        QListWidgetItem *item = new QListWidgetItem(lrc_at);
        item->setTextAlignment(Qt::AlignCenter);        //设置歌词居中
        ui->lrc->addItem(item);             //写入到lrc中
        //qDebug()<<"item"<<item;

       /* int mm = lrc_list.at(i).mid(1,2).toInt();  //分
        int ss = lrc_list.at(i).mid(4,2).toInt();  //秒
        int ll = lrc_list.at(i).mid(7,1).toDouble()/10;  //厘秒*/
        //时间戳转换为秒数(厘秒）
        double lrc_sec=lrcList.at(i).mid(1,2).toInt()*60 + lrcList.at(i).mid(4,2).toInt() + lrcList.at(i).mid(7,1).toDouble()/10;
        timeList << QString::number(lrc_sec);       //读取歌词文件中的时间存入timeList中
        //qDebug()<<"timeList"<<timeList;
    }
}

void MusicWindow::on_volume_toggled(bool checked)   //音量调节
{
    if(checked)
    {
        ui->vol_change->show();     //点击显示
    }
    else
    {
        ui->vol_change->hide();
    }
}

void MusicWindow::music_data()  //音频数据
{
    this->process->write("get_time_length\n");//视频时长
    this->process->write("get_time_pos\n");     //视频当前播放位置
    //this->process->write("get_percent_pos\n");  //视频当前播放位置百分比

    //qDebug()<<data;
    while(this->process->canReadLine())
    {
        //获取数据
        QString  message(this->process->readLine());
        QStringList mess_list = message.split("=");     //跳过等号
        if(mess_list[0] == "ANS_LENGTH")                //视频时长
        {
            int vd_length = mess_list[1].toDouble();
            ui->lrc_change->setRange(0,vd_length);
            QTime n(0,0,0);
            QTime time = n.addSecs(vd_length);
            //qDebug()<<time.toString("hh:mm:ss");
            ui->len->setText(time.toString("hh:mm:ss"));
        }
        if(mess_list[0] == "ANS_TIME_POSITION")//当前时间位置
        {
            ntime = mess_list[1].toDouble();
            ui->lrc_change->setValue(ntime);
            QTime n(0,0,0);
            QTime time = n.addSecs(ntime);
            //qDebug()<<time.toString("hh:mm:ss");
           ui->pos->setText(time.toString("hh:mm:ss"));     //转换为时间戳格式显示

           double t = mess_list[1].toDouble();
           int index = timeList.indexOf(QString::number(t));    //匹配时间，返回list索引
           //qDebug()<<"index"<<index;
           if(index != -1)
           {
                //ui->lrc->setCurrentRow(index);//根据播放时间，设置listwidget当前显示row
                //设置正在播放的歌词字体变大、颜色为白色
                qDebug()<<"index"<<index;
                ui->lrc->item(index)->setFont(QFont(tr("微软雅黑"),15));
                ui->lrc->item(index)->setTextColor(Qt::white);
                if(index>=1)     //前一项恢复原来状态
                {
                    ui->lrc->item(index-1)->setFont(QFont(tr("微软雅黑"),12));
                    ui->lrc->item(index-1)->setTextColor(Qt::black);
                }
                if(index>5)//播放到第5行时，移动滚动条位置，使用当前显示的歌词移到中间
                {
                    ui->lrc->verticalScrollBar()->setSliderPosition(index-5);
                }
           }
        }
    }
}

void MusicWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)    //双击播放
{
    ui->mp3name->clear();
    ui->album->clear();
    ui->singer->clear();
    music_play(item->text());
    icon.addFile(QString::fromUtf8(":/music/music/stop.png"));
    ui->play->setIcon(icon);
    ui->play->setIconSize(QSize(60, 60));
    ui->play->setCheckable(true);
    qDebug()<<"timer->start";
    timer->start(1000);
}



void MusicWindow::on_play_toggled(bool checked)     //播放暂停
{
    if(checked) //暂停
    {
        icon.addFile(QString::fromUtf8(":/music/music/play.png"));
        ui->play->setIcon(icon);
        ui->play->setIconSize(QSize(60, 60));
        ui->play->setCheckable(true);
        timer->stop();
        if(ui->listWidget->count() == 0)    //判断播放列表为空
        {
            QMessageBox::warning(this,tr("提示"),tr("播放列表为空，请添加视频文件！"), QMessageBox::Ok );
        }
        else
        {
            this->process->write("pause\n");
            disconnect(this->process,SIGNAL(readyReadStandardOutput()),this,SLOT(music_data()));
        }

    }
    else        //播放
    {
        icon.addFile(QString::fromUtf8(":/music/music/stop.png"));
        ui->play->setIcon(icon);
        ui->play->setIconSize(QSize(60, 60));
        ui->play->setCheckable(true);

        this->process->write("pause\n");
        connect(this->process,SIGNAL(readyReadStandardOutput()),this,SLOT(music_data()));
        timer->start();
    }
}

void MusicWindow::on_prev_clicked()     //上一首
{
    ui->mp3name->clear();
    ui->album->clear();
    ui->singer->clear();
    if(ui->listWidget->currentRow() == 0)
    {
        ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
        //this->process->write("pause\n");
        music_play(ui->listWidget->currentItem()->text());
    }
    else
    {
        ui->listWidget->setCurrentRow(ui->listWidget->currentRow()-1);
        music_play(ui->listWidget->currentItem()->text());
    }
}

void MusicWindow::on_next_clicked()     //下一首
{
    ui->mp3name->clear();
    ui->album->clear();
    ui->singer->clear();
    if(ui->listWidget->currentRow() == ui->listWidget->count()-1)
    {
        ui->listWidget->setCurrentRow(0);
        //this->process->write("pause\n");
        music_play(ui->listWidget->currentItem()->text());
    }
    else
    {
        ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
        music_play(ui->listWidget->currentItem()->text());
    }
}

void MusicWindow::on_del_clicked()      //删除
{
    if(ui->listWidget->count()==0)
    {
        QMessageBox::warning(this,tr("提示"),tr("播放列表为空，无法删除！"), QMessageBox::Ok );
    }
    else
    {
        musicFile.removeOne(ui->listWidget->currentItem()->text());
        this->process->kill();
        ui->listWidget->clear();
        ui->listWidget->addItems(musicFile);
    }
}

void MusicWindow::on_vol_change_sliderMoved(int position)       //音量调节
{
    QString slide="volume "+QString::number(position)+" 2\n";
    this->process->write(slide.toUtf8());
}



void MusicWindow::on_lrc_change_sliderMoved(int position)   //进度条滑动
{
    ntime=position;
}

void MusicWindow::on_lrc_change_actionTriggered(int action)     //单击进度条实现快进快退
{
    if(action==1||action==3)
    {
        QString slide="seek +10 0\n";
        this->process->write(slide.toUtf8());
    }
    if(action==2||action==4)
    {
        QString slide="seek -10 0\n";
        this->process->write(slide.toUtf8());
    }
}

void MusicWindow::on_lrc_change_sliderPressed()     //滑动按下时暂停
{
    icon.addFile(QString::fromUtf8(":/music/music/play.png"));
    ui->play->setIcon(icon);
    ui->play->setIconSize(QSize(60, 60));
    ui->play->setCheckable(true);
    this->process->write("pause\n");
    disconnect(this->process,SIGNAL(readyReadStandardOutput()),this,SLOT(music_data()));

}

void MusicWindow::on_lrc_change_sliderReleased()    //滑动弹起时继续播放当前位置
{
    icon.addFile(QString::fromUtf8(":/music/music/stop.png"));
    ui->play->setIcon(icon);
    ui->play->setIconSize(QSize(60, 60));
    ui->play->setCheckable(true);

    QString slide="seek "+QString::number(ntime)+" 2\n";
    this->process->write(slide.toUtf8());
    this->process->write("pause\n");
    connect(this->process,SIGNAL(readyReadStandardOutput()),this,SLOT(music_data()));
}

void MusicWindow::onTimeout()           //定时器
{
    this->process->write("get_time_pos\n");     //视频当前播放位置
}
