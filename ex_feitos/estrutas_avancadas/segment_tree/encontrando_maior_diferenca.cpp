#include <bits/stdc++.h>

#define ll long long
#define INF 1e+18

using namespace std;


struct Node {

	ll max, min;

	Node(ll max=0, ll min=INF) : max(max), min(min) {}

};


void update(vector<Node> &heap, ll valor, ll id, ll l, ll r, ll i) {
	if (l == r) {
		heap[i].max += valor;
		heap[i].min += valor;
		return;
	}

	ll meio = (l+r)/2;

	if (id <= meio) update(heap, valor, id, l, meio, i*2);
	else update(heap, valor, id, meio+1, r, i*2+1);

	heap[i].max = max(heap[2*i].max, heap[2*i+1].max);
	heap[i].min = min(heap[2*i].min, heap[2*i+1].min);
}


void build(vector<Node> &heap, vector<ll> &valores, ll l, ll r, ll i) {
	if (l == r) {
		heap[i].max = valores[l];
		heap[i].min = valores[l];
		return;
	}

	ll meio = (l+r)/2;

	build(heap, valores, l, meio, i*2);
	build(heap, valores, meio+1, r, i*2+1);

	heap[i].max = max(heap[2*i].max, heap[2*i+1].max);
	heap[i].min = min(heap[2*i].min, heap[2*i+1].min);
}


Node query(vector<Node> &heap, ll l, ll r, ll p, ll q, ll i) {
	if (r < p || l > q) return Node();
	if ((p <= l && r <= q) || l == r) return heap[i];

	ll meio = (l+r)/2;

	Node res1 = query(heap, l, meio, p, q, i*2);
	Node res2 = query(heap, meio+1, r, p, q, i*2+1);

	return Node(max(res1.max, res2.max), min(res1.min, res2.min));
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
				ll id, x;
				cin >> id >> x;

				update(heap, x, id, 1, tamanho, 1);

				break;
			case 2:
				ll l, r;
				cin >> l >> r;

				Node res = query(heap, 1, tamanho, l, r, 1);
				results.push_back(res.max-res.min);

				break;
		}
	}

	for (auto r : results) cout << r << endl;
}
