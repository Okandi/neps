#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	ll dimensao, qtdConsultas;
	cin >> dimensao >> qtdConsultas;

	vector<vector<ll>> psm(dimensao+1, vector<ll>(dimensao+1));

	for (ll i=1; i<=dimensao; i++) {
		for (ll j=1; j<=dimensao; j++) {
			ll val;
			cin >> val;

			psm[i][j] = psm[i-1][j] + psm[i][j-1] - psm[i-1][j-1] + val;
		}
	}

	vector<ll> results;
	for (ll i=0; i<qtdConsultas; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		results.push_back(psm[x2][y2] - psm[x2][y1-1] - psm[x1-1][y2] + psm[x1-1][y1-1]);
	}

	for (auto r : results) cout << r << endl;
}
