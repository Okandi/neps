#include <bits/stdc++.h>

using namespace std;


int main() {
    long long tamanho;
    cin >> tamanho;
    vector<long long> numeros;

    for (long long i=0; i<tamanho; i++) {
        long long numero;
        cin >> numero;
        if (i >= tamanho-3 || i < 2) numeros.push_back(numero);
    }

    long long resultado;
    if (numeros[0] < 0 && numeros[1] < 0 && numeros[0] * numeros[1] > numeros[numeros.size()-3] * numeros[numeros.size()-2]) {
        resultado = numeros[numeros.size()-1] * numeros[0] * numeros[1];
    } else {
        resultado = numeros[numeros.size()-1] * numeros[numeros.size()-2] * numeros[numeros.size()-3];
    }

    cout << resultado << endl;
}
