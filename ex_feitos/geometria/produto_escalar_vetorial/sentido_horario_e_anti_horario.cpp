#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	pair<ll, ll> V, A, B;
	cin >> V.first >> V.second;
	cin >> A.first >> A.second;
	cin >> B.first >> B.second;

	if ((A.first - V.first) * (B.second - V.second) - (A.second - V.second) * (B.first - V.first) > 0) cout << 1 << endl;
	else cout << -1 << endl;
}
