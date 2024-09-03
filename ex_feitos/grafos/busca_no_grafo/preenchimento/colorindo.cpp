#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> dy = {-1, -1, 0, 1, 1, 1, 0, -1};


bool isCellValid(int x, int y, vector<vector<int>> &table) {
	return !(
		x == 0 || x == table.size()
		|| y == 0 || y == table[0].size()
		|| table[x][y]
	);
}


int main() {
	int qtdLinhas, qtdColunas, xInicial, yInicial, qtdQuadradosCheios;
	cin >> qtdLinhas >> qtdColunas >> xInicial >> yInicial >> qtdQuadradosCheios;

	vector<vector<int>> tabela(qtdLinhas+1, vector<int>(qtdColunas+1, false));

	for (int i=0; i<=qtdLinhas; i++) tabela[i][0] = true;
	for (int i=0; i<=qtdColunas; i++) tabela[0][i] = true;

	for (int i=0; i<qtdQuadradosCheios; i++) {
		int xCheio, yCheio;
		cin >> xCheio >> yCheio;

		tabela[xCheio][yCheio] = true;
	}

	queue<pair<int, int>> fila;

	fila.push({xInicial, yInicial});
	tabela[xInicial][yInicial] = true;
	int qtdPintado = 1;

	int x = xInicial;
	int y = yInicial;
	while (!fila.empty()) {
		x = fila.front().first;
		y = fila.front().second;
		fila.pop();
		for (int i=0; i<8; i++) {
			if (isCellValid(x+dx[i], y+dy[i], tabela)) {
				tabela[x+dx[i]][y+dy[i]] = true;
				fila.push({x+dx[i], y+dy[i]});
				qtdPintado++;
			}
		}
	}

	cout << qtdPintado << endl;
}
