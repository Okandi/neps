#include <bits/stdc++.h>

#define INF 1e9

using namespace std;


class Node {
public:

	int key;
	bool isBlack;
	Node *parent, *left, *right;

	Node(int key) : key(key), isBlack(false) {}

	bool isLeft() {
		return this->parent->key > this->key;
	}

	Node *sibling() {
		if (this->isLeft()) return this->parent->right;
		return this->parent->left;
	}

};


class RBTree {
public:
	Node *null;
	Node *root;

	RBTree() {
		null = new Node(-INF);
		root = null->parent = null->left = null->right = null;
	}

	void insert(int value) {
		if (verifyIfExists(value, root)) return;

		Node* newNode = new Node(value);
		newNode->parent = newNode->left = newNode->right = null;

		root = placeNode(root, newNode);

		fixInsert(newNode);
	}

	bool verifyIfExists(int val, Node *node) {
		if (node == null) return false;
		if (node->key == val) return true;
		if (node->key > val) return verifyIfExists(val, node->left);
		return verifyIfExists(val, node->right);
	}

	Node *minimum(Node *node) {
		if (node == null) return null;
		else if (node->left == null) return node;
		return minimum(node->left);
	}

	Node *maximum(Node *node) {
		if (node == null) return null;
		else if (node->right == null) return node;
		return maximum(node->right);
	}

private:

	Node *placeNode(Node *T, Node *newNode) {
		if (T == null) T = newNode;
		else {
			if (T->key > newNode->key) {
				T->left = placeNode(T->left, newNode);
				T->left->parent = T;
			} else {
				T->right = placeNode(T->right, newNode);
				T->right->parent = T;
			}
		}
		return T;
	}

	void fixInsert(Node *node) {
		if (node == root) {
			node->isBlack = true;
			return;
		}

		Node *P = node->parent, *G = P->parent, *U = P->sibling();

		if (P->isBlack) return;

		if (!U->isBlack) {
			P->isBlack = U->isBlack = true;
			G->isBlack = false;

			fixInsert(G);

			return;
		}

		if (P->isLeft() == node->isLeft()) {
			G->isBlack = false;
			P->isBlack = true;

			if (P->isLeft()) rightRotate(G);
			else leftRotate(G);

			return;
		}

		if (P->isLeft()) leftRotate(P);
		else rightRotate(P);
		fixInsert(P);
	}

	void leftRotate(Node *node) {
		Node *newHigher = node->right;
		node->right = newHigher->left;
		newHigher->left = node;

		if (node->right != null) node->right->parent = node;

		if (node->parent == null) root = newHigher;
		else if (node->isLeft()) node->parent->left = newHigher;
		else node->parent->right = newHigher;

		newHigher->parent = node->parent;
		node->parent = newHigher;
	}

	void rightRotate(Node *node) {
		Node *newHigher = node->left;
		node->left = newHigher->right;
		newHigher->right = node;

		if (node->left != null) node->left->parent = node;

		if (node->parent == null) root = newHigher;
		else if (node->isLeft()) node->parent->left = newHigher;
		else node->parent->right = newHigher;

		newHigher->parent = node->parent;
		node->parent = newHigher;
	}

};


int main() {
	int qtdOperacoes;
	cin >> qtdOperacoes;

	RBTree *arvore = new RBTree();

	vector<int> results;
	for (int i=0; i<qtdOperacoes; i++) {
		int operacao, val;
		cin >> operacao;

		switch (operacao) {
			case 1:
				cin >> val;
				arvore->insert(val);
				break;
			case 2:
				cin >> val;
				results.push_back(arvore->verifyIfExists(val, arvore->root));
				break;
			case 3:
				results.push_back(arvore->minimum(arvore->root)->key);
				break;
			case 4:
				results.push_back(arvore->maximum(arvore->root)->key);
				break;
		}
	}

	for (auto r : results) {
		if (r == -INF) cout << "-" << endl;
		else cout << r << endl;
	}
}
