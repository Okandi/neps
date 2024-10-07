#include <bits/stdc++.h>

using namespace std;


struct Node {
	int left, right, father;
	Node(int left=0, int right=0, int father=0) : left(left), right(right), father(father) {}
};


void rightRotate(vector<Node>& arvore, int no) {
	int temp = arvore[no].left;
	arvore[no].left = arvore[temp].right;
	arvore[temp].right = no;

	arvore[arvore[no].left].father = no;

	if (arvore[no].father > temp) arvore[arvore[no].father].left = temp;
	else arvore[arvore[no].father].right = temp;

	arvore[temp].father = arvore[no].father;
	arvore[no].father = temp;
}


void leftRotate(vector<Node>& arvore, int no) {
	int temp = arvore[no].right;
	arvore[no].right = arvore[temp].left;
	arvore[temp].left = no;

	arvore[arvore[no].right].father = no;

	if (arvore[no].father > no) arvore[arvore[no].father].left = temp;
	else arvore[arvore[no].father].right = temp;

	arvore[temp].father = arvore[no].father;
	arvore[no].father = temp;
}


int main() {
	int qtdNos, qtdOperacoes;
	cin >> qtdNos >> qtdOperacoes;

	vector<Node> nos(qtdNos+1);

	for (int i=1; i<=qtdNos; i++) {
		cin >> nos[i].left >> nos[i].right;
		nos[nos[i].left].father = i;
		nos[nos[i].right].father = i;
	}

	for (int i=0; i<qtdOperacoes; i++) {
		char operacao; int no;
		cin >> operacao >> no;
		switch (operacao) {
			case 'L':
				leftRotate(nos, no);
				break;
			case 'R':
				rightRotate(nos, no);
				break;
		}
	}

	for (int i=1; i<=qtdNos; i++) cout << nos[i].left << " " << nos[i].right << endl;
}
