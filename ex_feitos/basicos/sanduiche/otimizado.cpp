#include <iostream>
#include <vector>

using namespace std;


int main() {
    int qtdPedacos, tamanhoDesejado;
    cin >> qtdPedacos >> tamanhoDesejado;

    int san[qtdPedacos];
    vector<int> sanduiche(qtdPedacos);

    for (int i=0; i<qtdPedacos; i++) cin >> sanduiche[i];

    sanduiche.insert(sanduiche.end(), sanduiche.begin(), sanduiche.end()-1);

    int qtdDeAlternativas = 0;
    int indiceSuperior = 0;
    int tamanhoAcumulado = 0;

    for (int indiceInferior=0; indiceInferior<qtdPedacos; indiceInferior++) { // O(2N)
        while (indiceSuperior<qtdPedacos*2-1 && (indiceSuperior<qtdPedacos || indiceInferior>indiceSuperior-qtdPedacos) && tamanhoAcumulado+sanduiche[indiceSuperior] <= tamanhoDesejado) {
            tamanhoAcumulado += sanduiche[indiceSuperior];
            indiceSuperior++;
        }
        if (tamanhoAcumulado == tamanhoDesejado) qtdDeAlternativas++;
        tamanhoAcumulado -= sanduiche[indiceInferior];
    }

    cout << qtdDeAlternativas << endl;
}
