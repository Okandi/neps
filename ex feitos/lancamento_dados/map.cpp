#include <bits/stdc++.h>

using namespace std;


int main() {
    int vezes;
    cin >> vezes;

    map<const int, int> lancamentos;
    for (int i=0; i<vezes; i++) {
        int resultado;
        cin >> resultado;
        if (lancamentos.find(resultado) == lancamentos.end()) lancamentos[resultado] = 0;
        lancamentos[resultado]++;
    }

    int maxValue = 0;
    for (int i=0; i<vezes; i++) {
        auto maxElement = max_element(lancamentos.begin(), lancamentos.end(), [](auto lancamento1, auto lancamento2) {
            return make_pair(lancamento1.second, lancamento2.first) < make_pair(lancamento2.second, lancamento1.first);
        });
        if (maxValue <= maxElement->second) maxValue = maxElement->second;
        else break;
        cout << maxElement->first << " ";
        lancamentos.erase(maxElement->first);
    }
    cout << endl;
}
