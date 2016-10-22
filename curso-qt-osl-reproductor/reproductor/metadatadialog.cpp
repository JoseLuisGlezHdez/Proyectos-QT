#include "metadatadialog.h"
#include "ui_metadatadialog.h"

MetadataDialog::MetadataDialog(QMediaPlayer* player,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MetadataDialog)
{
    ui->setupUi(this);
    player_=player;

    foreach(QString key,player_->availableMetaData()){
    ui->listMetadata->insertItem(ui->listMetadata->count(),key + ": "+ player_->metaData(key).toString());
    }

}

MetadataDialog::~MetadataDialog()
{
    delete ui;
}


