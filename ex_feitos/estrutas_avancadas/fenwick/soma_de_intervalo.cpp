#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll getSum(ll i, vector<ll> &BITS) {
	ll sum = 0;
	for (int j = i; j>0; j -= j & -j) {
		sum += BITS[j];
	}
	return sum;
}


void update(ll i, ll newV, vector<ll> &BITS) {
	for (ll j=i; j<BITS.size(); j += j & -j) {
		BITS[j] += newV;
	}
}


int main() {
	ll tamanho, qtdOperacoes;
	cin >> tamanho >> qtdOperacoes;

	vector<ll> BITS(tamanho+1, 0);
	vector<ll> values(tamanho+1, 0);

	for (int i=1; i<=tamanho; i++) {
		cin >> values[i];
		update(i, values[i], BITS);
	}

	vector<ll> respostas;
	for (int i=0; i<qtdOperacoes; i++) {
		int operacao;
		cin >> operacao;

		switch(operacao) {
			case 1:
				ll index, valor;
				cin >> index >> valor;
				update(index, valor-values[index], BITS);
				values[index] = valor;

				break;
			case 2:
				ll left, right;
				cin >> left >> right;
				respostas.push_back(getSum(right, BITS) - getSum(left-1, BITS));

				break;
		}
	}

	for (auto r : respostas) cout << r << endl;
}
