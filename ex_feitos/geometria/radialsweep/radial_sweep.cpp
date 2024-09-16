#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll prodEscalar(pair<ll, ll> &ponto1, pair<ll, ll> &ponto2) {
	return ponto1.first*ponto2.first + ponto1.second*ponto2.second;
}

ll prodVetorial(pair<ll, ll> &ponto1, pair<ll, ll> &ponto2) {
	return ponto1.first*ponto2.second-ponto1.second*ponto2.first;
}

int whichSide(pair<ll, ll> &ponto) {
	return !(ponto.second>0 || (ponto.second==0 && ponto.first>=0));
}

bool radialOrder(pair<ll, ll> ponto1, pair<ll, ll> ponto2) {
	if (whichSide(ponto1) != whichSide(ponto2)) return whichSide(ponto1) < whichSide(ponto2);
	else if (prodVetorial(ponto1, ponto2) != 0) return prodVetorial(ponto1, ponto2) > 0;
	return prodEscalar(ponto1, ponto1) < prodEscalar(ponto2, ponto2);
}

int main() {
	ll qtdPontos;
	cin >> qtdPontos;

	set<pair<ll, ll>, decltype(radialOrder)*> pontos(radialOrder);

	for (ll i=0; i<qtdPontos; i++) {
		ll x, y;
		cin >> x >> y;
		pontos.insert({x, y});
	}

	for (auto it = pontos.begin(); it != pontos.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}
