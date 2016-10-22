#include "notepadwindow.h"

NotepadWindow::NotepadWindow(QWidget *parent)
    : QMainWindow(parent)
{
    txtEditor_= new QTextEdit(this);
    setCentralWidget(txtEditor_);

    //Establecemos el tamaño inicial de la ventana
        this->setGeometry(30, 30, 800, 600);

    //Establecemos el título de la ventana
        this->setWindowTitle(tr("MI EDITOR DE TEXTO"));

    //Inicializamos los menus
    mainMenu_=new QMenuBar(this);

    mnuArchivo_=new QMenu(tr("&Archivo"),this);
    mainMenu_->addMenu(mnuArchivo_);

    //creamos el toolbar
    toolbar_=new QToolBar();
    addToolBar(toolbar_);
    setMenuBar(mainMenu_);

    // Definimos las acciones del menu

    actArchivoAbrir_=new QAction(tr("&Abrir"),this);
    actArchivoAbrir_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    mnuArchivo_->addAction(actArchivoAbrir_);

    actArchivoGuardar_=new QAction(tr("&Guardar"),this);
    actArchivoGuardar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    mnuArchivo_->addAction(actArchivoGuardar_);

    actArchivoCerrar_=new QAction(tr("&Cerrar"),this);
    actArchivoCerrar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_W));
    mnuArchivo_->addAction(actArchivoCerrar_);

    mnuEditar_ = new QMenu(tr("&Editar"));
    mainMenu_->addMenu(mnuEditar_);

        actEditarCopiar_ = new QAction(tr("&Copiar"), this);
        actEditarCopiar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
        mnuEditar_->addAction(actEditarCopiar_);

        actEditarPegar_ = new QAction(tr("&Pegar"), this);
        actEditarPegar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
        mnuEditar_->addAction(actEditarPegar_);

        actEditarCortar_ = new QAction(tr("&Cortar"), this);
        actEditarCortar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
        mnuEditar_->addAction(actEditarCortar_);

        actEditarDeshacer_ = new QAction(tr("&Deshacer"), this);
        actEditarDeshacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
        mnuEditar_->addAction(actEditarDeshacer_);

        actEditarRehacer_ = new QAction(tr("&Rehacer"), this);
        actEditarRehacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_I));
        mnuEditar_->addAction(actEditarRehacer_);


    mnuFormato_ = new QMenu(tr("&Formato"));
    mainMenu_->addMenu(mnuFormato_);

        actFormatoFuente_ = new QAction(tr("&Fuente"), this);
        mnuFormato_->addAction(actFormatoFuente_);

    mnuAyuda_=new QMenu(tr("&Ayuda"),this);
    mainMenu_->addMenu(mnuAyuda_);

        actAyudaAcercaDe_= new QAction(tr("&Acerca de"),this);
        mnuAyuda_->addAction(actAyudaAcercaDe_);

    // Las agregamos al toolbar
        toolbar_->addAction(actArchivoAbrir_);
        toolbar_->addAction(actArchivoGuardar_);
        toolbar_->addAction(actArchivoCerrar_);
        toolbar_->addAction(actEditarCopiar_ );
        toolbar_->addAction(actEditarPegar_ );
        toolbar_->addAction(actEditarCortar_ );
        toolbar_->addAction(actEditarDeshacer_ );
        toolbar_->addAction(actEditarRehacer_ );
        toolbar_->addAction(actAyudaAcercaDe_);


        //Agregamos la barra de menú a la ventana
        this->setMenuBar(mainMenu_);

        //Inicializamos el editor de texto
        txtEditor_ = new QTextEdit(this);

        //Agregamos el editor de texto a la ventana
        this->setCentralWidget(txtEditor_);

        // Mantenemos el toolbar fijo arriba
        toolbar_->setAllowedAreas(Qt::TopToolBarArea);
        toolbar_->setMovable(false);

        // Definimos que el texto se muestre a la derecha del icono
        toolbar_->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        // Definimos iconos para las acciones del toolbar
        actArchivoAbrir_->setIcon(QIcon(":/new/prefix1/imagenes/abrir.png"));
        actArchivoCerrar_->setIcon(QIcon(":/new/prefix1/imagenes/cerrar.png"));
        actArchivoGuardar_->setIcon(QIcon(":/new/prefix1/imagenes/guardar.png"));
        actEditarDeshacer_->setIcon(QIcon(":/new/prefix1/imagenes/deshacer.png"));
        actEditarRehacer_->setIcon(QIcon(":/new/prefix1/imagenes/rehacer.png"));
        actEditarCortar_->setIcon(QIcon(":/new/prefix1/imagenes/cortar.png"));
        actEditarCopiar_->setIcon(QIcon(":/new/prefix1/imagenes/copiar.png"));
        actEditarPegar_->setIcon(QIcon(":/new/prefix1/imagenes/pegar.png"));
        actAyudaAcercaDe_->setIcon(QIcon(":/new/prefix1/imagenes/ayuda.png"));
        actFormatoFuente_->setIcon(QIcon(":/new/prefix1/imagenes/fuente.jpg"));



        // Nuevo toolbar para negrita subrayado y cursiva
        addToolBarBreak();
        newToolbar_ = new QToolBar(this);
        newToolbar_->setAllowedAreas(Qt::TopToolBarArea);
        newToolbar_->setMovable(false);
        addToolBar(newToolbar_);

        // Definimos las acciones
        actEditarNegrita_ = new QAction(QIcon(":/new/prefix1/imagenes/negrita.jpg"), tr("Negrita"), this);
        actEditarCursiva_ = new QAction(QIcon(":/new/prefix1/imagenes/cursiva.jpg"), tr("Cursiva"), this);
        actEditarSubrayado_ = new QAction(QIcon(":/new/prefix1/imagenes/subrayado.jpg"), tr("Subrayado"), this);

        // Las agregamos al toolbar
        newToolbar_->addAction(actEditarNegrita_);
        newToolbar_->addAction(actEditarCursiva_);
        newToolbar_->addAction(actEditarSubrayado_);

        //Conectamos las acciones de los menus con nuestros slots

        connect(actArchivoAbrir_, SIGNAL(triggered()),this,SLOT(alAbrir()));
        connect(actArchivoGuardar_, SIGNAL(triggered()),this,SLOT(alGuardar()));
        connect(actArchivoCerrar_, SIGNAL(triggered()),this,SLOT(alCerrar()));
        connect(actEditarCopiar_,   SIGNAL(triggered()), txtEditor_,    SLOT(copy()));
        connect(actEditarPegar_,    SIGNAL(triggered()), txtEditor_,    SLOT(paste()));
        connect(actEditarCortar_,    SIGNAL(triggered()), txtEditor_,    SLOT(cut()));
        connect(actEditarDeshacer_,    SIGNAL(triggered()), txtEditor_,    SLOT(undo()));
        connect(actEditarRehacer_,    SIGNAL(triggered()), txtEditor_,    SLOT(redo()));
        connect(actFormatoFuente_,  SIGNAL(triggered()), this,SLOT(alFuente()));
        connect(actAyudaAcercaDe_,  SIGNAL(triggered()), this,SLOT(alAcercaDe()));
        connect(actEditarNegrita_, SIGNAL(triggered()), this, SLOT(alNegrita()));
        connect(actEditarCursiva_, SIGNAL(triggered()), this, SLOT(alCursiva()));
        connect(actEditarSubrayado_, SIGNAL(triggered()), this, SLOT(alSubrayado()));

}

NotepadWindow::~NotepadWindow()
{

}

void NotepadWindow::alAbrir(){
    //Mostramos un dialogo de apertura de ficheros
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getOpenFileName(this,
                                                   tr("Abrir archivo de texto plano"),
                                                   "",
                                                   tr("Archivo de texto plano (*.txt)"));
    if(nombreArchivo != ""){
        //INTENTAMOS ABRIR EL ARCHIVO
        QFile archivo;
        archivo.setFileName(nombreArchivo);
        if(archivo.open(QFile::ReadOnly)){
            //si se pudo abrir el archivo, lo leemos y lo colocamos
            txtEditor_->setPlainText(archivo.readAll());
            //se cierra el fichero
            archivo.close();
        }
    }
}

void NotepadWindow::alGuardar(){

    QString nombreArchivo;
    nombreArchivo = QFileDialog::getSaveFileName(this,
                                                   tr("Guardar archivo de texto plano"),
                                                   "",
                                                   tr("Guardar de texto plano (*.txt)"));
    if(nombreArchivo != ""){
        //INTENTAMOS guardar EL ARCHIVO
        QFile archivo;
        archivo.setFileName(nombreArchivo);
        if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
            //Si se puede abrir el archivo ,escribimos el contenido
            archivo.write(txtEditor_->toPlainText().toUtf8());
            //Se cierra el fichero
            archivo.close();
        }
    }
}


void NotepadWindow::alCerrar(){
    //qApp->quit();
    exit(0);
}

void NotepadWindow::alFuente()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, txtEditor_->font(), this);
    if (ok) {
        // Si el usuario hizo click en OK, se establece la fuente seleccionada
        txtEditor_->setFont(font);
    }
}

void NotepadWindow::alAcercaDe(){

    QMessageBox msgBox;
    msgBox.setText("Qt Creator 3.0.0""\n""\n""Based on Qt 5.2.0 (GCC 4.6.1, 64 bit)""\n""\n""Curso de QT""\n""\n""Aplicacion NOTEPAD ");

    msgBox.setIconPixmap(QPixmap(":/new/prefix1/imagenes/descarga.jpg"));
    msgBox.exec();
}

void NotepadWindow::alNegrita()
{
    if (txtEditor_->fontWeight() != QFont::Black)
        txtEditor_->setFontWeight(QFont::Black);
    else
        txtEditor_->setFontWeight(QFont::Normal);
}

void NotepadWindow::alCursiva()
{
    if (!txtEditor_->fontItalic())
        txtEditor_->setFontItalic(true);
    else
        txtEditor_->setFontItalic(false);
}

void NotepadWindow::alSubrayado()
{
    if (!txtEditor_->fontUnderline())
        txtEditor_->setFontUnderline(true);
    else
        txtEditor_->setFontUnderline(false);
}
