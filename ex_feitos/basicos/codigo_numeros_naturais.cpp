#include <bits/stdc++.h>

using namespace std;


int main() {
    int tamanho;
    cin >> tamanho;

    string sequencia;
    for (int i=0; i<tamanho; i++) {
        char digito;
        cin >> digito;
        sequencia.push_back(digito);
    }

    int qtd = 0;

    while (sequencia.find("100") != sequencia.npos) {
        sequencia = sequencia.substr(sequencia.find("100")+3);
        qtd++;
    }

    cout << qtd << endl;
}
