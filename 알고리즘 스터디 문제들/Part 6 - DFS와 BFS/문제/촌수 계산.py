from sys import stdin
from collections import deque


def bfs(start, target, graph, visited):
    Q = deque()
    Q.appendleft(start)
    visited[start] = 0

    while (Q):
        cur = Q.pop()
        for node in graph[cur]:
            if (visited[node] == -1):
                Q.appendleft(node)
                visited[node] = visited[cur] + 1
                if (node == target):
                    return


N = int(stdin.readline())
start, target = map(int, stdin.readline().split())
graph = [[] for i in range(N + 1)]
visited = [-1 for i in range(N + 1)]

M = int(stdin.readline())
for i in range(M):
    node1, node2 = map(int, stdin.readline().split())
    graph[node1].append(node2)
    graph[node2].append(node1)

bfs(start, target, graph, visited)
print(visited[target])
