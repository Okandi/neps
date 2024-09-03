#include <bits/stdc++.h>

using namespace std;


int find(int codigo, vector<int> &parentes) {
	if (parentes[codigo] == codigo) return codigo;
	return parentes[codigo] = find(parentes[codigo], parentes);
}


void merge(int codigo1, int codigo2, vector<int> &tamanhos, vector<int> &parentes) {
	int i = find(codigo1, parentes), j = find(codigo2, parentes);

	if (tamanhos[i] >= tamanhos[j]) {
		parentes[j] = i;
		tamanhos[i] += tamanhos[j];
	} else {
		parentes[i] = j;
		tamanhos[j] += tamanhos[i];
	}
}



int main() {
	int qtdBancos, qtdOperacoes;
	cin >> qtdBancos >> qtdOperacoes;

	vector<int> parentes(qtdBancos+1, 0);
	vector<int> tamanhos(qtdBancos+1, 1);

	for (int i=1; i<=qtdBancos; i++) parentes[i] = i;

	vector<char> results;
	for (int i=0; i<qtdOperacoes; i++) {
		char operacao; int codigo1, codigo2;
		cin >> operacao >> codigo1 >> codigo2;

		// O(a(n)) <- a(n) = função reversa de ackermann (praticamente instantâneo)

		if (operacao == 'F') merge(codigo1, codigo2, tamanhos, parentes);
		else {
			if (find(codigo1, parentes) == find(codigo2, parentes)) results.push_back('S');
			else results.push_back('N');
		}
	}

	for (auto c : results) cout << c << endl;
}
