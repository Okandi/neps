#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdCartelas, qtdNumerosNaCartela, qtdNumerosSorteados;
    cin >> qtdCartelas >> qtdNumerosNaCartela >> qtdNumerosSorteados;

    set<int> cartelas[qtdCartelas];
    for (int i=0; i<qtdCartelas; i++) { // O(n²*log(n))
        cartelas[i] = {};
        for (int j=0; j<qtdNumerosNaCartela; j++) {
            int numero;
            cin >> numero;
            cartelas[i].insert(numero);
        }
    }

    priority_queue<int, vector<int>, greater<int>> cartelasGanhadoras;
    for (int i=0; i<qtdNumerosSorteados; i++) { // O(n²*log(n)) obs: qtdNumerosSorteados > qtdNumerosNaCartela
        int numeroSorteado;
        cin >> numeroSorteado;

        for (int i=0; i<sizeof(cartelas)/sizeof(set<int>); i++) {
            cartelas[i].erase(numeroSorteado);
            if (cartelas[i].empty()) cartelasGanhadoras.push(i+1);
        }

        if (!cartelasGanhadoras.empty()) break;
    }

    while (!cartelasGanhadoras.empty()) {
        cout << cartelasGanhadoras.top() << " ";
        cartelasGanhadoras.pop();
    }

    cout << endl;
}
