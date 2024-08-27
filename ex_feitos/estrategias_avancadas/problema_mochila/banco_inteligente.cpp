#include <bits/stdc++.h>

using namespace std;

int main() {
	int valorSaque;
	cin >> valorSaque;

	vector<int> valorNotas = {2, 5, 10, 20, 50, 100};

	vector<int> notas(6);
	for (int i=0; i<6; i++) cin >> notas[i];

	vector<vector<int>> dp(6+1, vector<int>(valorSaque+1, 0));
	dp[0][0] = 1;
	for (int i=1; i<=6; i++) { // O(6*~k*valorSaque)
		int valorNota = valorNotas[i-1];
		for (int k=0; k<=notas[i-1]; k++) { // +- O(n²)
			for (int j=valorSaque-k*valorNota; j>=0; j--) {
				dp[i][j+k*valorNota] += dp[i-1][j];
			}
		}
	}

	cout << dp[6][valorSaque] << endl;
}
