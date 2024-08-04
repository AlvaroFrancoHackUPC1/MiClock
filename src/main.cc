#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "../include/alarm.hh"

using namespace std;

bool encendido = true;

bool shouldTriggerAlarm(int hh, int min, int seg) {
    auto now = chrono::system_clock::now();
    time_t now_time = chrono::system_clock::to_time_t(now);
    tm* local_time = localtime(&now_time);

    return (local_time->tm_hour == hh &&
            local_time->tm_min == min &&
            local_time->tm_sec == seg);
}

void startAlarmChecker() {
    while (encendido) {
        fstream file("/home/zombie/Desktop/MiClock/data/alarm_time.txt");
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                int hh, min, seg;

                // Crear un std::istringstream para leer la cadena
                istringstream iss(line);
                
                // Leer los valores separados por ":"
                char colon; // Variable para capturar el delimitador ":"
                iss >> hh >> colon >> min >> colon >> seg;
                if(shouldTriggerAlarm(hh, min, seg)) {
                    cout << "La alarma de las " << hh << colon << min << colon << seg << " esta activa" << endl;
                }
            }
            file.close();
            this_thread::sleep_for(chrono::seconds(1)); // Use the fully qualified name for this_thread and chrono
        }
    }
}



void Establecer() {
    // Configuración de la alarma
    cout << "¿En cuándo sonará la alarma? (hh mm ss)" << endl;
    int hh, min, seg; 
    cin >> hh >> min >> seg;

    Alarm myAlarm;
    myAlarm.setAlarm(hh, min, seg);
}

int main() {
    cout << "MiClock Project" << endl;
    
    // Start the alarm checker in a separate thread
    thread alarmCheckerThread(startAlarmChecker);
    
    int opt = -1; 
    while (opt != 5) {
        cout << "1. Establecer alarma" << endl;
        cout << "2. Ver alarmas activas" << endl;
        cout << "3. Modificar alarma" << endl;
        cout << "4. Apagar alarma" << endl;
        cout << "5. Salir" << endl;

        cin >> opt;
        if (opt == 1) {
            Establecer();
        }
        if (opt == 2) {
            // Implementar funcionalidad para ver alarmas activas
        }
        if (opt == 3) {
            // Implementar funcionalidad para modificar alarma
        }
        if (opt == 4) {
            // Implementar funcionalidad para apagar alarma
        }
    }
    encendido = false;

    // Join the thread when the main program exits (if desired)
    alarmCheckerThread.join(); // Comment this out to avoid blocking the main thread

    return 0;
}
