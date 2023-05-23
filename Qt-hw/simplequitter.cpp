#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>



int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QMainWindow *mw = new QMainWindow;
    QWidget *cw = new QWidget;
    QHBoxLayout *hl = new QHBoxLayout(cw);
    QLabel *ql = new QLabel;
    QPushButton *pb = new QPushButton("Quit");


    ql->setText("This is my first project.");
    hl->addWidget(ql);
    hl->addWidget(pb);


    QObject::connect(pb,SIGNAL(clicked()),&app,SLOT(quit()));

    mw->setCentralWidget(cw);
    mw ->setWindowTitle("Hello World!");
    mw->show();
    return app.exec();
}
