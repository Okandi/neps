#include <bits/stdc++.h>

#define ll long long

using namespace std;


struct Node {

	ll sum;

	Node(ll sum = 0) : sum(sum) {};

	Node operator + (Node n) const {
		return Node(sum+n.sum);
	}

};


ll query(vector<Node> &heap, ll l, ll r, ll p, ll q, ll i) {
	if (r < p || l > q) return 0;
	if (p <= l && r <= q) return heap[i].sum;

	ll meio = (l+r)/2;
	ll res = 0;

	res += query(heap, l, meio, p, q, i*2);
	res += query(heap, meio+1, r, p, q, i*2+1);

	return res;
}


void update(vector<Node> &heap, ll value, ll l, ll r, ll id, ll i) {
	if (l == r) {
		heap[i].sum = value;
		return;
	}

	ll meio = (l+r)/2;

	if (id <= meio) update(heap, value, l, meio, id, i*2);
	else update(heap, value, meio+1, r, id, i*2+1);

	heap[i] = heap[i*2] + heap[i*2+1];
}


void build(vector<Node> &heap, vector<ll> &values, ll l, ll r, ll i) {
	if (l == r) {
		heap[i].sum = values[l];
		return;
	}

	ll meio = (l+r)/2;

	build(heap, values, l, meio, i*2);
	build(heap, values, meio+1, r, i*2+1);

	heap[i] = heap[i*2] + heap[i*2+1];
}


int main() {
	ll tamanho, qtdOperacoes;
	cin >> tamanho >> qtdOperacoes;

	vector<ll> valores(tamanho+1);
	for (ll i=1; i<=tamanho; i++) cin >> valores[i];

	vector<Node> heap(4*tamanho+1);

	build(heap, valores, 1, tamanho, 1);

	vector<ll> results;
	for (ll i=0; i<qtdOperacoes; i++) {
		int operacao;
		cin >> operacao;

		switch(operacao) {
			case 1:
				ll index, val;
				cin >> index >> val;

				update(heap, val, 1, tamanho, index, 1);
				break;
			case 2:
				ll l, r;
				cin >> l >> r;

				results.push_back(query(heap, 1, tamanho, l, r, 1));
				break;
		}
	}

	for (auto r : results) cout << r << endl;
}
