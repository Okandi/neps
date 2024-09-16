#include <bits/stdc++.h>

#define ll long long
#define INF 999999999

using namespace std;


struct Ponto {
	ll x, y;

	Ponto (ll x, ll y) : x(x), y(y) {};

	Ponto operator - (Ponto ponto) const {
		return Ponto(this->x-ponto.x, this->y-ponto.y);
	}

	ll operator % (Ponto ponto) const {
		return this->x*ponto.x + this->y*ponto.y;
	}

	ll operator * (Ponto ponto) const {
		return this->x*ponto.y - this->y*ponto.x;
	}

	bool operator < (Ponto ponto) const {
		return make_pair(this->x, this->y) < make_pair(ponto.x, ponto.y);
	}

	bool operator == (Ponto ponto) const {
		return make_pair(this->x, this->y) == make_pair(ponto.x, ponto.y);
	}
};


int whichSide(Ponto ponto) {
	return !(ponto.y > 0 || (ponto.y == 0 && ponto.x >= 0));
}


int main() {
	int qtdMoedas;
	cin >> qtdMoedas;

	vector<pair<Ponto, ll>> moedas;

	for (int i=0; i<qtdMoedas; i++) {
		ll x, y, v;
		cin >> x >> y >> v;

		moedas.push_back({Ponto(x, y), v});
	}

	vector<pair<Ponto, ll>> refList = moedas;

	ll answer = -INF;
	for (auto referencia : refList) {
		sort(moedas.begin(), moedas.end(), [referencia](pair<Ponto, ll> moeda1, pair<Ponto, ll> moeda2) {
			if (whichSide(moeda1.first-referencia.first) != whichSide(moeda2.first-referencia.first)) return whichSide(moeda1.first-referencia.first) < whichSide(moeda2.first-referencia.first);
			else if ((moeda1.first-referencia.first) * (moeda2.first-referencia.first) != 0) return (moeda1.first-referencia.first) * (moeda2.first-referencia.first) > 0;
			return ((moeda1.first-referencia.first) % (moeda1.first-referencia.first)) < ((moeda2.first-referencia.first) % (moeda2.first-referencia.first));
		});

		ll currentAnswer = -INF;
		for (int i=1; i<qtdMoedas; i++) {
			ll currentSum = moedas[0].second + moedas[i].second;
			currentAnswer = max(currentAnswer, currentSum);
			while (i<qtdMoedas-1 && (moedas[i].first-referencia.first)*(moedas[i+1].first-referencia.first) == 0) {
				currentSum += moedas[i+1].second;
				currentAnswer = max(currentAnswer, currentSum);
				i++;
			}
		}
		answer = max(currentAnswer, answer);
	}

	cout << answer << endl;
}
