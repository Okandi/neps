#include <bits/stdc++.h>

using namespace std;

#define INF 999999999


int main() {
	int qtdSalas, qtdCorredores;
	cin >> qtdSalas >> qtdCorredores;

	vector<vector<vector<int>>> predio(qtdSalas+1, vector<vector<int>>(qtdSalas+1, vector<int>(qtdSalas+1, INF)));

	for (int i=1; i<=qtdSalas; i++) {
		for (int j=1; j<=qtdSalas; j++) {
			if (i == j) predio[i][j][0] = 0;
		}
	}

	for (int i=0; i<qtdCorredores; i++) {
		int sala1, sala2, distancia;
		cin >> sala1 >> sala2 >> distancia;

		predio[sala1][sala2][0] = distancia;
		predio[sala2][sala1][0] = distancia;
	}

	for (int k=1; k<=qtdSalas; k++) {
		for (int i=1; i<=qtdSalas; i++) {
			for (int j=1; j<=qtdSalas; j++) {
				predio[i][j][k] = min(predio[i][j][k-1], predio[i][k][k-1] + predio[k][j][k-1]);
			}
		}
	}

	int resposta = INF;
	for (int i=1; i<=qtdSalas; i++) {
		int maiorDistanciaDaSalaI = 0;
		for (int j=1; j<=qtdSalas; j++) {
			maiorDistanciaDaSalaI = max(maiorDistanciaDaSalaI, predio[i][j][qtdSalas]);
		}
		resposta = min(resposta, maiorDistanciaDaSalaI);
	}

	cout << resposta << endl;
}
