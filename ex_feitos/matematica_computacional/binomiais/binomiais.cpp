#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	ll n, k, m;
	cin >> n >> k >> m;

	if (n < k) {
		cout << 0 << endl;
		return 0;
	}

	vector<ll> fatorial(n+1);
	vector<ll> inv(n+1), fatorialInv(n+1);

	fatorial[0] = inv[0] = fatorialInv[0] = 1;
	fatorial[1] = inv[1] = fatorialInv[1] = 1;

	for (ll i=2; i<=n; i++) {
		fatorial[i] = (fatorial[i-1] * i)%m;
		inv[i] = (-(m/i)*inv[m%i])%m;
		if (inv[i] < 0) inv[i] += m;
		fatorialInv[i] = (fatorialInv[i-1]*inv[i])%m;
	}

	cout << (((fatorial[n] * fatorialInv[n-k])%m) * fatorialInv[k])%m << endl;
}
