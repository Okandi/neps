#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdCartelas, qtdNumerosNaCartela, qtdNumerosSorteados;
    cin >> qtdCartelas >> qtdNumerosNaCartela >> qtdNumerosSorteados;

    vector<int> cartelas[qtdCartelas]; // O(n²)
    for (int i=0; i<qtdCartelas; i++) {
        cartelas[i] = {};
        for (int j=0; j<qtdNumerosNaCartela; j++) {
            int numero;
            cin >> numero;
            cartelas[i].push_back(numero);
        }
    }

    map<const int, int> numerosSorteados;
    for (int i=0; i<qtdNumerosSorteados; i++) { // O(n*log(n))
        int numeroSorteado;
        cin >> numeroSorteado;
        numerosSorteados[numeroSorteado] = i;
    }

    vector<int> qtdNumeroParaGanhar; // O(n²*log(n))
    for (int i=0; i<qtdCartelas; i++) {
        int maiorIndexNaCartela = 0;
        for (int j=0; j<qtdNumerosNaCartela; j++) { // obs: qtdNumerosSorteados > qtdNumerosNaCartela
            int indexNumero = numerosSorteados[cartelas[i][j]];
            if (maiorIndexNaCartela<indexNumero) maiorIndexNaCartela = indexNumero;
        }
        qtdNumeroParaGanhar.push_back(maiorIndexNaCartela);
    }

    int menorNumeroParaGanhar = *min_element(qtdNumeroParaGanhar.begin(), qtdNumeroParaGanhar.end()); // O(n)

    for (int i=0; i<qtdCartelas; i++) { // O(n)
        if (qtdNumeroParaGanhar[i] == menorNumeroParaGanhar) cout << i+1 << " ";
    }

    cout << endl;
}
