#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	ll numero;
	cin >> numero;

	priority_queue<ll, vector<ll>, greater<ll>> divisores;

	for (ll x=1; x<=numero/x; x++) {
		if (!(numero%x)) {
			divisores.push(x);
			if (!(numero/x == x)) divisores.push(numero/x);
		}
	}

	while (!divisores.empty()) {
		cout << divisores.top() << " ";
		divisores.pop();
	}

	cout << endl;
}
