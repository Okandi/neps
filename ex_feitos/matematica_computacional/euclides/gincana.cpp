#include <bits/stdc++.h>

#define ll long long

using namespace std;


int mdc(ll a, ll b) { // O(log(a) + log(b))
	if (a == 0) return b;
	return mdc(b%a, a);
}


int main() {
	ll qtdRivais, qtdColegas;
	cin >> qtdRivais >> qtdColegas;

	while (mdc(qtdRivais, qtdColegas) != 1) qtdColegas--;

	cout << qtdColegas << endl;
}
