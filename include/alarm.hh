#ifndef ALARM_HH
#define ALARM_HH

#include <chrono>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <sstream>
#include <vector>
using namespace std;


class Alarm {
public:
    void set(int hours, int minutes, int seconds);
    void triggerAlarm();
    void stop();
    void snooze(int snoozeMinutes);

private:
    int alarmHours;
    int alarmMinutes;
    int alarmSeconds;
    bool isAlarmTriggered = false;
};

#endif // ALARM_HH
