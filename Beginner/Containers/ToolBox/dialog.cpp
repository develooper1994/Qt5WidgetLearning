#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    init();
}

Dialog::~Dialog(){
    delete ui;
}

void Dialog::itemDoubleClicked(QListWidgetItem *item){
    QString url =item->data(Qt::ItemDataRole::UserRole).toString();
    QDesktopServices::openUrl(QUrl(url));
}

void Dialog::init(){

    //clear pages toolbox
    while (ui->toolBox->count()>0) {
        ui->toolBox->removeItem(0);  // there is no at or anything. It just pop out the page.
    }

    //add pages to toolbox
    addCategory("News");
    addCategory("Social Media");
    addCategory("Search Engines");

    addNews();
    addSocial();
    addSearch();
}

void Dialog::addCategory(QString name){
    QListWidget* list = new QListWidget(this);
    ui->toolBox->addItem(list, QIcon(":/images/world.png"), name);

    connect(list, &QListWidget::itemDoubleClicked, this, &Dialog::itemDoubleClicked);
}

void Dialog::addLink(QListWidget *list, QString name, QString url){
    // user only sees item but item has url to open.
    // hiding link under the icon and name
    QListWidgetItem* item = new QListWidgetItem(QIcon(":/images/page_world.png"), name);
    item->setData(Qt::ItemDataRole::UserRole, url);
    list->addItem(item);
}

void Dialog::addNews(){
    QListWidget* list = qobject_cast<QListWidget*>(ui->toolBox->widget(0));

    if (!list) {
        qWarning("Couldn't find News List!");
        return;
    }

    addLink(list, "Google", "www.google.com");
    addLink(list, "BBC", "https://www.bbc.com/news");
    addLink(list, "github", "github.com");
}

void Dialog::addSocial(){
    QListWidget* list = qobject_cast<QListWidget*>(ui->toolBox->widget(1));

    if (!list) {
        qWarning("Couldn't find Social List!");
        return;
    }

    addLink(list,"Facebook", "http://www.facebook.com");
    addLink(list,"YouTube", "http://www.youtube.com");
}

void Dialog::addSearch(){
    QListWidget* list = qobject_cast<QListWidget*>(ui->toolBox->widget(2));

    if (!list) {
        qWarning("Couldn't find Search List!");
        return;
    }

    addLink(list,"Google", "http://www.google.com");
    addLink(list,"Yahoo", "http://www.yahoo.com");
}


