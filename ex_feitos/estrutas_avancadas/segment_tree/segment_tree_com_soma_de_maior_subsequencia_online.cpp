#include <bits/stdc++.h>

#define ll long long
#define INF 1e+18

using namespace std;


struct Node {

	ll maxSum, leftSum, rightSum, sum;

	Node(ll maxSum=-INF, ll leftSum=0, ll rightSum=0, ll sum=0) : maxSum(maxSum), leftSum(leftSum), rightSum(rightSum), sum(sum) {}

	Node operator + (Node other) {
		Node answ;

		answ.maxSum = max({this->maxSum, other.maxSum, this->rightSum + other.leftSum});
		answ.leftSum = max(this->leftSum, this->sum + other.leftSum);
		answ.rightSum = max(other.rightSum, other.sum + this->rightSum);
		answ.sum = this->sum + other.sum;

		return answ;
	}

};


void build(vector<Node> &BITS, vector<ll> &valores, ll l, ll r, ll i) {
	if (l == r) {
		BITS[i].maxSum = max(valores[l], 0ll);
		BITS[i].leftSum = valores[l];
		BITS[i].rightSum = valores[l];
		BITS[i].sum = valores[l];
		return;
	}

	ll meio = (l+r)/2;

	build(BITS, valores, l, meio, i*2);
	build(BITS, valores, meio+1, r, i*2+1);

	BITS[i] = BITS[i*2] + BITS[i*2+1];
}


void update(vector<Node> &BITS, ll valor, ll id, ll l, ll r, ll i) {
	if (l == r) {
		BITS[i].maxSum = max(BITS[i].sum+valor, 0ll);
		BITS[i].leftSum += valor;
		BITS[i].rightSum += valor;
		BITS[i].sum += valor;
		return;
	}

	ll meio = (l+r)/2;

	if (id <= meio) update(BITS, valor, id, l, meio, i*2);
	else update(BITS, valor, id, meio+1, r, i*2+1);

	BITS[i] = BITS[i*2] + BITS[i*2+1];
}


Node query(vector<Node> &BITS, ll l, ll r, ll p, ll q, ll i) {
	if (q < l || r < p) return Node();
	if (p <= l && r <= q) return BITS[i];

	ll meio = (l+r)/2;

	return query(BITS, l, meio, p, q, i*2) + query(BITS, meio+1, r, p, q, i*2+1);
}


int main() {
	ll tamanho, qtdConsultas;
	cin >> tamanho >> qtdConsultas;

	vector<ll> valores(tamanho+1);
	for (ll i=1; i<=tamanho; i++) cin >> valores[i];

	vector<Node> BITS(tamanho*4+1);
	build(BITS, valores, 1, tamanho, 1);

	vector<ll> results;
	for (ll i=0; i<qtdConsultas; i++) {
		int consulta;
		cin >> consulta;

		switch (consulta) {
			case 1:
				ll id, x;
				cin >> id >> x;
				update(BITS, x, id, 1, tamanho, 1);

				break;
			case 2:
				ll l, r;
				cin >> l >> r;
				results.push_back(query(BITS, 1, tamanho, l, r, 1).maxSum);

				break;
		}
	}

	for (auto r : results) cout << r << endl;
}
