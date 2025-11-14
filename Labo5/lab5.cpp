#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << " Ingresa un numero entero: ";
    cin >> n;

    cout << " numero multiplicado: ";
    for (int i = 1; i <= 10; i++)
    {
        cout << n << "*" << i << "=" << n * i << endl;
    }

    return 0;
}