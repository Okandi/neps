import math

tamanho, qtdConsultas = map(int, input().split())

bitsP = [0]*(1+math.ceil(tamanho/2))
bitsI = [0]*(1+math.ceil(tamanho/2))

arr = list(map(int, input().split()))
arr = [0, *arr]


def getXor(i, bits):
    total = 0
    while i>0:
        total ^= bits[i]
        i -= i & -i
    return total


def getAnsw(i, arr, bitsI, bitsP):
    if i&1: return arr[i]^getXor(math.ceil(i/2), bitsI)^getXor(math.ceil((i-1)/2), bitsP)
    return arr[i]^getXor(math.ceil(i/2), bitsP)^getXor(math.ceil((i-1)/2), bitsI)


def update(i, val, bits):
    while i<len(bits):
        bits[i] ^= val
        i += i & -i
    return bits

def updateS(i, val, bitsI, bitsP):
    if i&1: return update(math.ceil(i/2), val, bitsI)
    return update(math.ceil(i/2), val, bitsP)

resultados = []
for i in range(qtdConsultas):
    consulta = input()
    match int(consulta[0]):
        case 1:
            _, l, r, val = map(int, consulta.split())
            updateS(l, val, bitsI, bitsP)
            updateS(r+1, val, bitsI, bitsP)
        case 2:
            _, j = map(int, consulta.split())
            resultados.append(str(getAnsw(j, arr, bitsI, bitsP)))

print("\n".join(resultados))
