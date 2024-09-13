#include <bits/stdc++.h>

#define ll long long

using namespace std;


struct Evento {

	ll x, lowerY, upperY, id;
	bool entrada;

	Evento (ll x, ll lowerY, ll upperY, bool entrada, ll id) : x(x), lowerY(lowerY), upperY(upperY), entrada(entrada), id(id) {}

	bool operator < (Evento evento) const {
		return x < evento.x;
	}

};



int main() {
	ll qtdSalas;
	cin >> qtdSalas;

	vector<Evento> eventos;
	set<pair<pair<ll, ll>, ll>> eventosAtivos;
	vector<int> posicaoWifis(qtdSalas, 0);

	for (ll i=0; i<qtdSalas; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		Evento entrada(x1, y2, y1, true, i);
		Evento saida(x2, y2, y1, false, i);

		eventos.push_back(entrada);
		eventos.push_back(saida);
	}

	sort(eventos.begin(), eventos.end());

	for (ll i=0; i<eventos.size(); i++) {
		Evento eventoAtual = eventos[i];
		if (eventoAtual.entrada) {
			auto eventoAtivo = eventosAtivos.upper_bound({{eventoAtual.upperY, eventoAtual.lowerY}, eventoAtual.id});
			if (eventoAtivo != eventosAtivos.end() && eventoAtual.upperY < eventoAtivo->first.first && eventoAtual.lowerY > eventoAtivo->first.second) {
				posicaoWifis[eventoAtivo->second] = 0;
			}
			eventosAtivos.insert({{eventoAtual.upperY, eventoAtual.lowerY}, eventoAtual.id});
			posicaoWifis[eventoAtual.id] = 1;
		} else eventosAtivos.erase({{eventoAtual.upperY, eventoAtual.lowerY}, eventoAtual.id});
	}

	cout << reduce(posicaoWifis.begin(), posicaoWifis.end()) << endl;
}
