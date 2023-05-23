#include "head.h"

Head::Head()
{
    remainingTry = 50;
    score = 0;
    label = new QLabel("Remaining tries : " + QString::number(remainingTry) + " Score : " + QString::number(score));
}

void Head::update(){
    this->label->setText("Remaining tries : " + QString::number(this->remainingTry) + " Score : " + QString::number(this->score));
}
