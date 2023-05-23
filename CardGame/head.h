#ifndef HEAD_H
#define HEAD_H
#include <QLabel>

class Head : public QObject
{
    Q_OBJECT

public:

    Head();
    QLabel *label;
    int remainingTry;
    int score;
public slots:
    void update();

};


#endif // HEAD_H
