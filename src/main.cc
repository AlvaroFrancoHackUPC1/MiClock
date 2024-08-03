#include <iostream>
#include "alarm.hh"

using namespace std;

int main() {
    cout << "MiClock Project" << endl;

    Alarm myAlarm;
    myAlarm.setAlarm(7, 30, 0);
    myAlarm.checkAlarm();

    return 0;
}
