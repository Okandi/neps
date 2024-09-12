#include <bits/stdc++.h>

using namespace std;


int main() {
	pair<double, double> A, B, P;

	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> P.first >> P.second;

	cout << (
		abs((P.first-A.first)*(B.second-A.second)-(P.second-A.second)*(B.first-A.first))/sqrt(pow(A.first-B.first, 2) + pow(A.second-B.second, 2))
	) << endl;
}
