#include <bits/stdc++.h>

#define INF 99999999999999999
#define ll long long

using namespace std;


struct Ponto {

	ll x, y;

	Ponto (ll x, ll y) : x(x), y(y) {};

	Ponto operator - (Ponto ponto) const {
		return Ponto(this->x-ponto.x, this->y-ponto.y);
	}

	ll operator * (Ponto ponto) const {
		return this->x*ponto.y - this->y*ponto.x;
	}

	ll operator % (Ponto ponto) const {
		return this->x*ponto.x+this->y*ponto.y;
	}

	bool operator < (Ponto ponto) const {
		if ((*this)*ponto != 0) return (*this)*ponto > 0;
		return (*this)%(*this) < ponto%ponto;
	}
};

bool counterClockwise(Ponto a, Ponto b) {
	return a*b > 0;
}


int main() {
	int qtdPontos;
	cin >> qtdPontos;

	vector<Ponto> pontos;

	Ponto lowestPoint(INF, INF);
	for (int i=0; i<qtdPontos; i++) {
		ll x, y;
		cin >> x >> y;

		if (y < lowestPoint.y || (y == lowestPoint.y && x < lowestPoint.x)) {
			lowestPoint.y = y;
			lowestPoint.x = x;
		}

		pontos.push_back(Ponto(x, y));
	}

	for (int i=0; i<qtdPontos; i++) pontos[i] = pontos[i] - lowestPoint;

	sort(pontos.begin(), pontos.end());

	vector<Ponto> hull;
	for (int i=0; i<qtdPontos; i++) {
		while (hull.size()>=2 && !counterClockwise(hull[hull.size()-1]-hull[hull.size()-2], pontos[i]-hull[hull.size()-2])) {
			hull.pop_back();
		}

		hull.push_back(pontos[i]);
	}

	cout << hull.size() << endl;
	for (Ponto ponto : hull) cout << ponto.x+lowestPoint.x << " " << ponto.y+lowestPoint.y << endl;
}
