#include <bits/stdc++.h>

using namespace std;


int main() {
    const int qtdAndares = 3;
    int andares[qtdAndares];
    for (int i=0; i<qtdAndares; i++) cin >> andares[i];

    priority_queue<int, vector<int>, greater<int>> tempos;
    for (int i=0; i<qtdAndares; i++) {
        int totalTempoTentativa = 0;
        for (int j=0; j<qtdAndares; j++) {
            totalTempoTentativa += andares[j]*abs(i-j)*2;
        }
        tempos.push(totalTempoTentativa);
    }
    cout << tempos.top() << endl;
}
