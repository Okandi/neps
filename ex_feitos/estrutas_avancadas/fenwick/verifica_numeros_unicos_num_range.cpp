#include <bits/stdc++.h>

#define ll long long
#define pll pair<pair<ll, ll>, pair<ll, ll>>
#define f first
#define s second
#define INF 1e+15

using namespace std;


ll getSum(ll index, vector<ll> &BITS) {
	ll sum = 0;
	for (ll i=index; i>0; i-=i&-i)
		sum += BITS[i];
	return sum;
}


void update(ll index, vector<ll> &BITS) {
	if (index == 0) return;
	for (ll i=index; i<BITS.size(); i+=i&-i)
		BITS[i]++;
}


int main() {
	ll tamanho, qtdConsultas;
	cin >> tamanho >> qtdConsultas;

	vector<ll> valores(tamanho+1);
	for (ll i=1; i<=tamanho; i++) cin >> valores[i];

	vector<ll> lastIndexes(3e+5+1, 0);
	for (ll i=valores.size()-1; i>0; i--) {
		ll valor = valores[i];
		if (!lastIndexes[valor]) valores[i] = INF;
		else valores[i] = lastIndexes[valor];
		lastIndexes[valor] = i;
	}

	vector<pll> eventos;
	for (ll i=1; i<=valores.size()-1; i++) {
		eventos.push_back({{valores[i], i}, {0, 0}});
	}

	for (ll i=0; i<qtdConsultas; i++) {
		ll l, r;
		cin >> l >> r;
		eventos.push_back({{r, i}, {l, r}});
	}

	sort(eventos.begin(), eventos.end(), [](pll a, pll b) {
		return make_pair(a.f.f, a.s.s) > make_pair(b.f.f, b.s.s);
	});


	vector<ll> BITS(tamanho+1, 0);


	vector<ll> results(qtdConsultas);
	for (ll i=0; i<eventos.size(); i++) {
		pll evento = eventos[i];
		if (evento.s.s != 0) results[evento.f.s] = getSum(evento.s.s, BITS) - getSum(evento.s.f-1, BITS);
		else update(evento.f.s, BITS);
	}

	for (auto r : results) cout << r << endl;
}
