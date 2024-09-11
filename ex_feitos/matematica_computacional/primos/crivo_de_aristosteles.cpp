#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	ll n;
	cin >> n;

	vector<ll> numeros(n+1);
	for (ll i=1; i<=n; i++) numeros[i] = i;

	for (ll x = 2; x<=n; x++) {
		if (numeros[x] != x) continue;
		cout << x << " ";
		for (ll i=2*x; i <= n; i+=x) numeros[i] = min(numeros[i], x);
	}

	cout << endl;
}
