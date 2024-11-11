#include <bits/stdc++.h>

using namespace std;

#define INF 1e9+1


enum Color {
	RED,
	BLACK,
	DOUBLE_BLACK
};


template <typename T> class RBTree;


template <typename T> class Node {

private:

	friend class RBTree<T>;

	T key;
	Color color;
	Node<T> *parent, *left, *right;

	Node<T>(T key) : key(key), color(RED) {};

	bool isLeft() {
		return parent->left == this;
	}

	Node<T> *sibling() {
		if (isLeft()) return parent->right;
		return parent->left;
	}

};


template <typename T> class RBTree {

public:

	RBTree(T defaultValue) {
		null = (Node<T> *)malloc(sizeof(Node<T>));
		*null = *createNode(defaultValue);

		root = null;
		size = 0;
	}

	int getSize() {
		return size;
	}

	T minimum() {
		return minimum(root)->key;
	}

	T secondMinimum() {
		Node<T> *node = minimum(root);
		if (node->right == null) return node->parent->key;
		return minimum(node->right)->key;
	}

	T maximum() {
		return maximum(root)->key;
	}

	T secondMaximum() {
		Node<T> *node = maximum(root);
		if (node->left == null) return node->parent->key;
		return maximum(node->left)->key;
	}

	bool isIn(T value) {
		return find(root, value) != null;
	}

	void insert(T value) {
		if (isIn(value)) return;
		Node<T> *newNode = createNode(value);
		insert(newNode);
		size++;
	}

	void remove(T value) {
		Node<T> *nodeToRemove = find(root, value);
		if (nodeToRemove == null) return;
		remove(nodeToRemove);
		size--;
	}

private:

	Node<T> *null, *root;
	int size;


	Node<T> *createNode(T value) {
		Node<T> *newNode = new Node<T>(value);
		newNode->parent = newNode->left = newNode->right = null;
		return newNode;
	}


	Node<T> *minimum(Node<T> *node) {
		while (node->left != null) node = node->left;
		return node;
	}


	Node<T> *maximum(Node<T> *node) {
		while (node->right != null) node = node->right;
		return node;
	}


	Node<T> *find(Node<T> *node, T value) {
		if (node->key == value || node == null) return node;
		else if (node->key > value) return find(node->left, value);
		else return find(node->right, value);
	}


	void insert(Node<T> *newNode) {
		placeNode(root, newNode);
		fixInsert(newNode);
	}

	void placeNode(Node<T> *&node, Node<T>* newNode) {
		if (node == null) node = newNode;
		else {
			if (node->key > newNode->key) {
				placeNode(node->left, newNode);
				node->left->parent = node;
			} else {
				placeNode(node->right, newNode);
				node->right->parent = node;
			}
		}
	}

	void fixInsert(Node<T> *nodeToFix) {
		while (true) {
			if (nodeToFix == root) {
				nodeToFix->color = BLACK;
				return;
			}

			Node<T> *P = nodeToFix->parent, *G = P->parent, *U = P->sibling();

			if (P->color = BLACK) return;

			if (U->color == RED) {
				P->color = U->color = BLACK;
				G->color = RED;
				nodeToFix = G;
			} else if (P->isLeft() == nodeToFix->isLeft()) {
				G->color = RED;
				P->color = BLACK;
				if (P->isLeft()) rightRotate(G);
				else leftRotate(G);
				return;
			} else {
				if (P->isLeft()) leftRotate(P);
				else rightRotate(P);
				nodeToFix = P;
			}
		}
	}


	void remove(Node<T> *node) {
		if (node->left != null && node->right != null) {
			Node<T> *minimumRightNode = minimum(node->right);
			T key = minimumRightNode->key;
			remove(minimumRightNode);
			node->key = key;
		} else {
			Node<T> *childNode = (node->left == null) ? node->right : node->left;
			if (node != root) {
				if (node->isLeft()) node->parent->left = childNode;
				else node->parent->right = childNode;
			} else root = childNode;
			childNode->parent = node->parent;
			childNode->color = mergeColor(childNode->color, node->color);
			delete node;
			fixRemoval(childNode);
		}
	}

	void fixRemoval(Node<T> *nodeToFix) {
		while (true) {
			if (nodeToFix->color != DOUBLE_BLACK) return;
			if (nodeToFix == root) {
				nodeToFix->color = BLACK;
				return;
			}

			Node<T> *P = nodeToFix->parent, *S = nodeToFix->sibling();
			Node<T> *L = S->left, *R = S->right;

			if (getColor(S) == RED) {
				S->color = P->color = BLACK;
				if (nodeToFix->isLeft()) leftRotate(P);
				else rightRotate(P);
			} else if (getColor(L) == BLACK && getColor(R) == BLACK) {
				nodeToFix->color = BLACK;
				S->color = RED;
				P->color = mergeColor(P->color, BLACK);
				nodeToFix = P;
			} else if (nodeToFix->isLeft()) {
				if (getColor(L) == RED && getColor(R) == BLACK) {
					S->color = RED;
					L->color = BLACK;
					rightRotate(S);
				} else {
					S->color = P->color;
					P->color = R->color = nodeToFix->color = BLACK;
					leftRotate(P);
					return;
				}
			} else {
				if (getColor(R) == RED && getColor(L) == BLACK) {
					S->color = RED;
					R->color = BLACK;
					leftRotate(S);
				} else {
					S->color = P->color;
					P->color = L->color = nodeToFix->color = BLACK;
					rightRotate(P);
					return;
				}
			}
		}
	}

	Color mergeColor(Color color1, Color color2) {
		if (color1 == color2) {
			if (color1 == RED) return RED;
			else return DOUBLE_BLACK;
		}
		return BLACK;
	}

	Color getColor(Node<T> *node) {
		if (node == null) return BLACK;
		return node->color;
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
	int qtdOperacoes;
	cin >> qtdOperacoes;

	RBTree<int> arvore = RBTree<int>(INF);

	vector<int> results;
	for (int i=0; i<qtdOperacoes; i++) {
		int operacao, valor;
		cin >> operacao;

		switch (operacao) {
			case 1:
				cin >> valor;
				arvore.insert(valor);
				break;
			case 2:
				cin >> valor;
				arvore.remove(valor);
				break;
			case 3:
				cin >> valor;
				results.push_back(arvore.isIn(valor));
				break;
			case 4:
				results.push_back(arvore.getSize());
				break;
			case 5:
				results.push_back(arvore.minimum());
				break;
			case 6:
				results.push_back(arvore.secondMinimum());
				break;
			case 7:
				results.push_back(arvore.maximum());
				break;
			case 8:
				results.push_back(arvore.secondMaximum());
				break;
		}
	}

	for (auto r : results) {
		if (r == INF) cout << '-' << endl;
		else cout << r << endl;
	}
}
