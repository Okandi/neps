#include <bits/stdc++.h>

#define ll long long
#define pll pair<pair<ll, ll>, pair<ll, ll>>
#define f first
#define s second

using namespace std;


ll getSum(ll index, vector<ll> &BITS) {
	ll total = 0;
	for (ll i=index; i>0; i-=i&-i)
		total += BITS[i];
	return total;
}


void update(ll index, vector<ll> &BITS) {
	if (!index) return;
	for (ll i=index; i<BITS.size(); i+=i&-i)
		BITS[i] += 1;
}


void handleEvent(pll &evento, vector<ll> &BITS, vector<ll> &results) {
	if (!evento.s.f) update(evento.f.s, BITS);
	else results[evento.f.s] = getSum(evento.s.s, BITS) - getSum(evento.s.f-1, BITS);
}


int main() {
	ll tamanho, qtdConsultas;
	cin >> tamanho >> qtdConsultas;

	vector<pll> eventos;
	for (ll i=1; i<=tamanho; i++) {
		ll val;
		cin >> val;
		eventos.push_back(make_pair(make_pair(val, i), make_pair(0, 0)));
	}

	for (ll i=0; i<qtdConsultas; i++) {
		ll l, r, x;
		cin >> l >> r >> x;
		eventos.push_back(make_pair(make_pair(x, i), make_pair(l, r)));
	}


	vector<ll> BITS(tamanho+1, 0);


	sort(eventos.begin(), eventos.end(), [](pll a, pll b) {
		return make_pair(a.f.f, a.s.f) < make_pair(b.f.f, b.s.f);
	});


	vector<ll> results(qtdConsultas);
	for (ll i=eventos.size()-1; i>=0; i--) {
		handleEvent(eventos[i], BITS, results);
	}

	for (auto r : results) cout << r << endl;
}
