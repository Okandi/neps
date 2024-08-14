#include <bits/stdc++.h>

using namespace std;


int tamanhoSequencia, qtdBitsSeguidosMaximo;
long long possibilidadesTotal = 0;


void countDigitsPossibilities(int ordem, int somaDaSequencia) { // O(2^n)
    if (ordem > tamanhoSequencia) {
        possibilidadesTotal++;
        possibilidadesTotal = possibilidadesTotal%((long long) pow(10, 9)+7);
        return;
    }
    if (somaDaSequencia+1 < qtdBitsSeguidosMaximo) countDigitsPossibilities(ordem+1, somaDaSequencia+1);
    countDigitsPossibilities(ordem+1, 0);
}


int main() {
    cin >> tamanhoSequencia >> qtdBitsSeguidosMaximo;

    int somaDaSequencia = 0;

    countDigitsPossibilities(1, 0);

    cout << possibilidadesTotal << endl;
}
