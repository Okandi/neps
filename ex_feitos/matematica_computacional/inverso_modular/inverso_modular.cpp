#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll fastExponenciation(ll val, ll e, ll mod) {
	if (e == 0) return 1%mod;
	ll res = fastExponenciation(val, e/2, mod);
	res = (res*res)%mod;
	if (e%2) res = (res*val)%mod;
	return res;
}


int main() {
	ll a, m;
	cin >> a >> m;

	ll res = fastExponenciation(a, m-2, m);

	if ((a*res)%m != 1) cout << -1 << endl;
	else cout << res << endl;
}
