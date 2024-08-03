#ifndef ALARM_H
#define ALARM_H

class Alarm {
public:
    void setAlarm(int hours, int minutes, int seconds);
    void checkAlarm();
    void triggerAlarm();
    void stopAlarm();
    void snoozeAlarm(int snoozeMinutes);
private:
    int alarmHours;
    int alarmMinutes;
    int alarmSeconds;
    bool isAlarmTriggered = false;
};

#endif // ALARM_H
