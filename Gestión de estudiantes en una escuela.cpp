#include <iostream>
#include <string>
using namespace std;

struct Dir { string calle; int num; string ciudad; };
struct Est { string nom; int edad; float cal[5]; Dir dir; };

void ingresar(Est* &e, int &n) {
    int c; cout << "Cuantos? "; cin >> c; cin.ignore();
    Est* nuevo = new Est[n + c];
    for (int i = 0; i < n; i++) nuevo[i] = e[i];
    for (int i = n; i < n + c; i++) {
        cout << "Nom: "; getline(cin, nuevo[i].nom);
        cout << "Edad: "; cin >> nuevo[i].edad; cin.ignore();
        cout << "Calle: "; getline(cin, nuevo[i].dir.calle);
        cout << "Num: "; cin >> nuevo[i].dir.num; cin.ignore();
        cout << "Ciudad: "; getline(cin, nuevo[i].dir.ciudad);
        cout << "5 cal: "; for (int j = 0; j < 5; j++) cin >> nuevo[i].cal[j]; cin.ignore();
    }
    delete[] e; e = nuevo; n += c; cout << "Hecho!\n";
}

void mostrar(Est* e, int n) {
    if (!n) { cout << "No hay\n"; return; }
    for (int i = 0; i < n; i++) 
    {
        cout << e[i].nom << " (" << e[i].edad << ")\n" 
             << e[i].dir.calle << " #" << e[i].dir.num << ", " << e[i].dir.ciudad << "\nCal: ";
        for (int j = 0; j < 5; j++) cout << e[i].cal[j] << " "; cout << endl;
    }
}

void buscar(Est* e, int n) {
    if (!n) { cout << "No hay\n"; return; }
    string nom; cout << "Buscar: "; getline(cin, nom);
    for (int i = 0; i < n; i++) {
        if (e[i].nom == nom) {
            cout << e[i].nom << " - " << e[i].edad << " años\n";
            for (int j = 0; j < 5; j++) cout << e[i].cal[j] << " "; return;
        }
    }
    cout << "No existe\n";
}

void modificar(Est* e, int n) {
    if (!n) { cout << "No hay\n"; return; }
    string nom; cout << "Modificar: "; getline(cin, nom);
    for (int i = 0; i < n; i++) {
        if (e[i].nom == nom) {
            cout << "Nuevo nom: "; getline(cin, e[i].nom);
            cout << "Nueva edad: "; cin >> e[i].edad; cin.ignore();
            cout << "Nueva calle: "; getline(cin, e[i].dir.calle);
            cout << "Nuevo num: "; cin >> e[i].dir.num; cin.ignore();
            cout << "Nueva ciudad: "; getline(cin, e[i].dir.ciudad);
            cout << "Nuevas 5 cal: "; for (int j = 0; j < 5; j++) cin >> e[i].cal[j]; cin.ignore();
            cout << "Modificado!\n"; return;
        }
    }
    cout << "No existe\n";
}

int main() {
    Est* e = nullptr; int n = 0, op;
    do {
        cout << "1.Ingresar 2.Mostrar 3.Buscar 4.Modificar 5.Salir: "; cin >> op; cin.ignore();
        if(op == 1) ingresar(e, n);
        else if(op == 2) mostrar(e, n);
        else if(op == 3) buscar(e, n);
        else if(op == 4) modificar(e, n);
        else if(op == 5) cout << "Adios!\n";
    } while(op != 5);
    delete[] e; return 0;
}


  