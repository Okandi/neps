#include <bits/stdc++.h>

using namespace std;


int main() {
    int tamanhoBarra, qtdSequencias;
    cin >> tamanhoBarra >> qtdSequencias;

    int qtdOcorrenciasAcc[tamanhoBarra][10] = {};

    for (int nSequencia=0; nSequencia<tamanhoBarra; nSequencia++) { // O(10n)
        int numeroEscolhido;
        cin >> numeroEscolhido;
        for (int numero=0; numero<10; numero++) {
            if (nSequencia != 0) qtdOcorrenciasAcc[nSequencia][numero] = qtdOcorrenciasAcc[nSequencia-1][numero];
            if (numeroEscolhido == numero) qtdOcorrenciasAcc[nSequencia][numero]++;
        }
    }

    int resultados[10] = {};
    int ultimaPosicao = 0;

    for (int indexSequencia=0; indexSequencia<qtdSequencias; indexSequencia++) { // O(10n)
        int posicaoAtual;
        cin >> posicaoAtual;

        for (int numero=0; numero<10; numero++) {
            if (ultimaPosicao == 0) resultados[numero] += qtdOcorrenciasAcc[posicaoAtual-1][numero];
            else if (posicaoAtual > ultimaPosicao) resultados[numero] += qtdOcorrenciasAcc[posicaoAtual-1][numero] - qtdOcorrenciasAcc[ultimaPosicao-1][numero];
            else if (posicaoAtual < ultimaPosicao) {
                if (posicaoAtual == 1) resultados[numero] += qtdOcorrenciasAcc[ultimaPosicao-2][numero];
                else resultados[numero] += qtdOcorrenciasAcc[ultimaPosicao-2][numero] - qtdOcorrenciasAcc[posicaoAtual-2][numero];
            }
        }

        ultimaPosicao = posicaoAtual;
    }

    for (int i=0; i<10; i++) cout << resultados[i] << " ";
    cout << endl;
}
