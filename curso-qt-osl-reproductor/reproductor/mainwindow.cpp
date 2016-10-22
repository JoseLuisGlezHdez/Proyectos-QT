#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //Create central widget and set main layout
    wgtMain_ = new QWidget(this);//declaramos un widget que va en el centro , y solo puede ir uno
    lytMain_ = new QGridLayout(wgtMain_);
    wgtMain_->setLayout(lytMain_);
    setCentralWidget(wgtMain_);

    //Inicializamos los menus
    mainMenu_=new QMenuBar(this);

    mnuArchivo_=new QMenu(tr("&Archivo"),this);
    mainMenu_->addMenu(mnuArchivo_);

    mnuAyuda_=new QMenu(tr("&Ayuda"),this);
    mainMenu_->addMenu(mnuAyuda_);

    mnuVer_=new QMenu(tr("&Ver"),this);
    mainMenu_->addMenu(mnuVer_);


    toolbar_=new QToolBar();
    addToolBar(toolbar_);

    setMenuBar(mainMenu_);


    actArchivoAbrir_=new QAction(tr("&Abrir"),this);
    actArchivoAbrir_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    mnuArchivo_->addAction(actArchivoAbrir_);

    actArchivoRecientes_=new QMenu(tr("&Recientes"),this);
    mnuArchivo_->addMenu(actArchivoRecientes_);

    actAyudaAcercaDe_= new QAction(tr("&Acerca de"),this);
    mnuAyuda_->addAction(actAyudaAcercaDe_);

    actVerPantallaCompleta_= new QAction(tr("&Full Screem"),this);
    mnuVer_->addAction(actVerPantallaCompleta_);

    actMetadata_=new QAction(tr("Metadata"),this);
    mnuVer_->addAction(actMetadata_);

    actArchivoAbrirSTR_=new QAction(tr("AbrirStr"),this);
    mnuArchivo_->addAction(actArchivoAbrirSTR_);


    //Initialize widgets
    mediaPlayer_  = new QMediaPlayer(this);//objeto que se encarga de todo lo del video
    playerSlider_ = new QSlider(Qt::Horizontal, this);
    videoWidget_  = new QVideoWidget(this);
    volumeSlider_ = new QSlider(Qt::Horizontal, this);//barra de desplazamiento, poner vertical si la queremos vertical :)
    btnOpen_      = new QToolButton(this);
    btnPlay_      = new QToolButton(this);
    btnPause_     = new QToolButton(this);
    btnStop_      = new QToolButton(this);

    //Setup widwgets
    videoWidget_->setMinimumSize(400, 400);//donde se ve el video
    mediaPlayer_->setVideoOutput(videoWidget_);//posicion de donde pone el video, lo pone en videoWidget_
    mediaPlayer_->setVolume(100);
    videoWidget_->setAspectRatioMode(Qt::KeepAspectRatio);//mantener la resolucion
    volumeSlider_->setRange(0, 100);//rango del volumen, te devuelve un valor.
    volumeSlider_->setSliderPosition(100);//posicion por defecto

    //Populate grid layout
    lytMain_->addWidget(videoWidget_,  0, 0, 1, 5);//son cordenadas , que son celdas
    lytMain_->addWidget(playerSlider_, 1, 0, 1, 5);
    lytMain_->addWidget(btnOpen_,      2, 0, 1, 1);
    lytMain_->addWidget(btnPlay_,      2, 1, 1, 1);
    lytMain_->addWidget(btnPause_,     2, 2, 1, 1);
    lytMain_->addWidget(btnStop_,      2, 3, 1, 1);
    lytMain_->addWidget(volumeSlider_, 2, 4, 1, 1);

    //Buttons icons
    btnOpen_->setIcon(QIcon(QPixmap(":/icons/resources/eject.png")));
    btnPause_->setIcon(QIcon(QPixmap(":/icons/resources/pause.png")));
    btnPlay_->setIcon(QIcon(QPixmap(":/icons/resources/play.png")));
    btnStop_->setIcon(QIcon(QPixmap(":/icons/resources/stop.png")));
    videoWidget_->installEventFilter(this);



    //Connections
    connect(btnOpen_,      SIGNAL(pressed()),               this,         SLOT(onOpen()));
    connect(btnPlay_,      SIGNAL(pressed()),               mediaPlayer_, SLOT(play()));
    connect(btnPause_,     SIGNAL(pressed()),               mediaPlayer_, SLOT(pause()));
    connect(btnStop_,      SIGNAL(pressed()),               mediaPlayer_, SLOT(stop()));
    connect(playerSlider_, SIGNAL(sliderReleased()),        this,         SLOT(onSeek()));
    connect(mediaPlayer_,  SIGNAL(durationChanged(qint64)), this,         SLOT(onDurationChanged(qint64)));
    connect(mediaPlayer_,  SIGNAL(positionChanged(qint64)), this,         SLOT(onPositionChanged(qint64)));
    connect(volumeSlider_, SIGNAL(sliderMoved(int)),        this,         SLOT(onVolumeChanged(int)));

    connect(actArchivoAbrir_, SIGNAL(triggered()),this,SLOT(onOpen()));
    connect(actAyudaAcercaDe_,  SIGNAL(triggered()), this,SLOT(alAcercaDe()));
    connect(actVerPantallaCompleta_,SIGNAL(triggered()),this,SLOT(pantalla_completa()));
    connect(actMetadata_,SIGNAL(triggered()),this,SLOT(metadata()));
    connect(actArchivoAbrirSTR_, SIGNAL(triggered()),this,SLOT(onOpenSTR()));

}

MainWindow::~MainWindow()
{

}

void MainWindow::onOpen()
{


    //Show file open dialog
    QString fileName = QFileDialog::getOpenFileName(this,
                                            tr("Abrir archivo"));
    if (fileName != "") {
        mediaPlayer_->setMedia(QUrl::fromLocalFile(fileName));
    }
    actArchivoRecientes_->addAction(new QAction(fileName,this));
}

void MainWindow::onSeek()
{
    mediaPlayer_->setPosition(playerSlider_->sliderPosition());
}

void MainWindow::onDurationChanged(qint64 duration)
{
    playerSlider_->setRange(0, duration);
}

void MainWindow::onPositionChanged(qint64 position)
{
    playerSlider_->setSliderPosition(position);
}

void MainWindow::onVolumeChanged(int volume)
{
    mediaPlayer_->setVolume(volume);
}


void MainWindow::alAcercaDe(){

    QMessageBox msgBox;
    msgBox.setText("Qt Creator 3.0.0""\n""\n""Based on Qt 5.2.0 (GCC 4.6.1, 64 bit)""\n""\n""Built on Dec 10 2013 at 11:45:55""\n""\n""Copyright 2008-2013 Digia Plc. All rights reserved.");

    msgBox.setIconPixmap(QPixmap(":/new/prefix1/descarga.jpg"));
    msgBox.exec();
}


void MainWindow::pantalla_completa(){
    if(videoWidget_->isFullScreen())
    {
        videoWidget_->setFullScreen(false);
    }
    else
        videoWidget_->setFullScreen(true);

}
bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    QMouseEvent *mouse = static_cast<QMouseEvent *>(event);

    if (obj == videoWidget_) {
        if (event->type() == QEvent::MouseButtonDblClick) {
            if(mouse->button() == Qt::LeftButton){
                if(!videoWidget_->isFullScreen()){
                    videoWidget_->setFullScreen(true);
                }
                else{
                    videoWidget_->setFullScreen(false);
                }
                return true;
            }
        }
        else{
            return false;
        }
    }
    return false;
}

void MainWindow::metadata(){
    MetadataDialog md(mediaPlayer_);
    md.exec();
}

void MainWindow::onOpenSTR(){

    mediaPlayer_->setMedia(QUrl("http://208.92.53.87:80/MAXIMAFM"));//REPRODUCE MEDIANTE STREAMING
}
