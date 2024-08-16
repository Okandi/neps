#include <bits/stdc++.h>

using namespace std;


class Graph {
    private:
        bool is_undirected;
        int qtd_nodes;
        vector<int> *conexao_nodes;

        bool *visited = NULL;

        void dfs(int node) {
            this->visited[node] = true;
            for (int related_node : this->conexao_nodes[node])
                if (!this->visited[related_node]) this->dfs(related_node);
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

        int count_groups() {
            delete this->visited;
            this->visited = new bool[this->qtd_nodes+1];
            fill(this->visited, this->visited+this->qtd_nodes+1, false);

            int qtd_grupos = 0;
            for (int node=1; node <= this->qtd_nodes; node++) {
                if (!this->visited[node]) {
                    this->dfs(node);
                    qtd_grupos++;
                }
            }

            return qtd_grupos;
        }
};


int main() {
    int qtdPessoas, qtdConexoes;
    cin >> qtdPessoas >> qtdConexoes;

    Graph *grafo = new Graph(qtdPessoas);

    for (int i=0; i<qtdConexoes; i++) {
        int pessoa1, pessoa2;
        cin >> pessoa1 >> pessoa2;
        grafo->add_edge(pessoa1, pessoa2);
    }

    cout << grafo->count_groups() << endl;
}
