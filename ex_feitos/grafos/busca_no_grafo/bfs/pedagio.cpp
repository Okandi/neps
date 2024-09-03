#include <bits/stdc++.h>

#define INF 99999

using namespace std;


int main() {
	vector<vector<int>> respostas;
	while (true) {
	   	int qtdCidades, qtdEstradas, cidadeAtual, maximoViagens;
		cin >> qtdCidades >> qtdEstradas >> cidadeAtual >> maximoViagens;

		if (qtdCidades == 0) break;

		vector<vector<int>> ligacoes(qtdCidades+1, vector<int>());

		for (int i=0; i<qtdEstradas; i++) {
			int cidadeX, cidadeY;
			cin >> cidadeX >> cidadeY;
			ligacoes[cidadeX].push_back(cidadeY);
			ligacoes[cidadeY].push_back(cidadeX);
		}

		vector<int> camadas(qtdCidades+1, INF);
		camadas[cidadeAtual] = 0;

		queue<int> fila;
		fila.push(cidadeAtual);

		while (!fila.empty()) {
			cidadeAtual = fila.front();
			fila.pop();

			for (int cidadeVizinha : ligacoes[cidadeAtual]) {
				if (camadas[cidadeVizinha] == INF) {
					camadas[cidadeVizinha] = camadas[cidadeAtual]+1;
					fila.push(cidadeVizinha);
				}
			}
		}

		vector<int> resultado;
		for (int i=1; i<=qtdCidades; i++) {
			if (camadas[i] != 0 && camadas[i] <= maximoViagens) resultado.push_back(i);
		}

		respostas.push_back(resultado);
	}

	for (int i=1; i<=respostas.size(); i++) {
		cout << "Teste " << i << endl;
		for (auto cidade : respostas[i-1]) cout << cidade << " ";
		if (i != respostas.size()) cout << endl << endl;
	}
}
