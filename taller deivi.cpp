#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct RegistroTemperatura {
    string fecha;
    float temp_mañana;
    float temp_tarde;
    float temp_noche;
};


void ingresarRegistros(vector<RegistroTemperatura>& registros, int n) {
    for (int i = 0; i < n; ++i) {
        RegistroTemperatura registro;
        cout << "Ingrese la fecha (DD/MM/AAAA) para el día " << (i+1) << ": ";
        cin >> registro.fecha;
        cout << "Temperatura en la mañana: ";
        cin >> registro.temp_mañana;
        cout << "Temperatura en la tarde: ";
        cin >> registro.temp_tarde;
        cout << "Temperatura en la noche: ";
        cin >> registro.temp_noche;
        registros.push_back(registro);
    }
}


void mostrarRegistros(const vector<RegistroTemperatura>& registros) {
    cout << "Registros de temperatura:\n";
    for (const auto& registro : registros) {
        cout << "Fecha: " << registro.fecha << endl;
        cout << "Mañana: " << registro.temp_mañana << " grados Celsius\n";
        cout << "Tarde: " << registro.temp_tarde << " grados Celsius\n";
        cout << "Noche: " << registro.temp_noche << " grados Celsius\n";
        cout << "--------------------------------\n";
    }
}


float promedioTemperaturaDia(const RegistroTemperatura& registro) {
    return (registro.temp_mañana + registro.temp_tarde + registro.temp_noche) / 3.0;
}


float promedioTemperaturaTotal(const vector<RegistroTemperatura>& registros) {
    float suma = 0.0;
    for (const auto& registro : registros) {
        suma += promedioTemperaturaDia(registro);
    }
    return suma / registros.size();
}

int main() {
    int n;
    cout << "Ingrese el número de días para los cuales desea registrar la temperatura: ";
    cin >> n;

    vector<RegistroTemperatura> registros;
    ingresarRegistros(registros, n);

    mostrarRegistros(registros);

    cout << "El promedio de temperatura de todos los registros es: " << promedioTemperaturaTotal(registros) << " grados Celsius\n";

    return 0;
}