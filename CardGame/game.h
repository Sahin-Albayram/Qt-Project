#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QTextStream>
#include <QCoreApplication>
#include <QMessageBox>
#include <QProcess>
#include "card.h"
#include "mygrid.h"

class Game : QWidget
{
    Q_OBJECT
public:
    Game();
    MyGrid *grid;
    QWidget *cw;
    QHBoxLayout *hb;
    QVBoxLayout *vb;
    QLabel *triesString;
    QLabel *scoreString;
    QLabel *scoreNumber;
    QLabel *triesNumber;


public slots:
    void newGrid();
    QWidget *newGame();
    void closeCw();
    void update();
};

#endif // GAME_H
