#include <bits/stdc++.h>

#define INF 99999999;

using namespace std;


int main() {
    int valorFinalCompra, qtdMoedas;
    cin >> valorFinalCompra >> qtdMoedas;

    vector<int> moedas(qtdMoedas+1);

    for (int i=1; i<=qtdMoedas; i++) cin >> moedas[i];

    vector<vector<int>> dp(qtdMoedas+1, vector<int>(valorFinalCompra+1, 0));

    dp[0][0] = 0;

    for (int j=1; j<=valorFinalCompra; j++) dp[0][j] = -INF;

    for (int i=1; i<=qtdMoedas; i++) { // O(valorFinalCompra*qtdMoedas)
        for (int j=1; j<=valorFinalCompra; j++) {
            if (moedas[i] <= j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-moedas[i]]+moedas[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    if (dp[qtdMoedas][valorFinalCompra] == valorFinalCompra) cout << "S";
    else cout << "N";
    cout << endl;
}
