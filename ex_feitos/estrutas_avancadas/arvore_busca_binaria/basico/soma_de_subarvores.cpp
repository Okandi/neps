#include <bits/stdc++.h>

#define ll long long

using namespace std;


void buildTree(queue<int>& ordem, vector<pair<int, int>>& arvore, int& slot, ll& total, int camada, int l, int r) {
	if (!(l <= ordem.front() && ordem.front() <= r)) return;
	if (slot == 0) {
		slot = ordem.front();
		ordem.pop();
		total += camada;
		cout << total << endl;
	}
	if (ordem.front() < slot) buildTree(ordem, arvore, arvore[slot].first, total, camada+1, l, slot-1);
	else buildTree(ordem, arvore, arvore[slot].second, total, camada+1, slot+1, r);
}


int main() {
	int tamanho;
	cin >> tamanho;

	queue<int> ordem;
	vector<int> Vordem(tamanho);
	vector<pair<int, int>> arvore(tamanho+1);

	for (int i=0; i<tamanho; i++) {
		int val;
		cin >> val;
		ordem.push(val);
		Vordem[i] = val;
	}

	int root = ordem.front();

	ll total = 0;
	while (!ordem.empty()) buildTree(ordem, arvore, arvore[0].first, total, 1, 1, tamanho);
}
