#include <bits/stdc++.h>

#define ll long long
#define INF 1e+18

using namespace std;


struct Node {

	ll valMin, qtdMin, lazy;

	Node() : valMin(INF), qtdMin(0), lazy(0) {}

	Node operator + (Node other) {
		Node answ;

		pair<ll, ll> menor = min(make_pair(this->valMin, this->qtdMin), make_pair(other.valMin, other.qtdMin));

		answ.valMin = menor.first;

		if (this->valMin != other.valMin) answ.qtdMin = menor.second;
		else answ.qtdMin = this->qtdMin + other.qtdMin;

		return answ;
	}

};


void build(vector<Node> &heap, vector<ll> &values, ll l, ll r, ll i) {
	if (l == r) {
		heap[i].valMin = values[l];
		heap[i].qtdMin = 1;
		return;
	}

	ll meio = (l+r)/2;

	build(heap, values, l, meio, i*2);
	build(heap, values, meio+1, r, i*2+1);

	heap[i] = heap[i*2] + heap[i*2+1];
}


void progressLazy(vector<Node> &heap, ll l, ll r, ll i) {
	if (heap[i].lazy == 0) return;

	if (l<r) {
		heap[i*2].lazy += heap[i].lazy;
		heap[i*2+1].lazy += heap[i].lazy;
	}

	heap[i].valMin += heap[i].lazy;

	heap[i].lazy = 0;
}


void update(vector<Node> &heap, ll value, ll l, ll r, ll p, ll q, ll i) {
	progressLazy(heap, l, r, i);

	if (q < l || r < p) return;

	if (p <= l && r <= q) {
		heap[i].lazy += value;
		progressLazy(heap, l, r, i);
		return;
	}

	ll meio = (l+r)/2;

	update(heap, value, l, meio, p, q, i*2);
	update(heap, value, meio+1, r, p, q, i*2+1);

	heap[i] = heap[i*2] + heap[i*2+1];
}

Node query(vector<Node> &heap, ll l, ll r, ll p, ll q, ll i) {
	progressLazy(heap, l, r, i);

	if (q < l || r < p) return Node();
	if (p <= l && r <= q) return heap[i];

	ll meio = (l+r)/2;

	return query(heap, l, meio, p, q, i*2) + query(heap, meio+1, r, p, q, i*2+1);
}

int main() {
	ll tamanho, qtdConsultas;
	cin >> tamanho >> qtdConsultas;

	vector<ll> valores(tamanho+1);
	for (ll i=1; i<=tamanho; i++) cin >> valores[i];

	vector<Node> heap(tamanho*4+1);
	build(heap, valores, 1, tamanho, 1);

	vector<ll> results;
	for (ll i=0; i<qtdConsultas; i++) {
		int consulta;
		cin >> consulta;

		ll l, r, x;

		switch (consulta) {
			case 1:
				cin >> l >> r >> x;
				update(heap, x, 1, tamanho, l, r, 1);
				break;
			case 2:
				cin >> l >> r;
				Node answ = query(heap, 1, tamanho, l, r, 1);
				if (answ.valMin == 0) results.push_back(answ.qtdMin);
				else results.push_back(0);
				break;
		}
	}

	for (auto r : results) cout << r << endl;
}
