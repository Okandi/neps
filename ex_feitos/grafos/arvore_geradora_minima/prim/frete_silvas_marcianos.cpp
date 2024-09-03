#include <bits/stdc++.h>

#define INF 999999999

using namespace std;


int main() {
	int qtdColonias, qtdEstradas;
	cin >> qtdColonias >> qtdEstradas;

	vector<vector<pair<int, int>>> estradas(qtdColonias, vector<pair<int, int>>());

	for (int i=0; i<qtdEstradas; i++) {
		int colonia1, colonia2, custo;
		cin >> colonia1 >> colonia2 >> custo;

		estradas[colonia1].push_back({custo, colonia2});
		estradas[colonia2].push_back({custo, colonia1});
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
	vector<bool> marcado(qtdColonias, false);
	vector<int> distancia(qtdColonias, INF);

	distancia[0] = 0;
	fila.push({0, 0});

	int mst = 0;

	for (int i=0; i<qtdColonias; i++) {
		pair<int, int> coloniaAtual;
		while (true) {
			coloniaAtual = fila.top();
			fila.pop();
			if (!marcado[coloniaAtual.second]) break;
		}

		marcado[coloniaAtual.second] = true;
		mst += coloniaAtual.first;

		for (auto vizinho : estradas[coloniaAtual.second]) {
			if (distancia[vizinho.second] > vizinho.first) {
				distancia[vizinho.second] = vizinho.first;
				fila.push(vizinho);
			}
		}
	}

	cout << mst << endl;
}
