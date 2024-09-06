#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll mdc(ll a, ll b, ll& x, ll& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}

	ll x1, y1;
	ll g = mdc(b%a, a, x1, y1);

	x = y1-b/a*x1;
	y = x1;

	return g;
}


bool solver(ll a, ll b, ll c, ll& x, ll& y) {
	ll g = mdc(abs(a), abs(b), x, y);

	if (c%g != 0) return false;

	ll t = c/g;

	x = x * t * abs(a)/a;
	y = y * t * abs(b)/b;

	return true;
}


int main() {
	ll a, b, c, x, y;
	cin >> a >> b >> c;

	if (solver(a, b, c, x, y)) cout << 1 << endl << x << " " << y << endl;
	else cout << -1 << endl;
}
