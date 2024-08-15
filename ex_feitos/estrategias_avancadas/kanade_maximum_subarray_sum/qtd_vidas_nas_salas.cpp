#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdSalas;
    cin >> qtdSalas;

    int vidas[qtdSalas] = {};
    for (int i=0; i<qtdSalas; i++) cin >> vidas[i];

    long long maiorSomaPorPeriodo[qtdSalas] = {};
    maiorSomaPorPeriodo[0] = vidas[0];

    for (int i=1; i<qtdSalas; i++) { // O(n)
        if (maiorSomaPorPeriodo[i-1]+vidas[i] > vidas[i]) {
            maiorSomaPorPeriodo[i] = maiorSomaPorPeriodo[i-1]+vidas[i];
        } else maiorSomaPorPeriodo[i] = vidas[i];
    }

    long long resultado = -9999999999;
    for (long long somaDoPeriodo : maiorSomaPorPeriodo) {
        resultado = max(resultado, somaDoPeriodo);
    }

    cout << resultado << endl;
}
