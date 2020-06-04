# 재귀 호출을 이용한 dfs
def dfs(cur, graph, visited):
    print(cur, end=" ")
    visited[cur] = True
    for node in graph[cur]:
        if (not visited[node]):
            dfs(node, graph, visited)


# List로 구현한 Stack을 이용한 dfs
def dfs_stack(V, graph, visited):
    S = [V]
    visited[V] = True
    print(V, end=" ")

    while (S):
        cur = S[-1]
        for node in graph[cur]:
            if (not visited[node]):
                S.append(node)
                visited[node] = True
                print(node, end=" ")
                break
            elif (node == graph[cur][-1]):
                S.pop()


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

print("재귀 호출을 이용한 DFS의 탐색 순서")
dfs(V, graph, visited)

visited = [False for i in range(N + 1)]
print("\n\nStack을 이용한 DFS의 탐색 순서")
dfs_stack(V, graph, visited)
