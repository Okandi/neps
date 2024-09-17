#include <bits/stdc++.h>

#define INF 9999999999999999
#define ll long long

using namespace std;


struct Ponto {

	ll x, y;

	Ponto (ll x, ll y) : x(x), y(y) {};

	Ponto operator - (Ponto p) const {
		return Ponto(this->x-p.x, this->y-p.y);
	}

	Ponto operator + (Ponto p) const {
		return Ponto(this->x+p.x, this->y+p.y);
	}

	ll operator * (Ponto p) const {
		return this->x*p.y - this->y*p.x;
	}

	ll operator % (Ponto p) const {
		return this->x*p.x + this->y*p.y;
	}

	ll operator < (Ponto p) const {
		if ((*this)*p != 0) return (*this)*p < 0;
		return (*this)%(*this) < p%p;
	}

};



vector<Ponto> getConvexHull(int qtdCertas) {
	Ponto lowest(INF, INF);
	vector<Ponto> ovelhas;
	for (int i=0; i<qtdCertas; i++) {
		ll x, y;
		cin >> x >> y;
		if (y < lowest.y || (y == lowest.y && x < lowest.x)) {
			lowest.y = y;
			lowest.x = x;
		}
		ovelhas.push_back(Ponto(x, y));
	}

	for (int i=0; i<qtdCertas; i++) ovelhas[i] = ovelhas[i] - lowest;

	sort(ovelhas.begin(), ovelhas.end());

	vector<Ponto> hull;
	for (int i=0; i<qtdCertas; i++) {
		while (hull.size() > 1 && (hull[hull.size()-1]-hull[hull.size()-2])*(ovelhas[i]-hull[hull.size()-2]) >= 0) hull.pop_back();
		hull.push_back(ovelhas[i]);
	}

	for (int i=0; i<hull.size(); i++) hull[i] = hull[i] + lowest;

	return hull;
}



int findRegion(vector<Ponto> &cerco, Ponto &ovelha, ll lowestY, ll highestY, ll lowestX, ll highestX) {
	if (
		(cerco[1]-cerco[0])*(ovelha-cerco[0]) > 0
		|| (cerco[cerco.size()-1]-cerco[0])*(ovelha-cerco[0]) < 0
		|| ovelha.y > highestY || ovelha.y < lowestY
		|| ovelha.x > highestX || ovelha.x < lowestX
	) return 0;

	int l = 1, r = cerco.size()-1;

	while (l<r) {
		int m = (l+r)/2;
		if (l == r-1) m = r;

		if ((cerco[m]-cerco[0])*(ovelha-cerco[0]) >= 0) r = m-1;
		else l = m;
	}

	return r;
}



int main() {
	int qtdCertas, qtdDuvidas;
	cin >> qtdCertas >> qtdDuvidas;

	vector<Ponto> cerco = getConvexHull(qtdCertas);

	ll lowestX = INF;
	ll lowestY = INF;
	ll highestY = -INF;
	ll highestX = -INF;

	for (auto ponto : cerco) {
		if (ponto.x < lowestX) lowestX = ponto.x;
		if (ponto.y < lowestY) lowestY = ponto.y;
		if (ponto.x > highestX) highestX = ponto.x;
		if (ponto.y > highestY) highestY = ponto.y;
	}

	vector<Ponto> ovelhas;
	for (int i=0; i<qtdDuvidas; i++) {
		ll x, y;
		cin >> x >> y;
		ovelhas.push_back(Ponto(x, y));
	}

	int total = 0;
	for (auto ovelha : ovelhas) {
		int region = findRegion(cerco, ovelha, lowestY, highestY, lowestX, highestX);
		if (region == 0) continue;
		if (cerco.size() == 2 || (cerco[1+region]-cerco[region])*(ovelha-cerco[region]) <= 0) total++;
	}

	cout << total << endl;
}
