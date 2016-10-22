#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QFontDialog>
#include <QClipboard>
#include <QKeySequence>
#include <QMessageBox>
#include <QTextEdit>
#include <QToolBar>
#include <QIcon>

class NotepadWindow : public QMainWindow
{
    Q_OBJECT

public:
    NotepadWindow(QWidget *parent = 0);
    ~NotepadWindow();

private slots:

    void alAbrir();
    void alGuardar();
    void alCerrar();
    void alFuente();
    void alAcercaDe();
    void alNegrita();
    void alCursiva();
    void alSubrayado();


private:
       QTextEdit *     txtEditor_;
       QMenuBar*       mainMenu_;
       QMenu*          mnuArchivo_;
       QAction*        actArchivoAbrir_;
       QAction*        actArchivoGuardar_;
       QAction*        actArchivoCerrar_;
       QMenu*          mnuFormato_;
       QAction*        actFormatoFuente_;
       QMenu*          mnuEditar_;
       QAction*        actEditarCopiar_;
       QAction*        actEditarPegar_;
       QAction*        actEditarCortar_;
       QAction*        actEditarDeshacer_;
       QAction*        actEditarRehacer_;
       QMenu*          mnuAyuda_;
       QAction*        actAyudaAcercaDe_;
       QClipboard *    portapapeles_;

       QToolBar*       toolbar_;
       QToolBar *      newToolbar_;

       QAction *       actEditarNegrita_;
       QAction *       actEditarCursiva_;
       QAction *       actEditarSubrayado_;

};
#endif // NOTEPADWINDOW_H
