#include <bits/stdc++.h>

using namespace std;


int main() {
	int qtdTarefas, qtdDependencias;
	cin >> qtdTarefas >> qtdDependencias;

	vector<vector<int>> dependencias(qtdTarefas, vector<int>());

	for (int i=0; i<qtdDependencias; i++) { // O(m)
		int tarefaA, tarefaB;
		cin >> tarefaA >> tarefaB;
		dependencias[tarefaA].push_back(tarefaB);
	}

	vector<int> nDeps(qtdTarefas, 0);

	priority_queue<int, vector<int>, greater<int>> fila;

	for (auto deps : dependencias) // O(n+m)
		for (auto tarefa : deps)
			nDeps[tarefa]++;

	for (int i=0; i<qtdTarefas; i++) // O(n)
		if (nDeps[i] == 0) fila.push(i);

	vector<int> respostas;

	while (!fila.empty()) { // O(n) --> O(m+n*log(n))
		int tarefa = fila.top();
		fila.pop();

		respostas.push_back(tarefa);

		for (auto tarefaDependente : dependencias[tarefa]) { // O(m)
			nDeps[tarefaDependente]--;
			if (nDeps[tarefaDependente] == 0) fila.push(tarefaDependente); // O(log n)
		}
	}

	if (respostas.size() != qtdTarefas) cout << "*" << endl;
	else for (auto tarefa : respostas) cout << tarefa << endl;
}
