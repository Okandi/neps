#include <bits/stdc++.h>

#define ll long long
#define v vector
#define INF 1e+18

using namespace std;


struct Node {

	ll maxVal;

	Node(ll maxVal=-INF) : maxVal(maxVal) {}

	Node operator + (Node other) {
		return Node(max(this->maxVal, other.maxVal));
	}

};


v<v<Node>> TREE;
ll n, m;



void buildY(v<v<ll>> &valores, ll nodex, ll lx, ll rx, ll nodey, ll ly, ll ry) {
	if (ly == ry) {
		if (lx == rx) TREE[nodex][nodey].maxVal = valores[lx][ly];
		else TREE[nodex][nodey] = TREE[nodex*2][nodey] + TREE[nodex*2+1][nodey];
		return;
	}

	ll meio = (ly+ry)/2;

	buildY(valores, nodex, lx, rx, nodey*2, ly, meio);
	buildY(valores, nodex, lx, rx, nodey*2+1, meio+1, ry);

	TREE[nodex][nodey] = TREE[nodex][nodey*2] + TREE[nodex][nodey*2+1];
}

void buildX(v<v<ll>> &valores, ll nodex, ll lx, ll rx) {
	if (lx == rx) {
		buildY(valores, nodex, lx, rx, 1, 1, m);
		return;
	}

	ll meio = (lx+rx)/2;

	buildX(valores, nodex*2, lx, meio);
	buildX(valores, nodex*2+1, meio+1, rx);

	buildY(valores, nodex, lx, rx, 1, 1, m);
}



void updateY(ll nodex, ll lx, ll rx, ll nodey, ll ly, ll ry, ll idy, ll value) {
	if (ly == ry) {
		if (lx == rx) TREE[nodex][nodey].maxVal = value;
		else TREE[nodex][nodey] = TREE[nodex*2][nodey] + TREE[nodex*2+1][nodey];
		return;
	}

	ll meio = (ly+ry)/2;

	if (idy <= meio) updateY(nodex, lx, rx, nodey*2, ly, meio, idy, value);
	else updateY(nodex, lx, rx, nodey*2+1, meio+1, ry, idy, value);

	TREE[nodex][nodey] = TREE[nodex][nodey*2] + TREE[nodex][nodey*2+1];
}

void updateX(ll nodex, ll lx, ll rx, ll idx, ll idy, ll value) {
	if (lx == rx) {
		updateY(nodex, lx, rx, 1, 1, m, idy, value);
		return;
	}

	ll meio = (lx+rx)/2;

	if (idx <= meio) updateX(nodex*2, lx, meio, idx, idy, value);
	else updateX(nodex*2+1, meio+1, rx, idx, idy, value);

	updateY(nodex, lx, rx, 1, 1, m, idy, value);
}



Node queryY(ll nodex, ll nodey, ll ly, ll ry, ll py, ll qy) {
	if (qy < ly || ry < py) return Node();
	if (py <= ly && ry <= qy) return TREE[nodex][nodey];

	ll meio = (ly+ry)/2;

	return queryY(nodex, nodey*2, ly, meio, py, qy) + queryY(nodex, nodey*2+1, meio+1, ry, py, qy);
}

Node queryX(ll nodex, ll lx, ll rx, ll px, ll qx, ll py, ll qy) {
	if (qx < lx || rx < px) return Node();
	if (px <= lx && rx <= qx) return queryY(nodex, 1, 1, m, py, qy);

	ll meio = (lx+rx)/2;

	return queryX(nodex*2, lx, meio, px, qx, py, qy) + queryX(nodex*2+1, meio+1, rx, px, qx, py, qy);
}



int main() {
	ll qtdOperacoes;
	cin >> n >> m >> qtdOperacoes;

	v<v<ll>> valores(n+1, v<ll>(m+1));

	for (ll i=1; i<=n; i++)
		for (ll j=1; j<=m; j++)
			cin >> valores[i][j];


	TREE = v<v<Node>>(n*4+1, v<Node>(m*4+1));
	buildX(valores, 1, 1, n);

	v<ll> results;
	for (ll i=0; i<qtdOperacoes; i++) {
		int operacao;
		cin >> operacao;

		switch (operacao) {
			case 1:
				ll x, y, val;
				cin >> x >> y >> val;

				updateX(1, 1, n, x, y, val);

				break;
			case 2:
				ll x1, y1, x2, y2;
				cin >> x1 >> y1 >> x2 >> y2;

				results.push_back(queryX(1, 1, n, x1, x2, y1, y2).maxVal);
				break;
		}
	}

	for (auto r : results) cout << r << endl;
}
