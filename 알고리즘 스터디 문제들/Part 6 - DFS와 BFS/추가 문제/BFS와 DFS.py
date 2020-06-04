# 저번주의 설명 예제와 완전히 동일함.
from collections import deque


def dfs(cur, graph, visited):
    print(cur, end=" ")
    visited[cur] = True
    for node in graph[cur]:
        if (not visited[node]):
            dfs(node, graph, visited)


def bfs(start, graph, visited):
    Q = deque()
    Q.appendleft(start)

    visited[start] = True
    print(start, end=" ")

    while (Q):
        cur = Q.pop()
        for node in graph[cur]:
            if (not visited[node]):
                Q.appendleft(node)
                visited[node] = True
                print(node, end=" ")


# 정점의 개수 N, 간선의 개수 M, 탐색을 시작할 정점의 번호 V
N, M, V = map(int, input().split())

graph = [[] for i in range(N + 1)]  # 무방향 그래프 - 인접 리스트 구현
visited = [False for i in range(N + 1)]  # 정점의 방문 여부를 확인하는 list

# 간선 입력
for i in range(M):
    tmp1, tmp2 = map(int, input().split())
    graph[tmp1].append(tmp2)
    graph[tmp2].append(tmp1)

# 번호 순으로 탐색해야 하는 경우 정점들의 list를 sort해준다.
for edges in graph:
    edges.sort()

dfs(V, graph, visited)
print()

visited = [False for i in range(N + 1)]  # Visited를 다시 초기화
bfs(V, graph, visited)
