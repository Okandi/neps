#include <bits/stdc++.h>

using namespace std;


int qtdTotalProdutos, precoTotalProdutos;


int sumTillIndex(int precos[], int indiceProduto) {
    int soma = 0;
    for (int i=0; i<indiceProduto; i++) {
        soma += precos[i];
    }
    return soma;
}

void recursionFunction(int &totalFormas, int precos[], int indiceProduto) { // otimizei demais, não era esse o ponto da questão (demorei para montar) (cout demora muito!) (O(n!)?)
    if (indiceProduto == qtdTotalProdutos) {
        if (sumTillIndex(precos, indiceProduto) == precoTotalProdutos) totalFormas++;
        return;
    } else {
        int precoAtual = 1;
        if (indiceProduto != 0) precoAtual = precos[indiceProduto-1]+1;
        if (indiceProduto == qtdTotalProdutos-1) precoAtual = precoTotalProdutos - sumTillIndex(precos, indiceProduto);

        int qtdItensFaltando = qtdTotalProdutos - indiceProduto;
        while (precoAtual > 0 && sumTillIndex(precos, indiceProduto) + (2*precoAtual + qtdItensFaltando-1)*qtdItensFaltando/2 <= precoTotalProdutos) { // regra de sarros pra otimizar
            precos[indiceProduto] = precoAtual;
            recursionFunction(totalFormas, precos, indiceProduto+1);
            precoAtual++;
        }
        return;
    }
}


int main() {
    int totalFormas = 0;
    cin >> precoTotalProdutos >> qtdTotalProdutos;

    int precos[qtdTotalProdutos] = {};

    recursionFunction(totalFormas, precos, 0);

    cout << totalFormas << endl;
}
