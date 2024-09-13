#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll prodVetorial(pair<ll, ll>& V, pair<ll, ll>& A, pair<ll, ll>& B) {
	return (A.first-V.first)*(B.second-V.second)-(A.second-V.second)*(B.first-V.first);
}


bool clockwise(pair<ll, ll>& V, pair<ll, ll>& A, pair<ll, ll>& B) {
	return prodVetorial(V, A, B) < 0;
}

bool counterClockwise(pair<ll, ll>& V, pair<ll, ll>& A, pair<ll, ll>& B) {
	return prodVetorial(V, A, B) > 0;
}


int main() {
	ll qtdPontos;
	cin >> qtdPontos;

	vector<pair<ll, ll>> pontos(qtdPontos);

	for (ll i=0; i<qtdPontos; i++) {
		ll x, y;
		cin >> x >> y;
		pontos[i] = {x, y};
	}

	sort(pontos.begin(), pontos.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
		return make_pair(a.first, b.second) < make_pair(b.first, a.second);
	});

	vector<pair<ll, ll>> upperHull;
	for (ll i=0; i<qtdPontos; i++) {
		auto ponto = pontos[i];
		while (upperHull.size() >= 2) {
			if (clockwise(upperHull[upperHull.size()-2], upperHull[upperHull.size()-1], ponto)) break;
			upperHull.pop_back();
		}
		upperHull.push_back(ponto);
	}

	vector<pair<ll, ll>> lowerHull;
	for (ll i=0; i<qtdPontos; i++) {
		auto ponto = pontos[i];
		while (lowerHull.size() >= 2) {
			if (counterClockwise(lowerHull[lowerHull.size()-2], lowerHull[lowerHull.size()-1], ponto)) break;
			lowerHull.pop_back();
		}
		lowerHull.push_back(ponto);
	}

	cout << upperHull.size() + lowerHull.size() - 2 << endl;

	for (ll i=upperHull.size()-1; i>=0; i--) {
		cout << upperHull[i].first << " " << upperHull[i].second << endl;
	}

	for (ll i=1; i<lowerHull.size()-1; i++) {
		cout << lowerHull[i].first << " " << lowerHull[i].second << endl;
	}
}
