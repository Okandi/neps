#include <iostream>

using namespace std;


int main() {
    int qtdPedacos, tamanhoDesejado;
    cin >> qtdPedacos >> tamanhoDesejado;

    int sanduiche[qtdPedacos];
    for (int i=0; i<qtdPedacos; i++) cin >> sanduiche[i];

    int qtdDeAlternativas = 0;
    for (int i=0; i<qtdPedacos; i++) {
        int tamanhoTotal = 0;
        for (int j=0; j<qtdPedacos; j++) {
            int pedaco = i+j;
            if (pedaco >= qtdPedacos) pedaco -= qtdPedacos;
            tamanhoTotal += sanduiche[pedaco];
            if (tamanhoTotal == tamanhoDesejado) {
                qtdDeAlternativas++;
                break;
            } else if (tamanhoTotal > tamanhoDesejado) break;
        }
    }

    cout << qtdDeAlternativas << endl;
}
