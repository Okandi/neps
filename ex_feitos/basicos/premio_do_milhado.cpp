#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdDias;
    cin >> qtdDias;

    int acessos[qtdDias];
    for (int i=0; i<qtdDias; i++) cin >> acessos[i];

    int acessosAcumulados = 0;
    for (int i=0; i<qtdDias; i++) {
        acessosAcumulados += acessos[i];
        if (acessosAcumulados >= 1000000) {
            cout << i+1 << endl;
            break;
        }
    }
}
