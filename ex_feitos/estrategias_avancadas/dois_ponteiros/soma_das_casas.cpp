#include <bits/stdc++.h>

using namespace std;


int main() {
    int qtdCasas;
    cin >> qtdCasas;

    deque<int> casas;
    for (int i=0; i<qtdCasas; i++) { // O(n)
        int casa;
        cin >> casa;
        casas.push_back(casa);
    }

    int soma;
    cin >> soma;

    while (true) { // O(N)
        if (casas.front() + casas.back() < soma) casas.pop_front();
        else if (casas.front() + casas.back() > soma) casas.pop_back();
        else break;
    }

    cout << casas.front() << " " << casas.back() << endl;
}
