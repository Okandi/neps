#include <bits/stdc++.h>

#define ll long long

using namespace std;


double dist(pair<ll, ll> ponto1, pair<ll, ll> ponto2) {
	return sqrt(pow(ponto1.first-ponto2.first, 2) + pow(ponto1.second-ponto2.second, 2));
}


int main() {
	ll qtdPontos;
	cin >> qtdPontos;

	vector<pair<ll, ll>> pontos(qtdPontos); // {x, y}

	for (ll i=0; i<qtdPontos; i++) {
		ll x, y;
		cin >> x >> y;
		pontos[i] = {x, y};
	}

	sort(pontos.begin(), pontos.end());

	set<pair<ll, ll>> pontosAtivos; // {y, i}

	ll firstActive = 0;
	double answer = dist(pontos[0], pontos[1]);

	for (ll i=0; i<qtdPontos; i++) {
		while (pontos[i].first - pontos[firstActive].first > floor(answer)) {
			pontosAtivos.erase({pontos[firstActive].second, firstActive});
			firstActive++;
		}

		for (auto it = pontosAtivos.lower_bound({pontos[i].second-floor(answer), 0}); it != pontosAtivos.end() && it->first <= pontos[i].second + floor(answer); it++) {
			answer = min(dist(pontos[i], pontos[it->second]), answer);
		}

		pontosAtivos.insert({pontos[i].second, i});
	}

	cout.precision(7);
	cout << answer << endl;
}
