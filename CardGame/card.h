#ifndef CARD_H
#define CARD_H

#include <QPushButton>
#include <QPalette>

class Card : public QPushButton
{
    Q_OBJECT
public:
    Card(int row,int col,const QString& text,
         QWidget* parent=0);
    bool IsOpen;
    bool repeat;
    bool newlyOpened;
    int row;
    int col;
    QString color;
    QString inText;
    QString outText;
public slots:
    void change_color();
    void open();
    void close();
    void remove();
};

#endif // CARD_H
