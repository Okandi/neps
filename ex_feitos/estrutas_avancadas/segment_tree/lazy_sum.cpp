#include <bits/stdc++.h>

#define ll long long

using namespace std;


struct Node {

	ll sum, lazy;

	Node(ll sum=0) : sum(sum), lazy(0) {};

	Node operator + (Node n) {
		return Node(this->sum+n.sum);
	}

};


void build(vector<Node> &heap, vector<ll> &valores, ll l, ll r, ll i) {
	if (l == r) {
		heap[i].sum = valores[l];
		return;
	}

	ll meio = (l+r)/2;

	build(heap, valores, l, meio, i*2);
	build(heap, valores, meio+1, r, i*2+1);

	heap[i] = heap[2*i] + heap[2*i+1];
}


void lazyPropagation(vector<Node> &heap, ll l, ll r, ll i) {
	if (!heap[i].lazy) return;
	heap[i].sum += (r-l+1)*heap[i].lazy;
	if (l<r) {
		heap[i*2].lazy += heap[i].lazy;
		heap[i*2+1].lazy += heap[i].lazy;
	}
	heap[i].lazy = 0;
}


void update(vector<Node> &heap, ll valor, ll l, ll r, ll p, ll q, ll i) {
	lazyPropagation(heap, l, r, i);

	if (r < p || l > q) return;

	if (p <= l && r <= q) {
		heap[i].lazy += valor;
		lazyPropagation(heap, l, r, i);
		return;
	}

	ll meio = (l+r)/2;

	update(heap, valor, l, meio, p, q, i*2);
	update(heap, valor, meio+1, r, p, q, i*2+1);

	heap[i] = heap[2*i] + heap[2*i+1];
}


Node query(vector<Node> &heap, ll l, ll r, ll p, ll q, ll i) {
	if (q < l || r < p) return Node();
	lazyPropagation(heap, l, r, i);
	if (p <= l && r <= q) return heap[i];

	ll meio = (r+l)/2;

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
		int operacao;
		cin >> operacao;

		ll l, r;

		switch(operacao) {
			case 1:
				ll x;
				cin >> l >> r >> x;
				update(heap, x, 1, tamanho, l, r, 1);

				break;
			case 2:
				cin >> l >> r;
				results.push_back(query(heap, 1, tamanho, l, r, 1).sum);

				break;
		}
	}

	for (auto r : results) cout << r << endl;
}
