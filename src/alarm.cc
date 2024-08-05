#include "../include/alarm.hh"


void Alarm::set(int hours, int minutes, int seconds) {
    alarmHours = hours;
    alarmMinutes = minutes;
    alarmSeconds = seconds;
    isAlarmTriggered = false;

    // Save the alarm time to a text file
    ofstream file("/home/zombie/Desktop/MiClock/data/alarm_time.txt", std::ios::app);
    if (file.is_open()) {
        file << hours << ":" << minutes << ":" << seconds << endl;
        file.close();
        cout << "Alarm time saved!" << endl;
    } else {
        cout << "Failed to save alarm time!" << endl;
    }
}


void Alarm::triggerAlarm() {
    isAlarmTriggered = true;
    cout << "Alarm triggered!" << endl;
}

void Alarm::stop() {
    isAlarmTriggered = false;
    cout << "Alarm stopped!" << endl;
}

void Alarm::snooze(int snoozeMinutes) {
    // Implementar lógica para posponer la alarma
    cout << "Alarm snoozed for " << snoozeMinutes << " minutes." << endl;
}