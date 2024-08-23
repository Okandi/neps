#include <bits/stdc++.h>

#define ll long long
#define INF 999999999999

using namespace std;


vector<int> getSubSeq(vector<ll> &sequencia) {
	vector<ll> dp(sequencia.size()+1, INF);
	dp[0] = -INF;
	vector<int> maxLISPerLen(sequencia.size());

	for (int i=1; i<=sequencia.size(); i++) { // O(n*log(n))
		int p = lower_bound(dp.begin(), dp.end(), sequencia[i-1]) - dp.begin(); // O(log(n))
		dp[p] = sequencia[i-1];
		maxLISPerLen[i-1] = p;
	}

	return maxLISPerLen;
}


int main() {
	int tamanho;
	cin >> tamanho;

	vector<ll> sequencia(tamanho);
	for (int i=0; i<tamanho; i++) cin >> sequencia[i];

	auto ondaIndo = getSubSeq(sequencia);

	reverse(sequencia.begin(), sequencia.end());

	auto ondaVoltando = getSubSeq(sequencia);

	reverse(ondaVoltando.begin(), ondaVoltando.end());

	int res = 0;
	for (int i=0; i<tamanho; i++) if (ondaIndo[i] == ondaVoltando[i]) res = max(res, 2*ondaIndo[i]-1);

	cout << res << endl;
}
