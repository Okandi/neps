#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;


int main() {
    map<int, int> versaoDosAplicativos;
    set<int> aplicativosParaAtualizar;
    int qtdInstalados, qtdNaRede;
    cin >> qtdInstalados >> qtdNaRede;

    int idPrograma, versaoPrograma;
    for (int i=0; i<qtdInstalados; i++) {
        cin >> idPrograma >> versaoPrograma;
        versaoDosAplicativos[idPrograma] = versaoPrograma;
    }
    for (int i=0; i<qtdNaRede; i++) {
        cin >> idPrograma >> versaoPrograma;
        auto versaoInstalada = versaoDosAplicativos.find(idPrograma);
        if (versaoInstalada->second < versaoPrograma) {
            versaoDosAplicativos[idPrograma] = versaoPrograma;
            aplicativosParaAtualizar.insert(idPrograma);
        }
    }
    for (auto idPrograma : aplicativosParaAtualizar) {
        cout << idPrograma << " " << versaoDosAplicativos[idPrograma] << endl;
    }
}
