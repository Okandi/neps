#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int peso, no1, no2;

	Edge(int peso, int no1, int no2) {
		this->peso = peso;
		this->no1 = no1;
		this->no2 = no2;
	}

	bool operator < (Edge e) const { return this->peso < e.peso; }
};


int find(int cidade, vector<int> &parentes) {
	if (cidade == parentes[cidade]) return cidade;
	return parentes[cidade] = find(parentes[cidade], parentes);
}


void merge(int cidade1, int cidade2, vector<int> &tamanhos, vector<int> &parentes) {
	int i = find(cidade1, parentes), j = find(cidade2, parentes);

	if (tamanhos[i] >= tamanhos[j]) {
		parentes[j] = i;
		tamanhos[i] += tamanhos[j];
	} else {
		parentes[i] = j;
		tamanhos[j] += tamanhos[i];
	}
}


int main() {
	int qtdCidades, qtdRodovias;
	cin >> qtdCidades >> qtdRodovias;

	vector<Edge> rodovias;

	for (int i=0; i<qtdRodovias; i++) {
		int cidade1, cidade2, distancia;
		cin >> cidade1 >> cidade2 >> distancia;

		Edge e(distancia, cidade1, cidade2);
		rodovias.push_back(e);
	}

	sort(rodovias.begin(), rodovias.end());

	vector<int> tamanhos(qtdCidades+1, 1);
	vector<int> parentes(qtdCidades+1, 0);
	for (int i=1; i<=qtdCidades; i++) parentes[i] = i;

	int mag = 0;
	for (auto rodovia : rodovias) {
		if (find(rodovia.no1, parentes) != find(rodovia.no2, parentes)) {
			merge(rodovia.no1, rodovia.no2, tamanhos, parentes);
			mag += rodovia.peso;
		}
	}

	cout << mag << endl;
}
