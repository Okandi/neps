#include <bits/stdc++.h>

using namespace std;


int main() { // FUNCIONA LOCAL, MAS NÃO NO NEPS >:( <sim, ta feio, eu sei>
    int qtdPalavrasDicionario, qtdPalavrasTestes;
    cin >> qtdPalavrasDicionario >> qtdPalavrasTestes;

    vector<string> palavrasDicionario;
    for (int i=0; i<qtdPalavrasDicionario; i++) {
        string palavraDicionario;
        cin >> palavraDicionario;
        palavrasDicionario.push_back(palavraDicionario);
    }

    vector<string> palavrasTeste;
    for (int i=0; i<qtdPalavrasTestes; i++) {
        string palavraTeste;
        cin >> palavraTeste;
        palavrasTeste.push_back(palavraTeste);
    }

    vector<vector<string>> respostas;
    for (string palavraTeste : palavrasTeste) {
        vector<string> possiveisCorrecoes;

        for (string palavraDicionario : palavrasDicionario) {
            int dp[palavraDicionario.size()+1][palavraTeste.size()+1] = {};

            for (int i=1; i <= palavraDicionario.size(); i++) {
                for (int j=1; j <= palavraTeste.size(); j++) {
                    if (palavraDicionario[i-1] == palavraTeste[j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }

            string interseccao = "";
            int i = palavraDicionario.size();
            int j = palavraTeste.size();
            while (i != 0 && j != 0) {
                if (palavraDicionario[i-1] == palavraTeste[j-1]) {
                    interseccao = palavraDicionario[i-1] + interseccao;
                    i--; j--;
                } else if (dp[i][j-1] >= dp[i-1][j]) {
                    j--;
                } else i--;
            }

            bool indiceDicionarioFazParteDaInterseccaoIndo[palavraDicionario.size()];
            fill(indiceDicionarioFazParteDaInterseccaoIndo, indiceDicionarioFazParteDaInterseccaoIndo+palavraDicionario.size(), false);
            i=0;
            int k=0;
            while (k<interseccao.size() && i<palavraDicionario.size()) {
                if (palavraDicionario[i] == interseccao[k]) {
                    indiceDicionarioFazParteDaInterseccaoIndo[i] = true;
                    k++;
                }
                i++;
            }

            bool indiceTesteFazParteDaInterseccaoIndo[palavraTeste.size()];
            fill(indiceTesteFazParteDaInterseccaoIndo, indiceTesteFazParteDaInterseccaoIndo+palavraDicionario.size(), false);
            j=0;
            k=0;
            while (k<interseccao.size() && j<palavraTeste.size()) {
                if (palavraTeste[j] == interseccao[k]) {
                    indiceTesteFazParteDaInterseccaoIndo[j] = true;
                    k++;
                }
                j++;
            }

            // for (bool val : indiceDicionarioFazParteDaInterseccaoIndo) cout << val << " ";
            // cout << endl;

            // for (bool val : indiceTesteFazParteDaInterseccaoIndo) cout << val << " ";
            // cout << endl;

            i=0; j=0;
            int qtdErroIndo = 0;
            while (i<palavraDicionario.size() && j<palavraTeste.size()) {
                if (indiceDicionarioFazParteDaInterseccaoIndo[i] == indiceTesteFazParteDaInterseccaoIndo[j]) {
                    if (!indiceDicionarioFazParteDaInterseccaoIndo[i]) qtdErroIndo++;
                    i++; j++;
                } else if (indiceDicionarioFazParteDaInterseccaoIndo[i] && !indiceTesteFazParteDaInterseccaoIndo[j]) {
                    qtdErroIndo++;
                    j++;
                } else {
                    qtdErroIndo++;
                    i++;
                }
            }
            qtdErroIndo += palavraDicionario.size()-i + palavraTeste.size()-j;


            bool indiceDicionarioFazParteDaInterseccaoVoltando[palavraDicionario.size()];
            fill(indiceDicionarioFazParteDaInterseccaoVoltando, indiceDicionarioFazParteDaInterseccaoVoltando+palavraDicionario.size(), false);
            i=palavraDicionario.size()-1;
            k=interseccao.size()-1;
            while (0<=k && 0<=i) {
                if (palavraDicionario[i] == interseccao[k]) {
                    indiceDicionarioFazParteDaInterseccaoVoltando[i] = true;
                    k--;
                }
                i--;
            }

            bool indiceTesteFazParteDaInterseccaoVoltando[palavraTeste.size()];
            fill(indiceTesteFazParteDaInterseccaoVoltando, indiceTesteFazParteDaInterseccaoVoltando+palavraDicionario.size(), false);
            j=palavraTeste.size()-1;
            k=interseccao.size()-1;
            while (0<=k && 0<=j) {
                if (palavraTeste[j] == interseccao[k]) {
                    indiceTesteFazParteDaInterseccaoVoltando[j] = true;
                    k--;
                }
                j--;
            }

            i=0; j=0;
            int qtdErroVoltando = 0;
            while (i<palavraDicionario.size() && j<palavraTeste.size()) {
                if (indiceDicionarioFazParteDaInterseccaoVoltando[i] == indiceTesteFazParteDaInterseccaoVoltando[j]) {
                    if (!indiceDicionarioFazParteDaInterseccaoVoltando[i]) qtdErroVoltando++;
                    i++; j++;
                } else if (indiceDicionarioFazParteDaInterseccaoVoltando[i] && !indiceTesteFazParteDaInterseccaoVoltando[j]) {
                    qtdErroVoltando++;
                    j++;
                } else {
                    qtdErroVoltando++;
                    i++;
                }
            }
            qtdErroVoltando += palavraDicionario.size()-i + palavraTeste.size()-j;

            if (qtdErroIndo <= 2 || qtdErroVoltando <= 2) possiveisCorrecoes.push_back(palavraDicionario);
        }
        respostas.push_back(possiveisCorrecoes);
    }
    for (vector<string> possiveisCorrecoes : respostas) {
        for (string palavra : possiveisCorrecoes) cout << palavra << " ";
        cout << endl;
    }
}
