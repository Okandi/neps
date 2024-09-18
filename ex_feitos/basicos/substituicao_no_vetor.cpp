#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<pair<int, int>> inteiros;
    for (int i=0; i<10; i++) {
        int inteiro;
        cin >> inteiro;
        inteiros.push_back({inteiro, i});
    }

    sort(inteiros.begin(), inteiros.end());

    int menor = inteiros.front().first;

    cout << "Menor: " << menor << endl;

    cout << "Ocorrencias:";
    for (int i=0; i<10; i++) {
        if (inteiros[i].first == menor) {
            cout << " " << inteiros[i].second;
            inteiros[i] = {-1, inteiros[i].second};
        }
        swap(inteiros[i].first, inteiros[i].second);
    }
    cout << endl;

    sort(inteiros.begin(), inteiros.end());

    for (int i=0; i<10; i++) {
        cout << inteiros[i].second << " ";
    }
    cout << endl;
}
