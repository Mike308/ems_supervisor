#include "main_timer.h"

main_timer::main_timer()
{

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(main_timer_slot()));
}

void main_timer::start(int interval){


    timer->start(interval);

}

void main_timer::stop(){

    timer->stop();


}


