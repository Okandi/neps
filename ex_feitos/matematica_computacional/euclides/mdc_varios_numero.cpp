#include <bits/stdc++.h>

using namespace std;


int mdc(int a, int b) { // O(log(a) + log(b))
	if (a == 0) return b;
	return mdc(b%a, a);
}


int main() {
	int qtdNumeros;
	cin >> qtdNumeros;

	vector<int> numeros(qtdNumeros);

	for (int i=0; i<qtdNumeros; i++) cin >> numeros[i];

	int resposta = numeros[0];

	for (int i=1; i<qtdNumeros; i++) {
		resposta = mdc(resposta, numeros[i]);
	}

	cout << resposta << endl;
}
