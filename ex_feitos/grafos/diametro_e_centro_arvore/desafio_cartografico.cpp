#include <bits/stdc++.h>

using namespace std;


int main() {
	int qtdCidades;
	cin >> qtdCidades;

	vector<vector<int>> estradas(qtdCidades+1, vector<int>());

	for (int i=0; i<qtdCidades-1; i++) {
		int cidade1, cidade2;
		cin >> cidade1 >> cidade2;

		estradas[cidade1].push_back(cidade2);
		estradas[cidade2].push_back(cidade1);
	}

	int cidadeInicial = 1;

	for (int i=0; i<2; i++) {
		vector<int> distancias(qtdCidades+1, -1);
		
		queue<int> proximasCidades;
		proximasCidades.push(cidadeInicial);
		distancias[cidadeInicial] = 0;

		while (!proximasCidades.empty()) {
			int cidadeAtual = proximasCidades.front();
			proximasCidades.pop();

			for (int cidadeVizinha : estradas[cidadeAtual]) {
				if (distancias[cidadeVizinha] == -1) {
					distancias[cidadeVizinha] = distancias[cidadeAtual] + 1;
					proximasCidades.push(cidadeVizinha);
				}
			}
		}

		int maiorDistancia = -1;
		for (int j=1; j<=qtdCidades; j++) {
			if (distancias[j] > maiorDistancia) {
				maiorDistancia = distancias[j];
				cidadeInicial = j;
			}
		}

		if (i == 1) cout << maiorDistancia << endl;
	}
}
