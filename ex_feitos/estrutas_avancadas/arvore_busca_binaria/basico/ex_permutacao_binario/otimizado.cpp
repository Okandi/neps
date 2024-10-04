// NÃO FUI EU QUE FIZ!!
// NÃO ENTENDI COMO FUNCIONA/PRA QUE SERVE -> // ???

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10;
const ll MOD = 1e9+7;

vector<int> left_child, right_child;
vector<vector<ll>> qtdPossibilidadesPorQuantidade, choose;
int tamanhoTotal, qtdConstantes, alturaMeta;


ll fast_pow(ll a, ll b) {
    if (b == 0) return 1;
    ll resultado = fast_pow(a, b/2);
    resultado = (resultado * resultado) % MOD;
    if (b%2) resultado = (resultado*a) % MOD;
    return resultado;
}


vector<ll> calculaQuantidadeDePossibilidadesDeCadaAltura(int quantidadeMaximaDeNos){
    if(!qtdPossibilidadesPorQuantidade[quantidadeMaximaDeNos].empty()) return qtdPossibilidadesPorQuantidade[quantidadeMaximaDeNos];

    vector<ll> qtdPossibilidadesDadaAltura(tamanhoTotal+1, 0);

    for(int i=1;i<=quantidadeMaximaDeNos;i++){

        vector<ll> left_subtree = calculaQuantidadeDePossibilidadesDeCadaAltura(i-1); // ?
        vector<ll> right_subtree = calculaQuantidadeDePossibilidadesDeCadaAltura(quantidadeMaximaDeNos-i); // ?

        ll total_left=0, total_right=0;

        for(int j=1; j<=tamanhoTotal; j++) {
            qtdPossibilidadesDadaAltura[j] += (
                (
                    (
                        (
                            (
                                (total_left + left_subtree[j-1]) % MOD
                            ) * (
                                (total_right + right_subtree[j-1]) % MOD
                            )
                        ) % MOD
                        - (
                            (total_left * total_right) % MOD
                        ) + MOD
                    ) % MOD
                ) * choose[quantidadeMaximaDeNos-1][i-1] // ???
            ) % MOD;

            qtdPossibilidadesDadaAltura[j] %= MOD;

            total_left += left_subtree[j-1]; total_left %= MOD;
            total_right += right_subtree[j-1]; total_right %= MOD;
        }
    }
    return qtdPossibilidadesPorQuantidade[quantidadeMaximaDeNos] = qtdPossibilidadesDadaAltura;
}

vector<vector<ll>> subtree;
vector<ll> subtree_size;

void build(int node, int low, int high, int height=1){
    if (node == -1) {
        subtree_size.push_back(high-low+1);

        vector<ll> resp = calculaQuantidadeDePossibilidadesDeCadaAltura(high-low+1);

        for (int i=tamanhoTotal; i>=height-1; i--) resp[i] = resp[i-height+1];

        for (int i=height-2; i>=0; i--) resp[i] = 0;

        subtree.push_back(resp);
    } else {
        build(left_child[node], low, node-1, height+1);
        build(right_child[node], node+1, high, height+1);
    }
}

int main() {
    cin >> tamanhoTotal >> qtdConstantes >> alturaMeta;

    qtdPossibilidadesPorQuantidade.resize(tamanhoTotal+1);

    qtdPossibilidadesPorQuantidade[0] = vector<ll>(tamanhoTotal+1);
    qtdPossibilidadesPorQuantidade[0][0] = 1;

    qtdPossibilidadesPorQuantidade[1] = vector<ll>(tamanhoTotal+1);
    qtdPossibilidadesPorQuantidade[1][1] = 1;

    choose.resize(tamanhoTotal+1, vector<ll>(tamanhoTotal+1)); // ???
    choose[0][0]=1;

    for(int i=1; i<=tamanhoTotal; i++){ // ?????
        for(int j=0; j<=i; j++){
            if (j < i) choose[i][j] += choose[i-1][j];
            if (j != 0) choose[i][j] += choose[i-1][j-1];
            choose[i][j] %= MOD;
        }
    }

    if (qtdConstantes == 0) {
        cout << calculaQuantidadeDePossibilidadesDeCadaAltura(tamanhoTotal)[alturaMeta] << "\n";
        return 0;
    }

    left_child.resize(tamanhoTotal+1, -1);
    right_child.resize(tamanhoTotal+1, -1);

    int root = -1;

    for (int i=0; i<qtdConstantes; i++) {
        int valor;
        cin >> valor;

        if (root == -1) {
            root = valor;
            continue;
        }

        int curentNode = root;

        while (true) {
            if (valor > curentNode) {
                if (right_child[curentNode] == -1) {
                    right_child[curentNode] = valor;
                    break;
                } else curentNode = right_child[curentNode];
            } else {
                if (left_child[curentNode] == -1) {
                    left_child[curentNode] = valor;
                    break;
                } else curentNode = left_child[curentNode];
            }
        }
    }

    build(root, 1, tamanhoTotal);

    vector<ll> fatorial(tamanhoTotal+1);
    vector<ll> inv_fact(tamanhoTotal+1); // ???

    fatorial[0] = inv_fact[0] = 1;

    for (ll i=1; i<=tamanhoTotal; i++){
        fatorial[i] = (fatorial[i-1] * i) % MOD;
        inv_fact[i] = (inv_fact[i-1] * fast_pow(i, MOD-2)) % MOD; // ?????
    }

    ll prod_less=1, prod_more=1, total=0;
    for (int i=0; i<subtree.size(); i++) { // ?????
        ll sum=0;

        total += subtree_size[i];
        for (int j=0; j<alturaMeta; j++) sum = (sum + subtree[i][j]) % MOD;

        prod_less = (prod_less * sum) % MOD;
        sum = (sum + subtree[i][alturaMeta]) % MOD;
        prod_more = (prod_more * sum) % MOD;
    }

    ll val = fatorial[total];
    for (int i=0; i<subtree.size(); i++) val = (val * inv_fact[subtree_size[i]]) % MOD; // ???

    cout << (((prod_more - prod_less + MOD) % MOD) * val) % MOD << "\n"; // ???
}
