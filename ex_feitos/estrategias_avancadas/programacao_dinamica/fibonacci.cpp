#include <bits/stdc++.h>

using namespace std;


int main() {
    int enesimo;
    cin >> enesimo;

    int fibonacci[enesimo];

    fibonacci[0] = 1;
    fibonacci[1] = 1;

    for (int i = 2; i<=enesimo; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    cout << fibonacci[enesimo] << endl;
}
