from queue import Queue
from collections import defaultdict


qtd_ligacoes = int(input())

ligacoes = defaultdict(set)

lista_artigos = set()

for i in range(qtd_ligacoes):
	artigo1, artigo2 = input().split()
	ligacoes[artigo1].add(artigo2)
	lista_artigos.update([artigo1, artigo2])


lista_artigos = list(lista_artigos)

lista_artigos.sort()

for i in range(len(lista_artigos)):
	if i != 0: ligacoes[lista_artigos[i]].add(lista_artigos[i-1])
	if i != len(lista_artigos)-1: ligacoes[lista_artigos[i]].add(lista_artigos[i+1])

camadas = defaultdict(lambda: -1)
visitado = defaultdict(lambda: False)


input()


source, destination = input().split()


camadas[source] = 0

fila = Queue()
fila.put(source)

visitado[source] = True

while not fila.empty():
	artigo_atual = fila.get()

	if artigo_atual == destination: break

	for artigo_vizinho in ligacoes[artigo_atual]:
		if not visitado[artigo_vizinho]:
			visitado[artigo_vizinho] = True
			camadas[artigo_vizinho] = camadas[artigo_atual]+1
			fila.put(artigo_vizinho)

print(camadas[destination])
