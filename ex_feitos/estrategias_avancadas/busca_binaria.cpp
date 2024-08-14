#include <bits/stdc++.h>

using namespace std;


int main() {
    double numero;
    cin >> numero;

    double raiz = numero/2.;
    double limiteInf = 0.;
    double limiteSup = numero;
    int i=0;
    for (; i<pow(10, 8); i++) {
        if (raiz*raiz == numero) break;
        else if (raiz*raiz < numero) limiteInf = raiz;
        else if (raiz*raiz > numero) limiteSup = raiz;
        raiz = (limiteSup+limiteInf)/2;
    }

    cout << "quantidade iteracoes: " << i << endl;
    cout << "raiz: " << raiz << endl;
}
