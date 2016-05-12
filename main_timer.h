#ifndef MAIN_TIMER_H
#define MAIN_TIMER_H

#include <QObject>
#include <QTimer>

class main_timer : QObject
{
    Q_OBJECT
public:
    main_timer();
    void start(int interval);
    void stop();

private:
    QTimer *timer;

public slots:

    void main_timer_slot();


};

#endif // MAIN_TIMER_H
