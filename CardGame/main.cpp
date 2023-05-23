#include <QApplication>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QTextStream>
#include <QCoreApplication>
#include <QProcess>
#include "card.h"
#include "mygrid.h"
#include "game.h"


MyGrid *getGrid(){
    MyGrid *grid = new MyGrid(50,0);
    QString X = "X";
    QString texts[30] = {"A","A","B","B","C","C","D","D","E","E","F","F","G","G","H","H","I","I","J","J","K","K","L","L","M","M","N","N","O","O"};
    for(int row=0; row<5;row++){
        for(int col=0;col<6;col++){

            int r = arc4random()%30;
            while(texts[r]==X){
                r = arc4random()%30;
            }
            while(texts[r]!=X){
                Card *sampleCard = new Card(row,col,texts[r]);
                grid->addWidget(sampleCard,row,col,1,1);
                QLayoutItem *A = grid->itemAtPosition(row,col);
                if(A){
                    Card* c = qobject_cast<Card*>(A->widget());

                    if(c){
                        QTextStream(stdout) << c->inText << Qt::endl;
                    }

                }
                texts[r] = X;
                QObject::connect(sampleCard,SIGNAL(clicked()),
                                 sampleCard,SLOT(open()));
                QObject::connect(sampleCard,SIGNAL(clicked()),
                                 grid,SLOT(check_cards()));

            }
        }

    }
    return grid;
}

int main(int argc, char *argv[]){
//    QApplication app(argc,argv);
//    QWidget *cw = new QWidget;
//    QHBoxLayout *hb = new QHBoxLayout;
//    QVBoxLayout *vb = new QVBoxLayout(cw);
//    MyGrid *grid = new MyGrid(50,0);
//    QString X = "X";
//    QString texts[30] = {"A","A","B","B","C","C","D","D","E","E","F","F","G","G","H","H","I","I","J","J","K","K","L","L","M","M","N","N","O","O"};
//    for(int row=0; row<5;row++){
//        for(int col=0;col<6;col++){
//
//            int r = arc4random()%30;
//            while(texts[r]==X){
//                r = arc4random()%30;
//            }
//            while(texts[r]!=X){
//                Card *sampleCard = new Card(row,col,texts[r]);
//                grid->addWidget(sampleCard,row,col,1,1);
//                QLayoutItem *A = grid->itemAtPosition(row,col);
//                if(A){
//                    Card* c = qobject_cast<Card*>(A->widget());
//
//                    if(c){
//                        QTextStream(stdout) << c->inText << Qt::endl;
//                    }
//
//                }
//                texts[r] = X;
//              QObject::connect(sampleCard,SIGNAL(clicked()),
//                                 sampleCard,SLOT(open()));
//                QObject::connect(sampleCard,SIGNAL(clicked()),
//                                 grid,SLOT(check_cards()));
//
//            }
//        }
//
//    }
//
//    QLabel *triesString = new QLabel;
//    triesString->setText("Remaining Tries :");
//    QLabel *scoreString = new QLabel;
//    scoreString->setText("Score :");
//    QLabel *triesNumber = new QLabel(grid->tryShow);
//    QLabel *scoreNumber = new QLabel(grid->scoreShow);
//    hb->addWidget(triesString);
//    hb->addWidget(triesNumber);
//    hb->addWidget(scoreString);
//    hb->addWidget(scoreNumber);
//    QPushButton* restartButton = new QPushButton("New Game");
//    hb->addWidget(restartButton);
//
//    QObject::connect(restartButton, &QPushButton::clicked,
//                     [restartButton]() {
//                                        });
//
//
//    vb->addLayout(hb);
//    vb->addLayout(grid);
//    QSpacerItem *si = new QSpacerItem(0,10,QSizePolicy::Expanding,QSizePolicy::Expanding);
//    vb->addSpacerItem(si);
//    cw->setWindowTitle("Card Game");
//    cw->resize(640,480);
//    cw->show();
    QApplication app(argc,argv);
    Game *g = new Game();
    g->newGame();
    return app.exec();

}

