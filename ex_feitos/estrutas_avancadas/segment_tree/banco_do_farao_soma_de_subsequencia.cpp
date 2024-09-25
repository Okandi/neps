#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define f first
#define s second

#define INF 1e+18

using namespace std;


struct Node {
	pll maxSum, leftSum, rightSum, sum;

	Node(pll maxSum = {-INF, -INF}, pll leftSum = {-INF, -INF}, pll rightSum = {-INF, -INF}, pll sum = {-INF, -INF}) : maxSum(maxSum), leftSum(leftSum), rightSum(rightSum), sum(sum) {}

	Node operator + (Node other) {
		Node res;

		res.maxSum = max({this->maxSum, other.maxSum, make_pair(this->rightSum.f+other.leftSum.f, this->rightSum.s+other.leftSum.s)});
		res.leftSum = max(this->leftSum, make_pair(this->sum.f+other.leftSum.f, this->sum.s+other.leftSum.s));
		res.rightSum = max(other.rightSum, make_pair(other.sum.f+this->rightSum.f, other.sum.s+this->rightSum.s));
		res.sum = make_pair(this->sum.f+other.sum.f, this->sum.s+other.sum.s);

		return res;
	}
};


void build(vector<Node> &BITS, vector<ll> &valores, ll l, ll r, ll i) {
	if (l == r) {
		BITS[i].maxSum = {valores[l], 1};
		BITS[i].leftSum = {valores[l], 1};
		BITS[i].rightSum = {valores[l], 1};
		BITS[i].sum = {valores[l], 1};
		return;
	}

	ll meio = (l+r)/2;

	build(BITS, valores, l, meio, i*2);
	build(BITS, valores, meio+1, r, i*2+1);

	BITS[i] = BITS[2*i] + BITS[2*i+1];
}


Node query(vector<Node> &BITS, ll l, ll r, ll p, ll q, ll i) {
	if (p > r || q < l) return Node();
	if (p <= l && r <= q) return BITS[i];

	ll meio = (r+l)/2;

	Node left = query(BITS, l, meio, p, q, i*2);
	Node right = query(BITS, meio+1, r, p, q, i*2+1);

	if (left.maxSum.f == -INF && right.maxSum.f != -INF) return right;
	if (left.maxSum.f != -INF && right.maxSum.f == -INF) return left;
	if (left.maxSum.f != -INF && right.maxSum.f != -INF) return left + right;
	return left;
}


int main() {
	ll qtdInstancias;
	cin >> qtdInstancias;

	vector<pll> results;
	for (ll i=0; i<qtdInstancias; i++) {
		ll tamanho;
		cin >> tamanho;

		vector<ll> contas(tamanho+1);
		for (ll i=1; i<=tamanho; i++) cin >> contas[i];

		vector<Node> BITS(tamanho*4+1);
		build(BITS, contas, 1, tamanho, 1);

		ll qtdConsultas;
		cin >> qtdConsultas;

		for (ll j=0; j<qtdConsultas; j++) {
			ll l, r;
			cin >> l >> r;

			results.push_back(query(BITS, 1, tamanho, l, r, 1).maxSum);
		}
	}

	for (auto r : results) cout << r.first << " " << r.second << endl;
}
