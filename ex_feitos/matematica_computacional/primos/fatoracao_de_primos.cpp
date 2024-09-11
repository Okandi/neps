#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	ll numero;
	cin >> numero;

	vector<ll> fatores;

	ll fator = 2;
	while (numero != 1) {
		if (!(numero%fator)) {
			numero /= fator;
			fatores.push_back(fator);
		} else fator++;
	}

	cout << fatores.size() << endl;
	for (auto fator : fatores) cout << fator << " ";
	cout << endl;
}
