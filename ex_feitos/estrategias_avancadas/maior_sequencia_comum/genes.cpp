#include <bits/stdc++.h>

using namespace std;


int main() {
    int tamanhoGene1, tamanhoGene2;
    cin >> tamanhoGene1 >> tamanhoGene2;

    int gene1[tamanhoGene1];
    for (int i=0; i<tamanhoGene1; i++) cin >> gene1[i];

    int gene2[tamanhoGene2];
    for (int i=0; i<tamanhoGene2; i++) cin >> gene2[i];

    int dp[tamanhoGene1+1][tamanhoGene2+1] = {};

    for (int i=1; i<=tamanhoGene1; i++) {
        for (int j=1; j<=tamanhoGene2; j++) {
            if (gene1[i-1] == gene2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    int tamanhoMaiorAncestralComum = dp[tamanhoGene1][tamanhoGene2];

    cout << tamanhoGene1 - tamanhoMaiorAncestralComum << " " << tamanhoGene2 - tamanhoMaiorAncestralComum << endl;
}
