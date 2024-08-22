n, m = map(int, input().split())

dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

# Lê todos os inteiros da sequência A e armazena-os no vetor A
A = list(map(int, input().split()))

# Lê todos os inteiros da sequência B e armazena-os no vetor B
B = list(map(int, input().split()))

for i in range(1, n + 1):
    for j in range(1, m + 1):
        # Calculando dp[i][j] 
        if A[i - 1] != B[j - 1]:
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
        else:
            dp[i][j] = dp[i - 1][j - 1] + 1

print(f"Tamanho da maior subsequência comum: {dp[n][m]}")

MSC = []  # A MSC será guardado nesse vector
i = n
j = m

print(*dp)

while i != 0 and j != 0:
    if A[i - 1] == B[j - 1]:  # A[i - 1] e B[j - 1] estão na MSC
        MSC.append(A[i - 1])
        i -= 1
        j -= 1
    else:
        if dp[i - 1][j] > dp[i][j - 1]:  # Decidindo qual é o melhor estado para ir
            i -= 1
        else:
            j -= 1

# Revertendo a resposta
MSC.reverse()

print("Maior subsequência comum:")
print(*MSC)
