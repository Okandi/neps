#include <bits/stdc++.h>

using namespace std;


int main() {
	int qtdDicionario, qtdTestes;
	cin >> qtdDicionario >> qtdTestes;

	vector<string> dicionario(qtdDicionario);
	for (int i=0; i<qtdDicionario; i++) cin >> dicionario[i];

	vector<vector<string>> results;

	for (int k=0; k<qtdTestes; k++) {
		string teste;
		cin >> teste;

		vector<string> possibilidades;
		for (string correta : dicionario) {

			vector<vector<int>> dp(teste.size()+1, vector<int>(correta.size()+1));

			int i, j;
			for (i=1; i<=teste.size(); i++) {
				for (j=1; j<=correta.size(); j++) {
					if (teste[i-1] == correta[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
					else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}

			int qtdErros = 0;

			i=teste.size(), j=correta.size();
			while (i != 0 && j != 0) {
				if (teste[i-1] == correta[j-1]) {
					i--; j--; continue;
				} else if (dp[i-1][j-1] == dp[i][j]) {
					i--; j--;
				} else if (dp[i-1][j] == dp[i][j-1]) {
					if (i > j) i--;
					else j--;
				} else if (dp[i-1][j] > dp[i][j-1]) i--;
				else j--;
				qtdErros++;
			}

			qtdErros += i + j;

			if (qtdErros <= 2) possibilidades.push_back(correta);
		}

		results.push_back(possibilidades);
	}

	for (auto possibilidades : results) {
		for (auto palavra : possibilidades) cout << palavra << " ";
		cout << endl;
	}
}
