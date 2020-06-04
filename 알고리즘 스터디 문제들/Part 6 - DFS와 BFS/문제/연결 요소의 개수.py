# 런타임 에러 방지를 위해 제출 시 언어를 PyPy3로 설정해야 한다
from sys import stdin

graph = [[] for i in range(1001)]
visited = [False for i in range(1001)]


def dfs(cur):
    visited[cur] = True
    for node in graph[cur]:
        if (not visited[node]):
            dfs(node)


N, M = map(int, stdin.readline().split())
for i in range(M):
    node1, node2 = map(int, stdin.readline().split())
    graph[node1].append(node2)
    graph[node2].append(node1)
cnt = 0
for i in range(1, N + 1):
    if (not visited[i]):
        cnt += 1
        dfs(i)
print(cnt)
