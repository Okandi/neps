#include <bits/stdc++.h>

#define v vector
#define ll long long

using namespace std;


int main() {
	ll dimensao, qtdConsultas;
	cin >> dimensao >> qtdConsultas;

	v<v<v<ll>>> psm(dimensao+1, v<v<ll>>(dimensao+1, v<ll>(dimensao+1)));

	for (ll x=1; x<=dimensao; x++) {
		for (ll y=1; y<=dimensao; y++) {
			for (ll z=1; z<=dimensao; z++) {
				ll val;
				cin >> val;
				psm[x][y][z] =
					val
					+ psm[x-1][y][z] + psm[x][y-1][z] + psm[x][y][z-1]
					- psm[x-1][y-1][z] - psm[x-1][y][z-1] - psm[x][y-1][z-1]
					+ psm[x-1][y-1][z-1];
			}
		}
	}

	v<ll> results;
	for (ll i=0; i<qtdConsultas; i++) {
		ll x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;

		results.push_back(
			psm[x2][y2][z2]
			- psm[x1-1][y2][z2] - psm[x2][y1-1][z2] - psm[x2][y2][z1-1]
			+ psm[x1-1][y1-1][z2] + psm[x1-1][y2][z1-1] + psm[x2][y1-1][z1-1]
			- psm[x1-1][y1-1][z1-1]
		);
	}

	for (auto r : results) cout << r << endl;
}
