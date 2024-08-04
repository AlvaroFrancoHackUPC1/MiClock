#include "../include/alarm.hh"


void Alarm::setAlarm(int hours, int minutes, int seconds) {
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

void Alarm::stopAlarm() {
    isAlarmTriggered = false;
    cout << "Alarm stopped!" << endl;
}

void Alarm::snoozeAlarm(int snoozeMinutes) {
    // Implementar lógica para posponer la alarma
    cout << "Alarm snoozed for " << snoozeMinutes << " minutes." << endl;
}
/*
//! Hay que corregir esto
void Alarm::checkAlarm() {
    cout << "Checking alarm..." << endl;

    fstream file("/home/zombie/Desktop/MiClock/data/alarm_time.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
}
*/
//! Hay que solucionarlo
void Alarm::checkAlarm() {
    if (shouldTriggerAlarm()) {
        triggerAlarm();
    }
}
bool Alarm::shouldTriggerAlarm() {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm* local_time = localtime(&now_time);

    return (local_time->tm_hour == alarmHours &&
            local_time->tm_min == alarmMinutes &&
            local_time->tm_sec == alarmSeconds);
}
