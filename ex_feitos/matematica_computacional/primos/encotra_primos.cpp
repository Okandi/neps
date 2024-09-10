#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	ll numero;
	cin >> numero;

	bool primo = true;
	for (ll i=2; i*i<=numero && primo; i++) {
		if (!(numero%i)) primo = false;
	}
	if (primo && numero != 1) cout << "S" << endl;
	else cout << "N" << endl;
}
