#include <iostream>
#include <queue>

using namespace std;


bool verificarSeClienteDemorou(
    int &tempoAgora,
    priority_queue<int, vector<int>, greater<int>> &caixas,
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &clientes
) {
    pair<int, int> clienteAtual = clientes.top();
    clientes.pop();
    if (clienteAtual.first > tempoAgora) tempoAgora = clienteAtual.first;
    if (caixas.top() > tempoAgora) tempoAgora = caixas.top();
    caixas.pop();
    caixas.push(tempoAgora+clienteAtual.second);
    return (tempoAgora-clienteAtual.first) > 20;
}


int main() {
    int qtdClientesEsperouDemais = 0;
    int tempoAgora = 0;

    int qtdCaixas, qtdClientes, entrada, demora;

    cin >> qtdCaixas >> qtdClientes;

    priority_queue<int, vector<int>, greater<int>> caixas;
    for (int i=0; i<qtdCaixas; i++) caixas.push(0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> clientes;
    for (int i=0; i<qtdClientes; i++) {
        cin >> entrada >> demora;
        clientes.push({entrada, demora});
    }

    for (int i=0; i<qtdClientes; i++) {
        if (verificarSeClienteDemorou(tempoAgora, caixas, clientes)) qtdClientesEsperouDemais++;
    }

    cout << qtdClientesEsperouDemais << endl;
}
