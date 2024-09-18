#include <bits/stdc++.h>

#define ll long long
#define pls pair<ll, string>

using namespace std;


int main() {
	ll qtdOperacoes;
	cin >> qtdOperacoes;

	deque<pls> estudantes;

	for (ll i=0; i<qtdOperacoes; i++) {
		int operacao;
		cin >> operacao;

		pls estudante;
		switch(operacao) {
			case 1:
				cin >> estudante.first >> estudante.second;
				estudantes.push_front(estudante);

				break;
			case 2:
				cin >> estudante.first >> estudante.second;
				estudantes.push_back(estudante);

				break;
			case 3:
				if (estudantes.empty()) {
					cout << "0 0" << endl;
					break;
				}

				cout << estudantes.front().first << " " << estudantes.front().second << endl;
				estudantes.pop_front();

				break;
			case 4:
				if (estudantes.empty()) {
					cout << "0 0" << endl;
					break;
				}

				cout << estudantes.back().first << " " << estudantes.back().second << endl;
				estudantes.pop_back();

				break;
		}
	}
}
