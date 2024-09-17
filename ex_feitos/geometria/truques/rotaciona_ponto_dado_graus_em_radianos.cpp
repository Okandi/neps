#include <bits/stdc++.h>

using namespace std;


int main() {
	double x, y, t;
	cin >> x >> y >> t;

	cout << x*cos(t) - y*sin(t) << " " << x*sin(t) + y*cos(t) << endl;
}
