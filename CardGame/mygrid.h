#ifndef MYGRID_H
#define MYGRID_H
#include "card.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QLabel>

class MyGrid : public QGridLayout
{
    Q_OBJECT
public:
    MyGrid(int totalTry,int score);
    int remainingCard;
    int remainingTry;

    QLabel *tryShow;
    QLabel *scoreShow;
    int score;
    bool dual;
    int openCounter;
    Card* card1;
    Card* card2;
    Card* card3;
    bool check_dual(Card* card1,Card* card2);
    void victory();
public slots:

    void add_score();
    void check_cards();
};



#endif // MYGRID_H
