#include <bits/stdc++.h>

#define ll long long
#define pbb pair<bool, bool>

using namespace std;


int main() {
	ll tamanho, qtdArvores;
	cin >> tamanho >> qtdArvores;

	vector<ll> arvore(tamanho+1);
	vector<int> respostas;

	for (ll i=0; i<qtdArvores; i++) { // O(tamanho*qtdArvores)

		for (ll i=1; i<=tamanho; i++) cin >> arvore[i]; // O número de operações feitas dentro do loop, mesmo que não mude a quantidade de iterações, impacta no tempo

		pbb isHeap = {true, true};

		for (ll i=2; i<=tamanho; i++) { // Caso seja possível reduzir o número de operações ao quebrar um loop previamente, é melhor, por isso é bom separar cada bloco de operação em seu próprio loop
			isHeap.first = isHeap.first && arvore[i/2] <= arvore[i];
			isHeap.second = isHeap.second && arvore[i/2] >= arvore[i];
			if (!(isHeap.first || isHeap.second)) break;
		} // Ele vai desempenhar melhor se eu separar um loop para cada heap (min/max) porque cada um pode matar seu próprio loop primeiro, fazendo menos operações (mas isso já foi suficiente)
		// Talvez não impactasse tanto nesse caso por causa do &&, mas no desespero qualquer coisa vale

		if (isHeap.first) respostas.push_back(-1);
		else if (isHeap.second) respostas.push_back(1);
		else respostas.push_back(0);
	}

	for (auto resposta : respostas) cout << resposta << endl;
}
