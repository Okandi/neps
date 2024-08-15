#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdPalavrasDicionario, qtdPalavrasTestes;
    cin >> qtdPalavrasDicionario >> qtdPalavrasTestes;

    string dicionario[qtdPalavrasDicionario];
    for (int i=0; i<qtdPalavrasDicionario; i++) cin >> dicionario[i];

    vector<vector<string>> respostas;
    for (int i=0; i<qtdPalavrasTestes; i++) {
        string palavraTeste;
        cin >> palavraTeste;

        vector<string> palavrasPossiveis;
        for (int j = 0; j<qtdPalavrasDicionario; j++) {
            string palavraDicionario = dicionario[j];

            int maiorSubsequencia[palavraDicionario.size()+1][palavraTeste.size()+1] = {};

            for (int oDicionario = 1; oDicionario <= palavraDicionario.size(); oDicionario++) {
                for (int oTeste = 1; oTeste <= palavraTeste.size(); oTeste++) {
                    if (palavraDicionario[oDicionario-1] == palavraTeste[oTeste-1]) {
                        maiorSubsequencia[oDicionario][oTeste] = maiorSubsequencia[oDicionario-1][oTeste-1] + 1;
                    } else {
                        maiorSubsequencia[oDicionario][oTeste] = max(maiorSubsequencia[oDicionario][oTeste-1], maiorSubsequencia[oDicionario-1][oTeste]);
                    }
                }
            }

            int erros = (
                abs((int)palavraDicionario.size() - maiorSubsequencia[palavraDicionario.size()][palavraTeste.size()])
                + abs((int)palavraTeste.size() - maiorSubsequencia[palavraDicionario.size()][palavraTeste.size()])
            );

            if (erros <= 2) palavrasPossiveis.push_back(palavraDicionario);
        }

        respostas.push_back(palavrasPossiveis);
    }

    for (vector<string> palavrasPossiveis : respostas) {
        for (string palavra : palavrasPossiveis) {
            cout << palavra << " ";
        }
        cout << endl;
    }
}
