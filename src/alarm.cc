#include "alarm.hh"
#include <iostream>

using namespace std;

void Alarm::setAlarm(int hours, int minutes, int seconds) {
    alarmHours = hours;
    alarmMinutes = minutes;
    alarmSeconds = seconds;
    isAlarmTriggered = false;
    cout << "Alarm set for " << hours << ":" << minutes << ":" << seconds << endl;
}

void Alarm::checkAlarm() {
    // Implementar lógica para comprobar la alarma
    cout << "Checking alarm..." << endl;
}

void Alarm::triggerAlarm() {
    isAlarmTriggered = true;
    cout << "Alarm triggered!" << endl;
}

void Alarm::stopAlarm() {
    isAlarmTriggered = false;
    cout << "Alarm stopped!" << endl;
}

void Alarm::snoozeAlarm(int snoozeMinutes) {
    // Implementar lógica para posponer la alarma
    cout << "Alarm snoozed for " << snoozeMinutes << " minutes." << endl;
}
