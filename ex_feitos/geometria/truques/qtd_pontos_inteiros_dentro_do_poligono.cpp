#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>

using namespace std;


ll gdc(ll a, ll b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gdc(b%a, a);
}


int main() {
	ll qtdPontos;
	cin >> qtdPontos;

	vector<pll> pontos;
	for (ll i=0; i<qtdPontos; i++) {
		pll ponto;
		cin >> ponto.first >> ponto.second;
		pontos.push_back(ponto);
	}

	pontos.push_back(pontos[0]);
	ll area = 0;
	ll qtdPontosNaReta = 0;
	for (ll i=1; i<pontos.size(); i++) {
		area += (pontos[i].second+pontos[i-1].second)*(pontos[i].first-pontos[i-1].first);
		qtdPontosNaReta += gdc(abs(pontos[i].first-pontos[i-1].first), abs(pontos[i].second-pontos[i-1].second));
	}

	area = abs(area)/2;

	cout << area-qtdPontosNaReta/2+1 << endl;
}
