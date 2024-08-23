#include <bits/stdc++.h>

using namespace std;


int main() {
	string sequencia;
	cin >> sequencia;

	vector<char> dp(sequencia.size()+1, (char)91);
	dp[0] = '.';

	int answ = 0;
	for (int i=1; i<=sequencia.size(); i++) { // O(n*log(n))
		int p = upper_bound(dp.begin(), dp.end(), sequencia[i-1])-dp.begin(); // O(log(n))
		dp[p] = sequencia[i-1];
		answ = max(p, answ);
	}

	cout << answ << endl;
}
