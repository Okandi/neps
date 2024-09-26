#include <bits/stdc++.h>

#define ll long long
#define v vector

using namespace std;


ll getSum(v<v<v<ll>>> &BITS, ll x, ll y, ll z) {
	ll sum = 0;
	for (ll i=x; i>0; i -= i&-i)
		for (ll j=y; j>0; j -= j&-j)
			for (ll k=z; k>0; k -= k&-k)
				sum += BITS[i][j][k];
	return sum;
}


void update(v<v<v<ll>>> &BITS, ll valor, ll x, ll y, ll z) {
	if (x == 0 || y == 0 || z == 0) return;
	for (ll i=x; i<BITS.size(); i += i&-i)
		for (ll j=y; j<BITS.size(); j += j&-j)
			for (ll k=z; k<BITS.size(); k += k&-k)
				BITS[i][j][k] += valor;
}


int main() {
	ll dimensao, qtdOperacoes;
	cin >> dimensao >> qtdOperacoes;

	v<v<v<ll>>> BITS(dimensao+1, v<v<ll>>(dimensao+1, v<ll>(dimensao+1)));

	v<ll> results;
	for (ll i=0; i<qtdOperacoes; i++) {
		int operacao;
		cin >> operacao;

		switch (operacao) {
			case 1:
				ll x, y, z, valor;
				cin >> x >> y >> z >> valor;
				update(BITS, valor, x, y, z);
				break;
			case 2:
				ll x1, y1, z1, x2, y2, z2;
				cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
				results.push_back(
					getSum(BITS, x2, y2, z2)
					- getSum(BITS, x1-1, y2, z2) - getSum(BITS, x2, y1-1, z2) - getSum(BITS, x2, y2, z1-1)
					+ getSum(BITS, x1-1, y1-1, z2) + getSum(BITS, x1-1, y2, z1-1) + getSum(BITS, x2, y1-1, z1-1)
					- getSum(BITS, x1-1, y1-1, z1-1)
				);
				break;
		}
	}

	for (auto r : results) cout << r << endl;
}
