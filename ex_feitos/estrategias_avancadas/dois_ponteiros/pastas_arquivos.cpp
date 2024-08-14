#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdArquivos, maximoBytes;
    cin >> qtdArquivos >> maximoBytes;

    deque<int> arquivos;

    for (int i=0; i<qtdArquivos; i++) {
        int tamanho;
        cin >> tamanho;
        arquivos.push_back(tamanho);
    }

    sort(arquivos.begin(), arquivos.end());

    int totalPastas = 0;
    while (!arquivos.empty()) { // O(n)
        if (arquivos.size() == 1) {
            arquivos.pop_back();
            totalPastas++;
        } else {
            int somaDoisArquivos = arquivos.front() + arquivos.back();
            if (somaDoisArquivos > maximoBytes) {
                arquivos.pop_back();
                totalPastas++;
            } else {
                arquivos.pop_front();
                arquivos.pop_back();
                totalPastas++;
            }
        }
    }

    cout << totalPastas << endl;
}
