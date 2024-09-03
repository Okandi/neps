#include <bits/stdc++.h>

using namespace std;


class Graph {
    private:
        bool is_undirected;
        int qtd_nodes;
        vector<int> *conexao_nodes;

        int dfs(int node) {
            int last_sum = -1;
            for (int related_node : this->conexao_nodes[node]) {
                int soma_atual = this->dfs(related_node);
                if (soma_atual == -1) return -1;
                else if (last_sum == -1) last_sum = soma_atual;
                else if (last_sum != soma_atual) return -1;
            }
            if (last_sum == -1) return 1;
            return this->conexao_nodes[node].size() * last_sum + 1;
        }

    public:
        Graph (int qtd_nodes, bool is_undirected=true) {
            this->qtd_nodes = qtd_nodes;
            this->conexao_nodes = new vector<int>[qtd_nodes+1];
            this->is_undirected = is_undirected;
        }

        void add_edge(int from, int to) {
            this->conexao_nodes[from].push_back(to);
            if (this->is_undirected) {
                this->conexao_nodes[to].push_back(from);
            }
        }

        bool e_balanceado() {
            if (this->dfs(0) != -1) return true;
            return false;
        }
};


int main() {
    int qtdPecas;
    cin >> qtdPecas;
    Graph *grafo = new Graph(qtdPecas+1, false);
    for (int i=0; i<qtdPecas; i++) {
        int submobile, mobile;
        cin >> submobile >> mobile;
        grafo->add_edge(mobile, submobile);
    }

    if (grafo->e_balanceado()) cout << "bem";
    else cout << "mal";
    cout << endl;
}
