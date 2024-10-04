#include <bits/stdc++.h>

using namespace std;


void buildTree(vector<pair<int, int>>& arvore, queue<int>& preOrdem, int& slot, int l, int r) {
	if (!(l <= preOrdem.front() && preOrdem.front() <= r)) return;
	slot = preOrdem.front();
	preOrdem.pop();

	buildTree(arvore, preOrdem, arvore[slot].first, l, slot-1);
	buildTree(arvore, preOrdem, arvore[slot].second, slot+1, r);
}


int main() {
	int tamanho;
	cin >> tamanho;

	vector<pair<int, int>> arvore(tamanho+1);

	queue<int> preOrdem;

	for (int i=1; i<=tamanho; i++) {
		int val;
		cin >> val;

		preOrdem.push(val);
	}

	buildTree(arvore, preOrdem, arvore[0].first, 1, tamanho);

	for (int i=1; i<=tamanho; i++) cout << arvore[i].first << " " << arvore[i].second << endl;
}
