#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll fastMult(ll x, ll y, ll m) {
	if (x == 0 || y == 0) return 0;
	if (x == 1) return y%m;
	if (y == 1) return x%m;

	return (fastMult(x/2, y, m)*2%m + (x%2)*y)%m;
}


int main() {
	ll x, y, m;
	cin >> x >> y >> m;

	cout << fastMult(x, y, m) << endl;
}
