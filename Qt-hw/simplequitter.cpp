#include <QApplication>
#include <QVBoxLayout>
#include <QSpacerItem>
#include "colorbutton.h"
#include "mytimer.h"
#include "mygrid.h"



int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QWidget *cw = new QWidget;
    QVBoxLayout *vb = new QVBoxLayout(cw);
    MyTimer mt;
    MyGrid *gl = new MyGrid(mt.timer);

    for(int row = 0; row<4;row++){
        for(int col=0; col<3;col++){
            int color_code = rand()%3;
            QString color;
            if(color_code==0){
                color= "red";
            }else if(color_code ==1){
                color = "blue";
            }else{
                color = "green";

            }
            ColorButton *randButton = new ColorButton(color,"X");
            QObject::connect(randButton, SIGNAL(clicked()),randButton,SLOT(change_color()));
            QObject::connect(randButton, SIGNAL(clicked()),gl,SLOT(check_colors()));
            gl->addWidget(randButton,row,col,1,1);
        }
    }
    vb->addWidget(mt.label);
    vb->addLayout(gl);
    QSpacerItem *si = new QSpacerItem(0,10,QSizePolicy::Expanding,QSizePolicy::Expanding);
    vb->addSpacerItem(si);
    cw->setWindowTitle("Color Game");
    cw->resize(640,480);
    cw->show();

    return app.exec();


}
