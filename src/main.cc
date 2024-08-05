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
    ifstream file("/home/zombie/Desktop/MiClock/data/alarm_time.txt");
    if (file.is_open()) {
        while (encendido) {
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
            this_thread::sleep_for(chrono::seconds(1)); // Use the fully qualified name for this_thread and chrono
        }
    file.close();
    }
}


void establecer() {
    // Configuración de la alarma
    cout << "¿En cuándo sonará la alarma? (hh mm ss)" << endl;
    int hh, min, seg; 
    cin >> hh >> min >> seg;

    Alarm myAlarm;
    myAlarm.set(hh, min, seg);
}

void verAlarmas() {
    ifstream file("/home/zombie/Desktop/MiClock/data/alarm_time.txt");
    if (file.is_open()) {
        string line;
        int i = 1;
        while (getline(file, line)) {
            cout << i << ". " << line << endl;
            ++i;
        }
    file.close();
    }
    cout << endl;
}

bool buscarAlarma(int hh_des, int min_des, int seg_des) {
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
            if (hh == hh_des and min == min_des and seg == seg_des) {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void modificarAlarma(int nline) {
    // Abrir el archivo en modo lectura/escritura
    fstream file("/home/zombie/Desktop/MiClock/data/alarm_time.txt");
    if (file.is_open()) {
        string line;
        vector<string> lines;

        // Leer todas las líneas del archivo y almacenarlas en un vector
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();

        // Verificar si el número de línea es válido
        if (nline >= 1 && nline <= lines.size()) {
            cout << "Introduce los nuevos valores de la alarma (hh min seg)" << endl;
            int hh, min, seg;
            cin >> hh >> min >> seg;

            // Modificar la línea especificada con los nuevos valores de la alarma
            lines[nline - 1] = to_string(hh) + ":" + to_string(min) + ":" + to_string(seg);
            cout << "Alarma modificada correctamente" << endl;

            // Abrir el archivo en modo escritura para guardar los cambios
            ofstream outfile("/home/zombie/Desktop/MiClock/data/alarm_time.txt");
            if (outfile.is_open()) {
                // Escribir todas las líneas de nuevo en el archivo
                for (const string& l : lines) {
                    outfile << l << endl;
                }
                outfile.close();
            } else {
                cerr << "Error al abrir el archivo para escribir." << endl;
            }
        } else {
            cerr << "Número de línea inválido." << endl;
        }
    } else {
        cerr << "Error al abrir el archivo para leer." << endl;
    }
    cout << endl;
}

void eliminarAlarma(int nline) {
    // Abrir el archivo en modo lectura/escritura
    fstream file("/home/zombie/Desktop/MiClock/data/alarm_time.txt");
    if (file.is_open()) {
        string line;
        vector<string> lines;

        // Leer todas las líneas del archivo y almacenarlas en un vector
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();

        // Verificar si el número de línea es válido
        if (nline >= 1 && nline <= lines.size()) {
            // Eliminar la línea especificada
            lines.erase(lines.begin() + nline - 1);
            cout << "Alarma eliminada correctamente" << endl;

            // Abrir el archivo en modo escritura para guardar los cambios
            ofstream outfile("/home/zombie/Desktop/MiClock/data/alarm_time.txt");
            if (outfile.is_open()) {
                // Escribir todas las líneas de nuevo en el archivo
                for (const string& l : lines) {
                    outfile << l << endl;
                }
                outfile.close();
            } else {
                cerr << "Error al abrir el archivo para escribir." << endl;
            }
        } else {
            cerr << "Número de línea inválido." << endl;
        }
    } else {
        cerr << "Error al abrir el archivo para leer." << endl;
    }
    cout << endl;
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
        cout << "4. Eliminar alarma" << endl;
        cout << "5. Salir" << endl;

        cin >> opt;
        if (opt == 1) {
            establecer();
        }
        if (opt == 2) {
            verAlarmas();
        }
        if (opt == 3) {
            verAlarmas();
            cout << "Elige que alarma quieres modificar: ";
            int alarmasel; cin >> alarmasel;
            modificarAlarma(alarmasel);
        }
        if (opt == 4) {
            verAlarmas();
            cout << "Elige que alarma quieres eliminar: ";
            int alarmasel; cin >> alarmasel;
            eliminarAlarma(alarmasel);
        }
    }
    encendido = false;

    // Join the thread when the main program exits (if desired)
    alarmCheckerThread.join(); // Comment this out to avoid blocking the main thread

    return 0;
}
