#include <bits/stdc++.h>

#define ll long long
#define INF 999999999999999

using namespace std;


void mergeSort(vector<ll> &vetor, ll &total) {
	if (vetor.size() == 1) return;

	ll meio = vetor.size()/2;
	vector<ll> vetor1;
	vector<ll> vetor2;


	for (int i=0; i<meio; i++) vetor1.push_back(vetor[i]);
	for (int i=meio; i<vetor.size(); i++) vetor2.push_back(vetor[i]);

	mergeSort(vetor1, total);
	mergeSort(vetor2, total);

	vetor1.push_back(INF);
	vetor2.push_back(INF);

	ll i=0, j=0;
	for (ll k=0; k<vetor.size(); k++) {
		if (vetor1[i] <= vetor2[j]) {
			vetor[k] = vetor1[i];
			i++;
		}
		else {
			vetor[k] = vetor2[j];
			j++;
			total += vetor1.size()-i-1;
		}
	}
};


int main() {
	int tamanho;
	cin >> tamanho;

	vector<ll> pregos(tamanho+1, 0);
	for (ll i=1; i<=tamanho; i++) cin >> pregos[i];

	ll total = 0;

	mergeSort(pregos, total);

	cout << total << endl;
}
