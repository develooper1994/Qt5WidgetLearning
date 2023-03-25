# include "dialog.h"

void init_TAB6(){

}

void load_TAB6(){

}

void save_TAB6(){

}


// slots
void Dialog::on_SpinBoxButtonBox_accepted(){
    save_TAB6();
    accept();
}


void Dialog::on_SpinBoxButtonBox_rejected(){
    reject();
}
