#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	ll qtdPontos;
	cin >> qtdPontos;

	vector<pair<ll, ll>> pontos;
	for (ll i=0; i<qtdPontos; i++) {
		pair<ll, ll> ponto;
		cin >> ponto.first >> ponto.second;
		pontos.push_back(ponto);
	}

	pontos.push_back(pontos[0]);

	ll res = 0;
	for (ll i=1; i<=qtdPontos; i++) {
		ll diffX = pontos[i-1].first - pontos[i].first;
		ll sumY = pontos[i-1].second + pontos[i].second;

		res += diffX*sumY;
	}

	cout << abs(res/2) << endl;
}
