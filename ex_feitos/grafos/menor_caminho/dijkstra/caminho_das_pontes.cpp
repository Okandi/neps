#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000


int main() {
	int qtdPilares, qtdPontes;
	cin >> qtdPilares >> qtdPontes;

	vector<vector<pair<int, int>>> pontes(qtdPilares+2, vector<pair<int, int>>());

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i=0; i<qtdPontes; i++) {
		int pilar1, pilar2, qtdBuracos;
		cin >> pilar1 >> pilar2 >> qtdBuracos;

		pontes[pilar1].push_back({pilar2, qtdBuracos});
		pontes[pilar2].push_back({pilar1, qtdBuracos});
	}

	pq.push({0, 0});

	vector<bool> marcado(qtdPilares+2, false);
	vector<int> dist(qtdPilares+2, INF);

	dist[0] = 0;

	for (int i=0; i<qtdPilares+2; i++) {
		int pilarAtual;

		while (true) {
			pilarAtual = pq.top().second;
			pq.pop();
			if (!marcado[pilarAtual]) break;
		}

		marcado[pilarAtual] = true;

		for (int j=0; j<pontes[pilarAtual].size(); j++) {
			pair<int, int> ponte = pontes[pilarAtual][j];
			if (!marcado[ponte.first] && dist[ponte.first] > dist[pilarAtual] + ponte.second) {
				dist[ponte.first] = dist[pilarAtual] + ponte.second;
				pq.push({dist[ponte.first], ponte.first});
			}
		}
	}

	cout << dist[qtdPilares+1] << endl;
}
