#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>

using namespace std;


double dist(pll a, pll b) {
	return sqrt(pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}


int main() {
	pll a, b, c;
	cin >> a.first >> a.second;
	cin >> b.first >> b.second;
	cin >> c.first >> c.second;

	double da = dist(c, a);
	double db = dist(a, b);
	double dc = dist(b, c);

	double p = (da+db+dc)/2;
	cout << (ll)round(sqrt(p*(p-da)*(p-db)*(p-dc))) << endl;
}
