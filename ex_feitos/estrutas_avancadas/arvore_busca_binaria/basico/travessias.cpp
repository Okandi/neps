#include <bits/stdc++.h>

using namespace std;


void inOrdem(vector<pair<pair<int, int>, pair<int, int>>>& arvore, int node) {
	if (node == 0) return;

	inOrdem(arvore, arvore[node].second.first);
	cout << arvore[node].first.second << " ";
	inOrdem(arvore, arvore[node].second.second);
}


void preOrdem(vector<pair<pair<int, int>, pair<int, int>>>& arvore, int node) {
	if (node == 0) return;

	cout << arvore[node].first.second << " ";
	preOrdem(arvore, arvore[node].second.first);
	preOrdem(arvore, arvore[node].second.second);
}


void posOrdem(vector<pair<pair<int, int>, pair<int, int>>>& arvore, int node) {
	if (node == 0) return;

	posOrdem(arvore, arvore[node].second.first);
	posOrdem(arvore, arvore[node].second.second);
	cout << arvore[node].first.second << " ";
}


int main() {
	int qtdNos;
	cin >> qtdNos;

	vector<pair<pair<int, int>, pair<int, int>>> arvore(qtdNos+1);

	for (int i=1; i<=qtdNos; i++) cin >> arvore[i].first.second;

	for (int i=1; i<=qtdNos; i++) {
		int left, right;
		cin >> left >> right;

		arvore[i].second.first = left;
		arvore[i].second.second = right;

		arvore[left].first.first = i;
		arvore[right].first.first = i;
	}

	int root = 0;
	for (int i=1; i<=qtdNos; i++) {
		if (arvore[i].first.first == 0) {
			root = i;
			break;
		}
	}

	inOrdem(arvore, root);
	cout << endl;
	preOrdem(arvore, root);
	cout << endl;
	posOrdem(arvore, root);
	cout << endl;
}
