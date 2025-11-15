#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 100;

void leerArchivo(int numeros[], int& cantidad) {
    ifstream archivo("datos.txt");
    cantidad = 0;
    while (archivo >> numeros[cantidad] && cantidad < MAX) {
        cantidad++;
    }
    archivo.close();
}

void clasificarNumeros(int numeros[], int cantidad, int pares[], int& cantPares, int impares[], int& cantImpares) {
    cantPares = 0;
    cantImpares = 0;
    
    for (int i = 0; i < cantidad; i++) {
        if (numeros[i] % 2 == 0) {
            pares[cantPares++] = numeros[i];
        } else {
            impares[cantImpares++] = numeros[i];
        }
    }
    ofstream p("pares.txt"), i("impares.txt");
    for (int j = 0; j < cantPares; j++) p << pares[j] << endl;
    for (int j = 0; j < cantImpares; j++) i << impares[j] << endl;
    p.close(); i.close();
}

void ordenarArchivo(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void mostrarArchivo(string nombre) {
    ifstream archivo(nombre);
    string linea;
    cout << "\n--- " << nombre << " ---\n";
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

int main() {
    int numeros[MAX], pares[MAX], impares[MAX];
    int cantNumeros, cantPares, cantImpares;
    bool clasificado = false, ordenado = false;
    int opcion;
    //menu con opciones
    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Clasificar numeros" << endl;
        cout << "2. Ordenar archivos" << endl;
        cout << "3. Ver resultados" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                leerArchivo(numeros, cantNumeros);
                clasificarNumeros(numeros, cantNumeros, pares, cantPares, impares, cantImpares);
                clasificado = true;
                ordenado = false;
                cout << "Clasificados: " << cantPares << " pares y " << cantImpares << " impares" << endl;
                break;
                
            case 2:
                if (!clasificado) {
                    cout << "Primero clasifica los numeros (Opcion 1)" << endl;
                } else {
                    ordenarArchivo(pares, cantPares);
                    ordenarArchivo(impares, cantImpares);
                    
                    ofstream p("pares.txt"), i("impares.txt");
                    for (int j = 0; j < cantPares; j++) p << pares[j] << endl;
                    for (int j = 0; j < cantImpares; j++) i << impares[j] << endl;
                    p.close(); i.close();
                    
                    ordenado = true;
                    cout << "Archivos ordenados!" << endl;
                }
                break;
                
            case 3:
                if (!clasificado) {
                    cout << "Primero clasifica los numeros (Opcion 1)" << endl;
                } else if (!ordenado) {
                    cout << "\nANTES DE ORDENAR:" << endl;
                    mostrarArchivo("pares.txt");
                    mostrarArchivo("impares.txt");
                } else {
                    cout << "\nDESPUES DE ORDENAR:" << endl;
                    mostrarArchivo("pares.txt");
                    mostrarArchivo("impares.txt");
                }
                break;
                
            case 4:
                cout << "Adios!" << endl;
                break;
                
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 4);
    
    return 0;
}
