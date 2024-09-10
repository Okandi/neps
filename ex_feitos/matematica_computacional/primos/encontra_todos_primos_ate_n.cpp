#include <bits/stdc++.h>

using namespace std;


int main() {
	int maximoNumero;
	cin >> maximoNumero;

	int i=2;
	vector<int> primos;

	while (i<=maximoNumero) {
		bool primo = true;
		for (int nPrimo : primos) {
			if (i%nPrimo == 0) {
				primo = false;
				break;
			}
		}

		if (primo) primos.push_back(i);
		i++;
	}

	for (int primo : primos) cout << primo << " ";
	cout << endl;
}
