#include <bits/stdc++.h>

#define ll long long

using namespace std;


class Heap {

private:

	vector<ll> dados;

	void fixInsert(ll node) {
		if (node == 1) return;
		if (dados[node/2] >= dados[node]) return;
		swap(dados[node/2], dados[node]);
		fixInsert(node/2);
	}

	void fixDelete(ll node) {
		if (node*2 > size()) return;
		ll maxNode = node*2;
		if (node*2+1 <= size() && dados[node*2] <= dados[node*2+1]) maxNode = node*2+1;
		if (dados[maxNode] > dados[node]) {
			swap(dados[maxNode], dados[node]);
			fixDelete(maxNode);
		}
	}

public:

	Heap() : dados(1) {};

	bool isEmpty() {
		return size() == 0;
	}

	ll size() {
		return dados.size()-1;
	}

	void insert(ll value) {
		dados.push_back(value);
		fixInsert(size());
	}

	void remove(ll node) {
		swap(dados[node], dados[size()]);
		dados.pop_back();
		fixDelete(node);
	}

	ll maiorValor(bool segundo) {
		if (segundo) {
			if (3 > size()) return dados[2];
			else if (dados[3] > dados[2]) return dados[3];
			return dados[2];
		}
		return dados[1];
	}

};


int main() {
	ll qtdOperacoes;
	cin >> qtdOperacoes;

	Heap* heap = new Heap();

	vector<ll> respostas;

	for (ll i=0; i<qtdOperacoes; i++) {
		int operacao;
		cin >> operacao;

		switch(operacao) {
			case 1:
				heap->remove(1);

				break;
			case 2:
				ll val;
				cin >> val;
				heap->insert(val);

				break;
			case 3:
				respostas.push_back(heap->maiorValor(false));

				break;
			case 4:
				respostas.push_back(heap->maiorValor(true));

				break;
		}
	}

	for (auto r : respostas) cout << r << endl;
}
