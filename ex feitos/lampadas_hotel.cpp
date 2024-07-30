#include <bits/stdc++.h>

using namespace std;


int main() {
    int estadoInicialA, estadoInicialB, estadoDesejadoA, estadoDesejadoB;
    cin >> estadoInicialA >> estadoInicialB >> estadoDesejadoA >> estadoDesejadoB;

    int quantidadeMinima = 0;
    if (estadoDesejadoA != estadoDesejadoB) {
        if (estadoInicialA != estadoInicialB) {
            if (estadoInicialA != estadoDesejadoA) {
                quantidadeMinima = 1;
            } else {
                quantidadeMinima = 0;
            }
        } else {
            if (estadoInicialA != estadoDesejadoA) {
                quantidadeMinima = 1;
            } else {
                quantidadeMinima = 2;
            }
        }
    } else {
        if (estadoInicialA != estadoInicialB) {
            if (estadoInicialA != estadoDesejadoA) {
                quantidadeMinima = 1;
            } else {
                quantidadeMinima = 2;
            }
        } else {
            if (estadoInicialA != estadoDesejadoA) {
                quantidadeMinima = 1;
            } else {
                quantidadeMinima = 0;
            }
        }
    }
    cout << quantidadeMinima << endl;
}
