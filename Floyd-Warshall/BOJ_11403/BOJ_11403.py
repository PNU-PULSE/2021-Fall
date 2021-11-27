n = int(input())
graph = []
for _ in range(n):
    graph.append(list(map(int, input().split())))
    
# 플로이드-와셜 알고리즘
for k in range(n): # 경로 k가 있는 for문이 가장 상위여야함
    for i in range(n):
        for j in range(n): 
            if graph[i][j] == 1 or (graph[i][k] == 1 and graph[k][j] == 1):
                graph[i][j] = 1

for line in graph:
    for x in line:
        print(col, end = " ")
    print()
