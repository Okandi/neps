#include <bits/stdc++.h>

#define INF 9999999;

using namespace std;


int main() {
	vector<int> resultados;
	while (true) {
	 	int tamanhoCartao, qtdFrases;
		cin >> tamanhoCartao >> qtdFrases;
		if (tamanhoCartao == qtdFrases && tamanhoCartao == 0) break;

		vector<pair<int, int>> frases(qtdFrases+1);

		for (int i=1; i<=qtdFrases; i++) {
			int qtdCaracteres, qtdDesculpe;
			cin >> qtdCaracteres >> qtdDesculpe;

			frases[i] = make_pair(qtdCaracteres, qtdDesculpe);
		}

		vector<vector<int>> dp(qtdFrases+1, vector<int>(tamanhoCartao+1, 0));

		for (int i=1; i<=qtdFrases; i++) { // O(n²)
			for (int j=1; j<=tamanhoCartao; j++) {
				if (frases[i].first > j) dp[i][j] = dp[i-1][j];
				else dp[i][j] = max(dp[i-1][j], dp[i-1][j-frases[i].first]+frases[i].second);
			}
		}

		resultados.push_back(dp[qtdFrases][tamanhoCartao]);
	}

	for (int i=0; i<resultados.size(); i++) {
		cout << "Teste " << i+1 << endl;
		cout << resultados[i] << endl;
		cout << endl;
	}
}
