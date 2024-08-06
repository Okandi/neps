#include <bits/stdc++.h>

using namespace std;


int main() {
    queue<int> caixas;
    for (int i=0; i<3; i++) {
        int caixa;
        cin >> caixa;
        caixas.push(caixa);
    }

    int lastBox = 0;
    queue<int> caixasAcumuladas;
    while (caixas.size() != 0) {
        if (lastBox != 0) {
            int espacoOcupado = lastBox;
            while (caixasAcumuladas.size() != 0 && espacoOcupado+caixasAcumuladas.front() < caixas.front()) {
                espacoOcupado += caixasAcumuladas.front();
                caixasAcumuladas.pop();
            }
            if (lastBox >= caixas.front()) caixasAcumuladas.push(lastBox);
        }
        lastBox = caixas.front();
        caixas.pop();
    }

    cout << caixasAcumuladas.size() + 1 << endl;
}
