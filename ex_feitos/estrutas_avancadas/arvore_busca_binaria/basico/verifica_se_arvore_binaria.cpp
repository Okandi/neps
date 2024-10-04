#include <bits/stdc++.h>

using namespace std;


bool verifyBinaryTree(vector<pair<int, pair<int, int>>>& arvore, int node, int l, int r) {
	if (node == 0) return true;

	bool isBinary = l <= node && node < r;

	return isBinary
		&& verifyBinaryTree(arvore, arvore[node].second.first, l, node)
		&& verifyBinaryTree(arvore, arvore[node].second.second, node+1, r);
}


int main() {
	int qtdTestes;
	cin >> qtdTestes;

	vector<bool> results;
	for (int i=0; i<qtdTestes; i++) {
		int qtdNos;
		cin >> qtdNos;

		vector<pair<int, pair<int, int>>> arvore(qtdNos+1);

		for (int i=1; i<=qtdNos; i++) {
			int left, right;
			cin >> left >> right;

			arvore[i].second.first = left;
			arvore[i].second.second = right;

			arvore[left].first = i;
			arvore[right].first = i;
		}

		int root = 0;
		for (int i=1; i<=qtdNos; i++) {
			if (arvore[i].first == 0) {
				root = i;
				break;
			}
		}

		results.push_back(verifyBinaryTree(arvore, root, 1, qtdNos+1));
	}

	for (auto r : results) cout << r << endl;
}
