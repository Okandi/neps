#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeSmallestDigitsFromNumber(string number, int qtdDigitosARemover) {
    stack<char> numberStack;
    for (char digit : number) {
        if (numberStack.empty()) {
            numberStack.push(digit);
            continue;
        };
        while (!numberStack.empty() && numberStack.top() < digit && qtdDigitosARemover > 0) {
            numberStack.pop();
            qtdDigitosARemover--;
        };
        numberStack.push(digit);
    };
    for (int i=0; i<qtdDigitosARemover; i++) {
        numberStack.pop();
    };
    number = "";
    int newTotalSize = numberStack.size();
    for (int i=0; i<newTotalSize; i++) {
        number = numberStack.top() + number;
        numberStack.pop();
    };
    return number;
};

int main() {
    int tamanhoNumero;
    int qtdDigitosARemover;
    string resultados = "";

    while (true) {
        cin >> tamanhoNumero >> qtdDigitosARemover;
        if (tamanhoNumero == 0 && qtdDigitosARemover == 0) break;
        string numero;
        cin >> numero;
        resultados += removeSmallestDigitsFromNumber(numero, qtdDigitosARemover) + "\n";
    };
    cout << resultados;
};
