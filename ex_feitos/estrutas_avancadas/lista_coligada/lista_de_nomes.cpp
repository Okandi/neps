#include <bits/stdc++.h>

#define str string
#define pss pair<str, str>

using namespace std;


int main() {
	int qtdNomes, qtdOperacoes;
	cin >> qtdNomes >> qtdOperacoes;

	map<str, pss> nomes;

	str lastName = "";
	for (int i=0; i<qtdNomes; i++) {
		str nome;
		cin >> nome;

		nomes[nome] = {lastName, "0"};
		if (lastName != "") nomes[lastName].second = nome;
		lastName = nome;
	}

	for (int i=0; i<qtdOperacoes; i++) {
		int operacao;
		cin >> operacao;

		str nome1, nome2;
		switch (operacao) {
			case 1:
				cin >> nome1 >> nome2;
				if (nomes[nome1].first != "") nomes[nomes[nome1].first].second = nomes[nome1].second;
				if (nomes[nome1].second != "0") nomes[nomes[nome1].second].first = nomes[nome1].first;

				if (nomes[nome2].second != "0") nomes[nomes[nome2].second].first = nome1;

				nomes[nome1].second = nomes[nome2].second;
				nomes[nome1].first = nome2;
				nomes[nome2].second = nome1;

				break;
			case 2:
				cin >> nome1;
				cout << nomes[nome1].second << endl;

				break;
		}
	}

	str primeiro;
	for (map<str, pss>::iterator it = nomes.begin(); it!=nomes.end(); it++) {
		if (it->second.first == "") {
			primeiro = it->first;
			break;
		}
	}

	cout << primeiro << " ";
	for (int i=0; i<nomes.size()-1; i++) {
		cout << nomes[primeiro].second << " ";
		primeiro = nomes[primeiro].second;
	}
	cout << endl;
}
