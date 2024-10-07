#include <bits/stdc++.h>

using namespace std;


struct Node {

	bool isBlack;
	int value, left, right;

	Node(int value = 0, bool isBlack = true) : value(value), isBlack(isBlack), left(0), right(0) {}

};


bool verifyFirstRule(vector<Node>& arvore, int root) {
	return arvore[root].isBlack;
}


bool verifySecondRule(vector<Node>& arvore, int node) {
	bool isRBTree;

	if (node == 0) return true;
	else if (arvore[node].isBlack) isRBTree = true;
	else isRBTree = arvore[arvore[node].left].isBlack && arvore[arvore[node].right].isBlack;

	return isRBTree
		&& verifySecondRule(arvore, arvore[node].left)
		&& verifySecondRule(arvore, arvore[node].right);
}


bool verifyBlackHeight(vector<Node>& arvore, int node, int blackHeight, int blackHeightTarget) {
	if (node == 0) return blackHeight == blackHeightTarget;
	if (arvore[node].isBlack) blackHeight++;
	return verifyBlackHeight(arvore, arvore[node].left, blackHeight, blackHeightTarget)
		&& verifyBlackHeight(arvore, arvore[node].right, blackHeight, blackHeightTarget);
}


bool verifyThirdRule(vector<Node>& arvore, int root) {
	int node = root;
	int blackHeight = 0;
	while (node != 0) {
		if (arvore[node].isBlack) blackHeight++;
		node = arvore[node].left;
	}
	return verifyBlackHeight(arvore, root, 0, blackHeight);
}


int main() {
	int qtdTestes;
	cin >> qtdTestes;

	vector<int> results;

	for (int k=0; k<qtdTestes; k++) {
		int qtdNos;
		cin >> qtdNos;

		vector<Node> arvore(qtdNos+1);

		set<int> childNodes;

		for (int i=1; i<=qtdNos; i++) {
			int left, right; bool isBlack;
			cin >> left >> right >> isBlack;

			Node newNode = Node(i, isBlack);

			newNode.left = left;
			newNode.right = right;

			childNodes.insert(left);
			childNodes.insert(right);

			arvore[i] = newNode;
		}

		int root = 0;

		auto it = childNodes.begin();
		it++;

		for (int i=1; i<=qtdNos; i++) {
			if (it != childNodes.end() && *it == i) it++;
			else {
				if (!root) root = i;
				else {
					root = 0;
					break;
				}
			}
		}

		if (!root) {
			results.push_back(0);
			continue;
		}

		results.push_back(
			verifyFirstRule(arvore, root)
			&& verifySecondRule(arvore, root)
			&& verifyThirdRule(arvore, root)
		);
	}

	for (auto r : results) cout << r << endl;
}
