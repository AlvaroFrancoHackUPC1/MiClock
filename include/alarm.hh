#ifndef ALARM_HH
#define ALARM_HH

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

#endif // ALARM_HH
