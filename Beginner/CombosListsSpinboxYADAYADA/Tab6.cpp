# include "dialog.h"

void Dialog::init_TAB6(){

}

void Dialog::load_TAB6(){

}

void Dialog::save_TAB6(){

}


// slots
void Dialog::on_SpinBoxButtonBox_accepted(){
    save_TAB6();
    accept();
}


void Dialog::on_SpinBoxButtonBox_rejected(){
    reject();
}
