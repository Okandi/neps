#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll fastExpo(ll b, ll e, ll m) {
	if (e == 0) return 1;

	ll answer = fastExpo(b, e/2, m);

	answer = (answer * answer)%m;

	if (e%2) answer = (answer * b)%m;

	return answer%m;
}


int main() {
	ll b, e, m;
	cin >> b >> e >> m;

	cout << fastExpo(b, e, m) << endl;
}
