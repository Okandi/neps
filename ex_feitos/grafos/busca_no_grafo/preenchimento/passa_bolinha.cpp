#include <bits/stdc++.h>

using namespace std;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};


bool isCellValid(int x, int y, vector<vector<int>> &visitado) {
	return !(
		x == 0 || x == visitado.size()
		|| y == 0 || y == visitado[0].size()
		|| visitado[x][y]
	);
}


int main() {
	int dimensao, si, sj;
	cin >> dimensao >> si >> sj;

	vector<vector<int>> matriz(dimensao+1, vector<int>(dimensao+1, -1));

	for (int i=1; i<=dimensao; i++) {
		for (int j=1; j<=dimensao; j++) cin >> matriz[i][j];
	}

	stack<pair<int, int>> pilha;
	pilha.push({si, sj});

	vector<vector<int>> visitado(dimensao+1, vector<int>(dimensao+1, false));
	visitado[si][sj] = true;

	int qtdLevantada = 1;

	while (!pilha.empty()) {
		int x = pilha.top().first;
		int y = pilha.top().second;
		pilha.pop();

		for (int i=0; i<4; i++) {
			if (isCellValid(x+dx[i], y+dy[i], visitado) && matriz[x][y] <= matriz[x+dx[i]][y+dy[i]]) {
				visitado[x+dx[i]][y+dy[i]] = true;
				pilha.push({x+dx[i], y+dy[i]});
				qtdLevantada++;
			}
		}
	}

	cout << qtdLevantada;
}
