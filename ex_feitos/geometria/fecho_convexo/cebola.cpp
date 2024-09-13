#include <bits/stdc++.h>

using namespace std;


int produtoVetorial(pair<int, int> &V, pair<int, int> &A, pair<int, int> &B) {
	return (A.first-V.first)*(B.second-V.second) - (A.second-V.second)*(B.first-V.first);
}

bool clockwise(pair<int, int> &V, pair<int, int> &A, pair<int, int> &B) {
	return produtoVetorial(V, A, B) <= 0;
}

bool counterClockwise(pair<int, int> &V, pair<int, int> &A, pair<int, int> &B) {
	return produtoVetorial(V, A, B) >= 0;
}


int main() {
	vector<int> results;

	while (true) {
		int qtdPontos;
		cin >> qtdPontos;

		if (!qtdPontos) break;

		vector<pair<int, int>>* pontos = new vector<pair<int, int>>();
		for (int i=0; i<qtdPontos; i++) {
			int x, y;
			cin >> x >> y;

			pontos->push_back({x, y});
		}

		sort(pontos->begin(), pontos->end());

		int camadas = 0;
		while (!pontos->empty()) {
			vector<pair<pair<int, int>, int>> parteSuperior;
			for (int i=0; i<pontos->size(); i++) {
				pair<int, int> ponto = (*pontos)[i];
				while (parteSuperior.size() >= 2) {
					if (clockwise(parteSuperior[parteSuperior.size()-2].first, parteSuperior[parteSuperior.size()-1].first, ponto)) break;
					parteSuperior.pop_back();
				}
				parteSuperior.push_back({{ponto.first, ponto.second}, i});
			}

			vector<pair<pair<int, int>, int>> parteInferior;
			for (int i=0; i<pontos->size(); i++) {
				auto ponto = (*pontos)[i];
				while (parteInferior.size() >= 2) {
					if (counterClockwise(parteInferior[parteInferior.size()-2].first, parteInferior[parteInferior.size()-1].first, ponto)) break;
					parteInferior.pop_back();
				}
				parteInferior.push_back({{ponto.first, ponto.second}, i});
			}

			vector<bool> pontosUtilizados(pontos->size(), 0);
			for (auto ponto : parteSuperior) pontosUtilizados[ponto.second] = true;
			for (auto ponto : parteInferior) pontosUtilizados[ponto.second] = true;


			vector<pair<int, int>> tempPontos;
			for (int i=0; i<pontos->size(); i++) {
				if (!pontosUtilizados[i]) tempPontos.push_back((*pontos)[i]);
			}

			*pontos = tempPontos;

			camadas++;
		}

		results.push_back(camadas);
	}

	for (auto result : results) {
		if (!(result%2)) cout << "Do not take this onion to the lab!" << endl;
		else cout << "Take this onion to the lab!" << endl;
	}
}
