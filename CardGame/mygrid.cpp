#include "mygrid.h"



MyGrid::MyGrid(int totalTry,int score) : QGridLayout()
{
    this->remainingCard = 30;
    this->remainingTry = totalTry;
    this->tryShow = new QLabel(QString::number(remainingTry));
    this->score = score;
    this->scoreShow = new QLabel(QString::number(this->score));
    this->dual = false;
    Card *empty_card = new Card(-1,-1,"QQQ");
    this->card1 = empty_card;
    this->card2 = empty_card;
    this->card3 = empty_card;
}

void MyGrid::add_score(){
    this->score +=1;
    this->scoreShow->setText(QString::number(this->score));
}

void MyGrid::check_cards(){
    Card *empty_card = new Card(-1,-1,"QQQ");
    int n_row=-1;
    Card *card;
    for(int row=0;row<5;row++){
        if(n_row!=-1) break;
        for(int col=0;col<6;col++){
            card = qobject_cast<Card*>(this->itemAtPosition(row,col)->widget());
            if(card->repeat){
                card->repeat = false;
                return;
            }
            if(card->newlyOpened){
                n_row = row;

                card->newlyOpened=false;
                break;
            }
        }
    }


    if(this->card1->row != -1 && this->card1->col != -1){ // card1 is already
        if(this->card2->row != -1 && this->card2->col != -1){
            this->card3 = card;
            if(this->dual){
                this->card1->remove();
                this->card2->remove();
                this->card1 = empty_card;
                this->card2 = empty_card;

                this->card1 = this->card3;

                this->card3 = empty_card;

                this->dual=false;

                this->remainingCard -=2;
                return;

            }else{   // close cards put card3 to card1

                this->card1->close();
                this->card2->close();

                this->card2 = empty_card;

                this->card1 = this->card3;

                this->card3 = empty_card;
            }

        }else{
            this->card2 = card;
            this->remainingTry--;
            this->tryShow->setText(QString::number(remainingTry));
            if(this->check_dual(this->card1,this->card2)){
                if(this->remainingCard==2){
                    QString greenC = "green";
                    this->card1->color= greenC;
                    this->card2->color= greenC;
                    this->card1->change_color();
                    this->card2->change_color();
                    this->victory();
                    this->card1->close();
                    this->card2->close();
                }
                this->dual = true;
                QString greenC = "green";
                this->card1->color= greenC;
                this->card2->color= greenC;
                this->card1->change_color();
                this->card2->change_color();
                this->add_score();
            }else{
                this->dual = false;
                QString redC = "red";
                this->card1->color= redC;
                this->card2->color= redC;
                this->card1->change_color();
                this->card2->change_color();
            }
        }
    }else{
        this->card1 = card;
    }
}

bool MyGrid::check_dual(Card *cardCheck1,Card *cardCheck2){
    if(cardCheck1->inText==cardCheck2->inText){
        return true;
    }
    return false;
}
void MyGrid::victory(){
    QMessageBox msgBox;
    msgBox.setText("YOU WON!");
    msgBox.exec();
    msgBox.setStandardButtons(QMessageBox::Cancel);

}



