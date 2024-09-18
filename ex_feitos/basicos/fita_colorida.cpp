#include <bits/stdc++.h>

using namespace std;


int decideCor(vector<int> &quadradosPintadosInicial, int indexQuadrado) {
    int menorDist = -1;
    for (int index : quadradosPintadosInicial) {
        int distAtual = abs(index-indexQuadrado);
        if (menorDist < 0) menorDist = distAtual;
        else if (distAtual > menorDist) break;
        else menorDist = distAtual;
    }
    if (menorDist > 9) return 9;
    return menorDist;
}


int main() {
    vector<int> quadradosPintadosInicial;
    int tamanho;

    cin >> tamanho;
    for (int i=0; i<tamanho; i++) {
        int cor;
        cin >> cor;
        if (cor == 0) quadradosPintadosInicial.push_back(i);
    }

    for (int i=0; i<tamanho; i++) {
        cout << decideCor(quadradosPintadosInicial, i) << " ";
    }

    cout << endl;
}
