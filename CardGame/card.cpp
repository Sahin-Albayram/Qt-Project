#include "card.h"
#include <QPushButton>
#include <QPalette>

Card::Card(int row,int col,const QString& text, QWidget* parent): QPushButton(text,parent)
{
    this->inText = text;
    this->row = row;
    this->col = col;
    this->outText = "?";
    this->newlyOpened = false;
    this->repeat = false;
    this->IsOpen = false;
    this->setText(this->outText);
    QPalette pal = palette();

    if(color=="green"){
        pal.setColor(QPalette::Button, QColor(Qt::green));
    }else if (color=="red"){
        pal.setColor(QPalette::Button,QColor(Qt::red));
    }else{
        pal.setColor(QPalette::Button,QColor(Qt::gray));
    }
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
}

void Card::change_color(){

    QPalette pal = palette();

    if(this->color=="green"){
        pal.setColor(QPalette::Button, QColor(Qt::green));
    }else if (this->color=="red"){
        pal.setColor(QPalette::Button,QColor(Qt::red));
    }else{
        pal.setColor(QPalette::Button,QColor(Qt::gray));
    }
    setFlat(true);
    setFlat(true);
    setAutoFillBackground(true);
    setPalette(pal);
    update();
}

void Card::open(){
    if(this->IsOpen){
        this->repeat = true;
        return;
    }
    this->setText(this->inText);
    this->IsOpen = true;
    this->newlyOpened = true;
}
void Card::close(){
    this->color = "gray";
    this->change_color();
    this->setText(this->outText);
    this->IsOpen = false;
}
void Card::remove(){
    this->setVisible(false);
    this->setEnabled(false);
}
