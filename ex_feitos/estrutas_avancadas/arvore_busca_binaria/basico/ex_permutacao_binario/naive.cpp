#include <bits/stdc++.h>

#define ll long long
#define MOD 1e9+7

using namespace std;


struct Node {

	int value, height;
	Node* father;
	Node* left;
	Node* right;

	Node(int value) : value(value), height(height), father(NULL), left(NULL), right(NULL) {}

};


class Tree {

public:

	Node* root;
	int maxHeight = 0;
	vector<Node*> arvore;

	Tree() : root(NULL) {}

	void build(deque<int> valores, int totalSize) {
		arvore.resize(totalSize+1);

		root = new Node(1e5);
		arvore[0] = root;

		root->father = root;
		root->height = 0;
		maxHeight = 0;

		while (!valores.empty()) insertValues(valores, root);
	}

	void addValue(int value) {
		deque<int> valores = {value};
		insertValues(valores, root);
	}

	void removeValue(int value) {
		Node* node = arvore[value];
		Node* fatherNode = node->father;

		if (fatherNode->left == node) fatherNode->left = NULL;
		else fatherNode->right = NULL;

		arvore[value] = NULL;
		delete node;

		maxHeight = 0;

		queue<Node*> nodes;
		nodes.push(root);

		while (!nodes.empty()) {
			Node* currentNode = nodes.front();
			nodes.pop();

			if (currentNode == NULL) continue;

			maxHeight = max(maxHeight, currentNode->height);

			nodes.push(currentNode->left);
			nodes.push(currentNode->right);
		}
	}


private:

	void insertValues(deque<int>& valores, Node* node) {
		if (valores.empty()) return;
		if (valores.front() < node->value && node->left != NULL) insertValues(valores, node->left);
		else if (valores.front() > node->value && node->right != NULL) insertValues(valores, node->right);
		else {
			Node* newNode = new Node(valores.front());
			valores.pop_front();

			newNode->father = node;
			newNode->height = node->height+1;

			if (newNode->value < node->value) node->left = newNode;
			else node->right = newNode;

			arvore[newNode->value] = newNode;

			maxHeight = max(newNode->height, maxHeight);
		}
	}

};


void doPermutations(deque<int>& valores, Tree* arvore, int meta, int i, ll& total) {
	if (i == valores.size()) {
		if (arvore->maxHeight == meta) total = (total+1)%MOD;
	} else if (arvore->maxHeight <= meta) {
		for (int j=i; j<valores.size(); j++) {
			swap(valores[i], valores[j]);

			arvore->addValue(valores[i]);

			doPermutations(valores, arvore, meta, i+1, total);

			arvore->removeValue(valores[i]);

			swap(valores[i], valores[j]);
		}
	}
}


int main() {
	int tamanhoTotal, tamanhoInicial, alturaMeta;
	cin >> tamanhoTotal >> tamanhoInicial >> alturaMeta;

	deque<int> ordem(tamanhoInicial);

	for (int i=0; i<ordem.size(); i++) cin >> ordem[i];

	deque<int> ordemAdicionais;

	deque<int> tempSorted = ordem;

	sort(tempSorted.begin(), tempSorted.end());

	int j=0;
	for (int i=1; i<=tamanhoTotal; i++) {
		if (i == tempSorted[j]) {
			j++;
			continue;
		}
		ordemAdicionais.push_back(i);
	}

	Tree* arvore = new Tree();
	arvore->build(ordem, tamanhoTotal);

	ll total = 0;
	doPermutations(ordemAdicionais, arvore, alturaMeta, 0, total);

	cout << total << endl;
}
