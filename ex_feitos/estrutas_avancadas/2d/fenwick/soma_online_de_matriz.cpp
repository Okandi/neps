#include <bits/stdc++.h>

#define ll long long
#define v vector

using namespace std;


void update(v<v<ll>> &BITS, ll x, ll y, ll val) {
	if (x == 0 || y == 0) return;
	for (ll i=x; i<BITS.size(); i += i & -i)
		for (ll j=y; j<BITS[i].size(); j += j & -j)
			BITS[i][j] += val;
}


ll getSum(v<v<ll>> &BITS, ll x, ll y) {
	ll sum = 0;
	for (ll i=x; i>0; i -= i & -i)
		for (ll j=y; j>0; j -= j & -j)
			sum += BITS[i][j];
	return sum;
}



int main() {
	ll dimensao, qtdConsultas;
	cin >> dimensao >> qtdConsultas;

	v<v<ll>> BITS(dimensao+1, v<ll>(dimensao+1));

	for (ll x=1; x<=dimensao; x++) {
		for (ll y=1; y<=dimensao; y++) {
			ll val;
			cin >> val;
			update(BITS, x, y, val);
		}
	}

	v<ll> results;
	for (ll i=0; i<qtdConsultas; i++) {
		int consulta;
		cin >> consulta;

		ll x1, y1;
		cin >> x1 >> y1;

		switch (consulta) {
			case 1:
				ll val;
				cin >> val;
				val -= getSum(BITS, x1, y1) - getSum(BITS, x1-1, y1) - getSum(BITS, x1, y1-1) + getSum(BITS, x1-1, y1-1);

				update(BITS, x1, y1, val);
				break;
			case 2:
				ll x2, y2;
				cin >> x2 >> y2;

				results.push_back(
					getSum(BITS, x2, y2)
					- getSum(BITS, x2, y1-1) - getSum(BITS, x1-1, y2)
					+ getSum(BITS, x1-1, y1-1)
				);
				break;
		}
	}

	for (auto r : results) cout << r << endl;
}
