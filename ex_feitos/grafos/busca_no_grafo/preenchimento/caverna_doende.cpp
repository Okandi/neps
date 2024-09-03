#include <bits/stdc++.h>

using namespace std;


vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {-1, 0, 1, 0};


bool isCellValid(int x, int y, vector<vector<int>> &caverna, vector<vector<int>> &camadas) {
	return !(
		x == -1 || x == caverna.size()
		|| y == -1 || y == caverna[0].size()
		|| caverna[x][y] == 2
		|| camadas[x][y] != -1
	);
}


int main() {
	int qtdLinhas, qtdColunas;
	cin >> qtdLinhas >> qtdColunas;

	int xInicial, yInicial;

	vector<vector<int>> caverna(qtdLinhas, vector<int>(qtdColunas));
	for (int i=0; i<qtdLinhas; i++) {
		for (int j=0; j<qtdColunas; j++) {
			cin >> caverna[i][j];
			if (caverna[i][j] == 3) {
				xInicial = i;
				yInicial = j;
			}
		}
	}

	vector<vector<int>> camadas(qtdLinhas, vector<int>(qtdColunas, -1));
	queue<pair<int, int>> fila;
	fila.push({xInicial, yInicial});
	camadas[xInicial][yInicial] = 0;

	int resultado = 999999;

	while (!fila.empty()) {
		int x = fila.front().first;
		int y = fila.front().second;
		fila.pop();

		for (int i=0; i<4; i++) {
			int newX = x+dx[i];
			int newY = y+dy[i];

			if (isCellValid(newX, newY, caverna, camadas)) {
				camadas[newX][newY] = camadas[x][y]+1;
				if (caverna[newX][newY] == 0) resultado = min(camadas[newX][newY], resultado);
				else fila.push({newX, newY});
			}
		}
	}

	cout << resultado << endl;
}
