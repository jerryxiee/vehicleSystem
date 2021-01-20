#include "videowindow.h"
#include "ui_videowindow.h"

VideoWindow::VideoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VideoWindow)
{
    ui->setupUi(this);
    //创建进程
    this->process = new QProcess;
    this->process->setProcessChannelMode(QProcess::MergedChannels);
    //mplayer路径
    mp_path="/bin/mplayer";
    //创建定时器
    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&VideoWindow::onTimeout);
    //隐藏音量调节条
    ui->volchange->setRange(-100,50);
    ui->volchange->hide();
    //设置步长
    ui->horizontalSlider->setSingleStep(10);
    //设置关闭listwidget的滚动条
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

VideoWindow::~VideoWindow()
{
    delete ui;
}

void VideoWindow::on_commandLinkButton_clicked()
{
    this->process->kill();

    //恢复初始ui
    icon.addFile(QString::fromUtf8(":/video/video/play.png"));
    ui->play->setIcon(icon);
    ui->play->setIconSize(QSize(50, 50));
    ui->play->setCheckable(true);
    ui->horizontalSlider->setValue(0);
    ui->vd_len->setText("00:00:00");
    ui->vd_po->setText("00:00:00");
    ui->listWidget->clear();

    //返回上一级窗体
    this->parentWidget()->show();
    this->hide();
}

void VideoWindow::video_play(QString vd_path)
{
    this->process->kill();
    this->process=new QProcess;

    //播放视频命令
    QStringList cmd;
    //"-loop"循环播放 |"-geometry"视频窗口开始位置| "-zoom" 视频窗口大小
    cmd <<vd_path<< "-slave"<<"-quiet" <<"-geometry" << "80:30"<<"-zoom" << "-x"<<"560" <<"-y"<<"320"<<"-loop"<<"0";

    this->process->start(mp_path,cmd);          //开启进程
    connect(this->process,SIGNAL(readyReadStandardOutput()),this,SLOT(video_data()));//关联视频数据处理槽函数
    timer->start(1000);                 //设置定时1s
}

void VideoWindow::video_data()  //获取视频信息
{
    this->process->write("get_time_length\n");  //视频时长
    this->process->write("get_time_pos\n");     //视频当前播放位置
    this->process->write("get_percent_pos\n");  //视频当前播放位置百分比

    while(this->process->canReadLine())
    {
        //获取数据
        QString  message(this->process->readLine());    //读取数据
        QStringList mess_list = message.split("=");     //跳过等号
        if(mess_list[0] == "ANS_LENGTH")                //视频时长
        {
            vd_length = mess_list[1].toDouble();        //获取时长
            ui->horizontalSlider->setRange(0,vd_length);    //设置进度条范围
            QTime n(0,0,0);
            QTime time = n.addSecs(vd_length);
            qDebug()<<time.toString("hh:mm:ss");
            ui->vd_len->setText(time.toString("hh:mm:ss")); //将时长转换为时间戳格式
        }
        if(mess_list[0] == "ANS_TIME_POSITION")//当前时间位置
        {
            ntime = mess_list[1].toDouble();        //获取当前播放时间
            ui->horizontalSlider->setValue(ntime);  //设置进度条当前位置
            QTime n(0,0,0);
            QTime time = n.addSecs(ntime);
            qDebug()<<time.toString("hh:mm:ss");
            ui->vd_po->setText(time.toString("hh:mm:ss")+" /");//将时长转换为时间戳格式
        }
    }
}

void VideoWindow::on_commandLinkButton_3_clicked()      //添加文件
{
    int flag=0;
    //打开视频
    fileName = QFileDialog::getOpenFileNames(this, tr("添加视频文件"),"/JR/project1/avi", tr("Images (*.avi *.mp4)"));
    //添加列表，筛选重复
    if(ui->listWidget->count() != -1)
    {
        for(QStringList::iterator at = fileName.begin();at != fileName.end();at++)
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
        if(fileName.count() !=0)
        {
            ui->listWidget->addItems(fileName);
        }
}

//音量调节
void VideoWindow::on_volume_toggled(bool checked)
{
    if(checked)
    {
        ui->volchange->show();//点击显示
    }
    else
    {
        ui->volchange->hide();
    }
}

void VideoWindow::on_play_toggled(bool checked)         //播放暂停
{
    if(checked) //暂停
    {
        //设置图标为播放
        icon.addFile(QString::fromUtf8(":/video/video/play.png"));
        ui->play->setIcon(icon);
        ui->play->setIconSize(QSize(50, 50));
        ui->play->setCheckable(true);
        timer->stop();
        if(ui->listWidget->count() == 0)    //判断播放列表为空
        {
            QMessageBox::warning(this,tr("提示"),tr("播放列表为空，请添加视频文件！"), QMessageBox::Ok );
        }
        else
        {
            //暂停，取消关联
            this->process->write("pause\n");
            disconnect(this->process,SIGNAL(readyReadStandardOutput()),this,SLOT(video_data()));
            //video_play(ui->listWidget->currentItem()->text());

        }

    }
    else        //播放
    {
         //设置图标为暂停
        icon.addFile(QString::fromUtf8(":/video/video/stop.png"));
        ui->play->setIcon(icon);
        ui->play->setIconSize(QSize(50, 50));
        ui->play->setCheckable(true);

        this->process->write("pause\n");
        connect(this->process,SIGNAL(readyReadStandardOutput()),this,SLOT(video_data()));
        timer->start();
    }
}

void VideoWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)    //双击列表播放
{
    video_play(item->text());
    icon.addFile(QString::fromUtf8(":/video/video/stop.png"));
    ui->play->setIcon(icon);
    ui->play->setIconSize(QSize(50, 50));
    ui->play->setCheckable(true);
}

void VideoWindow::on_next_clicked()//下一个
{
    //判断视频列表中当前位置是否为最后一项，如是，设置其位置为首项
    if(ui->listWidget->currentRow() == ui->listWidget->count()-1)
    {
        ui->listWidget->setCurrentRow(0);
        //this->process->write("pause\n");
        video_play(ui->listWidget->currentItem()->text());
    }
    else
    {
        ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);
        video_play(ui->listWidget->currentItem()->text());
    }
}

void VideoWindow::on_prev_clicked() //上一个
{
    //判断视频列表中当前位置是否为首项，如是，设置其位置为最后一项
    if(ui->listWidget->currentRow() == 0)
    {
        ui->listWidget->setCurrentRow(ui->listWidget->count()-1);
        //this->process->write("pause\n");
        video_play(ui->listWidget->currentItem()->text());
    }
    else
    {
        ui->listWidget->setCurrentRow(ui->listWidget->currentRow()-1);
        video_play(ui->listWidget->currentItem()->text());
    }
}

void VideoWindow::on_del_clicked()  //删除
{
    if(ui->listWidget->count()==0)
    {
        QMessageBox::warning(this,tr("提示"),tr("播放列表为空，无法删除！"), QMessageBox::Ok );
    }
    else
    {
        //删除列表中内容
        fileName.removeOne(ui->listWidget->currentItem()->text());
        this->process->kill();
        ui->listWidget->clear();
        ui->listWidget->addItems(fileName);
        ui->listWidget->setCurrentRow(0);
    }
}

void VideoWindow::on_volchange_sliderMoved(int position)    //音量调节
{
    QString slide1="volume "+QString::number(position)+" 2\n";  //跳转至绝对音量
    this->process->write(slide1.toUtf8());
}

void VideoWindow::on_horizontalSlider_sliderMoved(int position) //进度条调节
{
    ntime=position;
}

void VideoWindow::on_horizontalSlider_actionTriggered(int action)    //单击进度条实现快进快退
{
    if(action==1||action==3)    //单击右边快进
    {
        QString slide="seek +10 0\n";
        this->process->write(slide.toUtf8());
    }
    if(action==2||action==4)        //单击右边快退
    {
        QString slide="seek -10 0\n";
        this->process->write(slide.toUtf8());
    }
}

void VideoWindow::on_horizontalSlider_sliderPressed() //滑动按下时暂停播放
{
    icon.addFile(QString::fromUtf8(":/video/video/play.png"));
    ui->play->setIcon(icon);
    ui->play->setIconSize(QSize(50, 50));
    ui->play->setCheckable(true);
    this->process->write("pause\n");
    disconnect(this->process,SIGNAL(readyReadStandardOutput()),this,SLOT(video_data()));

}

void VideoWindow::on_horizontalSlider_sliderReleased()//滑动弹起时继续播放当前位置
{
    icon.addFile(QString::fromUtf8(":/video/video/stop.png"));
    ui->play->setIcon(icon);
    ui->play->setIconSize(QSize(50, 50));
    ui->play->setCheckable(true);

    QString slide="seek "+QString::number(ntime)+" 2\n";
    this->process->write(slide.toUtf8());
    this->process->write("pause\n");
    connect(this->process,SIGNAL(readyReadStandardOutput()),this,SLOT(video_data()));
}

void VideoWindow::onTimeout()
{
     this->process->write("get_time_pos\n");
}
