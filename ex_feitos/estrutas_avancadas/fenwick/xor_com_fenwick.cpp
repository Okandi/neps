#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll getXor(ll index, vector<ll> &bits) {
	ll res = 0;
	for (ll j=index; j>0; j -= j & -j) {
		res ^= bits[j];
	}
	return res;
}


ll getAnsw(ll index, vector<ll> &valores, vector<ll> &bitsI, vector<ll> &bitsP) {
	if (index&1) return valores[index]^getXor(ceil((double)index/2.), bitsI)^getXor(ceil((double)(index-1)/2.), bitsP);
	return valores[index]^getXor(ceil((double)index/2.), bitsP)^getXor(ceil((double)(index-1)/2.), bitsI);
}


void update(ll index, ll val, vector<ll> &bits) {
	for (ll j=index; j<bits.size(); j += j & -j) {
		bits[j] ^= val;
	}
}


void updateS(ll index, ll val, vector<ll> &bitsI, vector<ll> &bitsP) {
	if (index&1) update(ceil((double)index/2.), val, bitsI);
	else update(ceil((double)index/2.), val, bitsP);
}


int main() {
	ll tamanho, qtdOperacoes;
	cin >> tamanho >> qtdOperacoes;

	vector<ll> valores(tamanho+1, 0);
	vector<ll> bitsP(ceil((double)tamanho/2.)+1, 0);
	vector<ll> bitsI(ceil((double)tamanho/2.)+1, 0);

	for (int i=1; i<=tamanho; i++) cin >> valores[i];

	vector<ll> results;
	for (int i=0; i<qtdOperacoes; i++) {
		int operacao;
		cin >> operacao;

		switch (operacao) {
			case 1:
				ll left, right, val;
				cin >> left >> right >> val;
				updateS(left, val, bitsI, bitsP);
				updateS(right+1, val, bitsI, bitsP);

				break;
			case 2:
				ll index;
				cin >> index;
				results.push_back(getAnsw(index, valores, bitsI, bitsP));

				break;
		}
	}

	for (auto r : results) cout << r << endl;
}
