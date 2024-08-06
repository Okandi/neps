#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdDoces;
    cin >> qtdDoces;

    priority_queue<int, vector<int>, greater<int>> qtdDocesParaEvoluir;
    for (int i=0; i<3; i++) {
        int qtd;
        cin >> qtd;
        qtdDocesParaEvoluir.push(qtd);
    }

    int qtdEvoluida = 0;
    while (!qtdDocesParaEvoluir.empty() && qtdDoces-qtdDocesParaEvoluir.top() >= 0) {
        qtdDoces -= qtdDocesParaEvoluir.top();
        qtdDocesParaEvoluir.pop();
        qtdEvoluida++;
    }

    cout << qtdEvoluida << endl;
}
