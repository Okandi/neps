#include <bits/stdc++.h>

using namespace std;


int main() {
    string resultados = "";

    while (true) {
        int qtdDigitos, qtdDigitosAApagar;
        cin >> qtdDigitos >> qtdDigitosAApagar;
        if (qtdDigitos == 0 && qtdDigitosAApagar == 0) break;

        string numero;
        cin >> numero;

        stack<char> pilhaNumeros;

        for (char digito : numero) { // O(2n) no pior cenário
            while (!pilhaNumeros.empty() && pilhaNumeros.top() < digito && qtdDigitosAApagar > 0) {
                pilhaNumeros.pop();
                qtdDigitosAApagar--;
            }
            pilhaNumeros.push(digito);
        }
        while (qtdDigitosAApagar > 0) {
            pilhaNumeros.pop();
            qtdDigitosAApagar--;
        }

        string resultadoCasoTeste = "";
        while (!pilhaNumeros.empty()) { // O(n)
            resultadoCasoTeste = pilhaNumeros.top() + resultadoCasoTeste;
            pilhaNumeros.pop();
        }

        resultados += resultadoCasoTeste + "\n";
    }

    cout << resultados;
}
