#include <iostream>
#include <string>
#include <queue>

using namespace std;


int main() {
    priority_queue<pair<int, string>> alunos;
    int qtd_alunos, qtd_times;

    cin >> qtd_alunos >> qtd_times;

    for (int i=0; i<qtd_alunos; i++) {
        pair<int, string> aluno;
        cin >> aluno.second >> aluno.first;
        alunos.push(aluno);
    }

    vector<priority_queue<string, vector<string>, greater<string>>> times[qtd_times];
    for (int i=0; i<qtd_times; i++) {
        times->push_back(priority_queue<string, vector<string>, greater<string>>());
    }

    for (int i=0; i<qtd_alunos; i++) {
        times->at(i%qtd_times).push(alunos.top().second);
        alunos.pop();
    }

    for (int i=0; i<qtd_times; i++) {
        cout << "Time " << i+1 << endl;
        while (!times->at(i).empty()) {
            cout << times->at(i).top() << endl;
            times->at(i).pop();
        }
        cout << endl;
    }
}
