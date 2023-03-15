#include "dialog.h"

// findChildren is better implementation(Page3.cpp)
QString extras="";
QObjectList objectsFound;
template<typename T>
void searchForChildren(QObject* root, const char* searchingChild, int level=0){
    const QObjectList& childrens = root->children();
    if(childrens.empty()) return;

    foreach (QObject* obj, childrens) {
        if(!obj->inherits(searchingChild))
            searchForChildren<T>(obj, searchingChild, level+1);
        else{
            T* child = qobject_cast<T*>(obj);
            if (!child) return;
            objectsFound.append(child);
        }
    }
}


void Dialog::on_pushButton_2_clicked()
{
    int level = 5;
    const char searchingFor[]="QCheckBox";
    QObject* root=this;
    /*
    QString extras="";
    QObjectList boxes = root->children();
    foreach (QObject* obj, boxes) {
        if(obj->inherits(searchingFor)){
            QCheckBox* box = qobject_cast<QCheckBox*>(obj);
            if(box && box->isChecked()){
                extras += "#" + box->text();
            }
        }
    }
*/
    searchForChildren<QCheckBox>(root, searchingFor, level);
    foreach (QObject* obj, objectsFound) {
        QCheckBox* cb = qobject_cast<QCheckBox*>(obj);
        if(cb->isChecked())
            extras.append(", ").append(cb->text());
    }
    QMessageBox::information(this, ui->labelExtras->text(), extras+" selected");
    extras="";
    objectsFound.clear();
}
