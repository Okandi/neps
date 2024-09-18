#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	ll tamanho, qtdConsultas;
	cin >> tamanho >> qtdConsultas;

	vector<vector<ll>> matriz(tamanho+1); // instancia um vetor custa O(n) (n sendo o tamanho dele) -> cada casa reservada precisa da incialização de um objetivo do tipo especificado, então ao inicializar os vetores dentro da matriz, estava custando O(n²), o que não é desejável, bizarro =O :: NÃO EXISTE MAGIA!
	vector<ll> expoentes(tamanho+1);
	vector<ll> potenciasDeDois; // parando para pensar, não acho que precisava

	ll tempExpo = 0;
	for (ll t = 1; t <= tamanho; tempExpo++) {
		t = (1<<tempExpo);
		potenciasDeDois.push_back(t);
	}

	for (ll t = 0; potenciasDeDois[t] <= tamanho; t++)
		for (ll i = potenciasDeDois[t]; i<potenciasDeDois[t+1] && i<=tamanho; i++)
			expoentes[i] = t;

	for (ll i = 1; i <= tamanho; i++) {
		ll value;
		cin >> value;
		matriz[i].push_back(value);
	}

	for (ll k=1; potenciasDeDois[k] <= tamanho; k++) {
		for (ll l = 1; l + potenciasDeDois[k]-1 <= tamanho; l++) {
			ll mid = l + potenciasDeDois[k-1];
			matriz[l].push_back(max(matriz[l][k-1], matriz[mid][k-1]));
		}
	}

	ll l, r;
	vector<ll> respostas;
	for (ll i=0; i<qtdConsultas; i++) {
		cin >> l >> r;

		ll t = expoentes[r-l+1];

		respostas.push_back(max(matriz[l][t], matriz[r-potenciasDeDois[t]+1][t]));
	}

	for (auto r : respostas) cout << r << endl;
}
