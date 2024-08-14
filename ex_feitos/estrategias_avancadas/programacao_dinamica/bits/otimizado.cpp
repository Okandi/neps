#include <bits/stdc++.h>

using namespace std;


int main() {
    int tamanhoSequencia, qtdBitsSeguidosMaximo;
    cin >> tamanhoSequencia >> qtdBitsSeguidosMaximo;

    long long possibilidadesTotal[tamanhoSequencia][qtdBitsSeguidosMaximo];
    const long long modulo = (long long) pow(10, 9) + 7;

    memset(*possibilidadesTotal, 0, sizeof(possibilidadesTotal));

    possibilidadesTotal[0][0] = 1;
    if (qtdBitsSeguidosMaximo > 1) possibilidadesTotal[0][1] = 1;

    for (int tamanhoIterIndex=1; tamanhoIterIndex<tamanhoSequencia; tamanhoIterIndex++) {
        for (int soma1NoFinal=0; soma1NoFinal <= min(tamanhoIterIndex+1,qtdBitsSeguidosMaximo-1); soma1NoFinal++) { // O(n²)
            possibilidadesTotal[tamanhoIterIndex][0] += possibilidadesTotal[tamanhoIterIndex-1][soma1NoFinal];
            possibilidadesTotal[tamanhoIterIndex][0] = possibilidadesTotal[tamanhoIterIndex][0]%modulo;
            if (soma1NoFinal != 0) {
                possibilidadesTotal[tamanhoIterIndex][soma1NoFinal] += possibilidadesTotal[tamanhoIterIndex-1][soma1NoFinal-1];
                possibilidadesTotal[tamanhoIterIndex][soma1NoFinal] = possibilidadesTotal[tamanhoIterIndex][soma1NoFinal]%modulo;
            }
        }
    }

    long long soma = 0;
    for (int i=0; i<qtdBitsSeguidosMaximo; i++) soma = (soma+possibilidadesTotal[tamanhoSequencia-1][i])%modulo;

    cout << soma << endl;
}
