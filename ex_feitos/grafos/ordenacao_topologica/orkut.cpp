#include <bits/stdc++.h>

using namespace std;


int findNameIndex(string nome, vector<string> &nomes) {
	for (int i=0; i<nomes.size(); i++) {
		if (nome == nomes[i]) return i;
	}
	return -1;
}


int main() {
	int teste = 1;
	while (true) {
		int qtdAmigos;
		cin >> qtdAmigos;

		if (qtdAmigos == 0) break;

		vector<vector<int>> amigos(qtdAmigos, vector<int>());
		vector<string> nomes(qtdAmigos);

		for (int i=0; i<qtdAmigos; i++) cin >> nomes[i];

		for (int i=0; i<qtdAmigos; i++) {
			string nome; int qtdRelacoes;
			cin >> nome >> qtdRelacoes;

			int indexNome = findNameIndex(nome, nomes);
			for (int i=0; i<qtdRelacoes; i++) {
				string nomeRelacionado;
				cin >> nomeRelacionado;

				amigos[findNameIndex(nomeRelacionado, nomes)].push_back(indexNome);
			}
		}

		vector<int> grau(qtdAmigos, 0);
		for (int i=0; i<qtdAmigos; i++) {
			for (auto amigo : amigos[i]) grau[amigo]++;
		}

		vector<int> ordem;
		queue<int> fila;

		for (int i=0; i<qtdAmigos; i++) {
			if (grau[i] == 0) fila.push(i);
		}

		while (!fila.empty()) {
			int amigo = fila.front();
			fila.pop();

			ordem.push_back(amigo);

			for (int amigoRelacionado : amigos[amigo]) {
				grau[amigoRelacionado]--;
				if (grau[amigoRelacionado] == 0) {
					fila.push(amigoRelacionado);
				}
			}
		}

		cout << "Teste " << teste << endl;
		if (ordem.size() != 0) {
			for (int amigo : ordem) cout << nomes[amigo] << " ";
			cout << endl;
		} else cout << "impossivel" << endl;
		teste++;
	}
}
