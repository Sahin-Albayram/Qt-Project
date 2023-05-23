#include "game.h"

Game::Game()
{



}
void Game::newGrid(){
   this->grid = new MyGrid(50,0);
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
               this->grid->addWidget(sampleCard,row,col,1,1);
               QLayoutItem *A = this->grid->itemAtPosition(row,col);
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
                                this->grid,SLOT(check_cards()));
               QObject::connect(sampleCard,SIGNAL(clicked()),
                                this,SLOT(update()));

           }
       }

   }
}
QWidget *Game::newGame(){
   this->newGrid();
   this->cw = new QWidget;
   this->hb = new QHBoxLayout;
   this->vb = new QVBoxLayout(cw);


 //  this->triesNumber = new QLabel(this->grid->tryShow);
 //  this->scoreNumber = new QLabel(this->grid->scoreShow);
   this->triesNumber = this->grid->tryShow;
   QLabel *triesString = new QLabel;
   QLabel *scoreString = new QLabel;
   triesString->setText("Remaining Tries :");
   scoreString->setText("Score :");


   this->hb->addWidget(triesString);
   this->hb->addWidget(this->triesNumber);
   this->hb->addWidget(scoreString);
   this->hb->addWidget(this->grid->scoreShow);

   QPushButton* restartButton = new QPushButton("New Game");


   this->hb->addWidget(restartButton);
   QObject::connect(restartButton, SIGNAL(clicked()),
                    this, SLOT(closeCw()));
   QObject::connect(restartButton, SIGNAL(clicked()),
                    this, SLOT(newGame()));
   this->vb->addLayout(hb);
   this->vb->addLayout(grid);
   QSpacerItem *si = new QSpacerItem(0,10,QSizePolicy::Expanding,QSizePolicy::Expanding);
   this->vb->addSpacerItem(si);
   this->cw->setWindowTitle("Card Game");
   this->cw->resize(640,480);
   this->cw->show();
   return this->cw;


}
void Game::closeCw(){
   this->cw->close();
}
void Game::update(){
   if(this->grid->remainingTry == 0){
       QMessageBox msgBox;
       msgBox.setText("YOU LOST!");
       msgBox.exec();
       msgBox.setStandardButtons(QMessageBox::Cancel);
       QCoreApplication::exit();
   }


}
