#ifndef ALARM_HH
#define ALARM_HH

#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <sstream>
using namespace std;


class Alarm {
public:
    void setAlarm(int hours, int minutes, int seconds);
    void checkAlarm();
    void triggerAlarm();
    void stopAlarm();
    void snoozeAlarm(int snoozeMinutes);
    bool shouldTriggerAlarm();

private:
    int alarmHours;
    int alarmMinutes;
    int alarmSeconds;
    bool isAlarmTriggered = false;
};

#endif // ALARM_HH
