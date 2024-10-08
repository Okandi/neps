#include <bits/stdc++.h>

#define INF 1e9

using namespace std;


template <typename T> class RBTree;


template <typename T> class Node {
public:
	T key;
	bool isNull;

private:
	friend class RBTree<T>;

	bool isBlack;
	Node<T> *parent, *left, *right;

	Node<T>(T key = T()) : key(key), isBlack(false), isNull(false) {}

	bool isLeft() {
		return this->parent->key > this->key;
	}

	Node<T> *sibling() {
		if (this->isLeft()) return this->parent->right;
		return this->parent->left;
	}
};


template <typename T> class RBTree {
public:
	RBTree() {
		null = createNode();
		null->isNull = true;

		root = null;
		size = 0;
	}

	int getSize() {
		return size;
	}

	void insert(T value) {
		if (verifyIfExists(value, root)) return;

		Node<T> *newNode = createNode(value);

		root = placeNode(root, newNode);

		fixInsert(newNode);

		size++;
	}

	bool verifyIfExists(T val, Node<T> *node) {
		if (node == null) return false;
		if (node->key == val) return true;
		if (node->key > val) return verifyIfExists(val, node->left);
		return verifyIfExists(val, node->right);
	}

	Node<T> *minimum(Node<T> *node) {
		if (node == null) return null;
		else if (node->left == null) return node;
		return minimum(node->left);
	}

	Node<T> *maximum(Node<T> *node) {
		if (node == null) return null;
		else if (node->right == null) return node;
		return maximum(node->right);
	}

private:

	Node<T> *null, *root;
	int size;


	Node<T> *createNode(T value = T()) {
		Node<T> *newNode = new Node<T>(value);
		newNode->parent = newNode->left = newNode->right = null;
		return newNode;
	}


	Node<T> *placeNode(Node<T> *node, Node<T> *newNode) {
		if (node == null) node = newNode;
		else {
			if (node->key > newNode->key) {
				node->left = placeNode(node->left, newNode);
				node->left->parent = node;
			} else {
				node->right = placeNode(node->right, newNode);
				node->right->parent = node;
			}
		}
		return node;
	}

	void fixInsert(Node<T> *node) {
		if (node == root) {
			node->isBlack = true;
			return;
		}

		Node<T> *P = node->parent, *G = P->parent, *U = P->sibling();

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

	void leftRotate(Node<T> *node) {
		Node<T> *newHigher = node->right;
		node->right = newHigher->left;
		newHigher->left = node;

		if (node->right != null) node->right->parent = node;

		if (node->parent == null) root = newHigher;
		else if (node->isLeft()) node->parent->left = newHigher;
		else node->parent->right = newHigher;

		newHigher->parent = node->parent;
		node->parent = newHigher;
	}

	void rightRotate(Node<T> *node) {
		Node<T> *newHigher = node->left;
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
	int qtdAlunos;
	cin >> qtdAlunos;

	RBTree<int> *listaPresenca = new RBTree<int>();

	for (int i=0; i<qtdAlunos; i++) {
		int aluno;
		cin >> aluno;
		listaPresenca->insert(aluno);
	}

	cout << listaPresenca->getSize() << endl;
}
