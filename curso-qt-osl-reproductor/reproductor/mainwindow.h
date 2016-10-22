#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDir>
#include <QSlider>
#include <QFileDialog>
#include <QToolButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QMessageBox>
#include <QEvent>
#include <QMouseEvent>
#include "metadatadialog.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    QGridLayout*        lytMain_;
    QWidget*            wgtMain_;
    QMediaPlayer*       mediaPlayer_;
    QSlider*            playerSlider_;
    QVideoWidget*       videoWidget_;
    QSlider*            volumeSlider_;
    QToolButton*        btnOpen_;
    QToolButton*        btnPlay_;
    QToolButton*        btnPause_;
    QToolButton*        btnStop_;

    QMenuBar*       mainMenu_;
    QMenu*          mnuArchivo_;
    QAction*        actArchivoAbrir_;
    QMenu*          actArchivoRecientes_;
    QToolBar*       toolbar_;
    QMenu*          mnuAyuda_;
    QAction*        actAyudaAcercaDe_;
    QMenu*          mnuVer_;
    QAction*        actVerPantallaCompleta_;
    QAction*        actMetadata_;
    QAction*        actArchivoAbrirSTR_;


private slots:
    void onOpen();
    void onSeek();
    void onDurationChanged(qint64 duration);
    void onPositionChanged(qint64 position);
    void onVolumeChanged(int volume);

    void alAcercaDe();
    void pantalla_completa();
    bool eventFilter(QObject *obj, QEvent *event);
    void metadata();
    void onOpenSTR();

};

#endif // MAINWINDOW_H
