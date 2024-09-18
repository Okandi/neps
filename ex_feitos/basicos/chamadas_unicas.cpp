#include <iostream>
#include <set>

using namespace std;


int main() {
    int qtdRegistros;
    cin >> qtdRegistros;
    int registro;
    set<int> registrosUnicos;
    for (int i=0; i<qtdRegistros; i++) {
        cin >> registro;
        registrosUnicos.insert(registro);
    }
    cout << registrosUnicos.size() << endl;
}
