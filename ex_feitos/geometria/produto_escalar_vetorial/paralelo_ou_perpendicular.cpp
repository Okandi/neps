#include <bits/stdc++.h>

using namespace std;


int main() {
	long long ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;

	if (ax*bx+ay*by == 0) cout << -1 << endl;
	else if (ax*by-ay*bx == 0) cout << 1 << endl;
	else cout << 0;
}
