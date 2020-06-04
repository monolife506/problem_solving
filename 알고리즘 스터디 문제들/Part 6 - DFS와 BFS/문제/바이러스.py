cnt = 0


def dfs(cur):
    global cnt
    visited[cur] = True
    for node in graph[cur]:
        if (not visited[node]):
            dfs(node)
            cnt += 1


graph = [[] for i in range(101)]
visited = [False for i in range(101)]

N = int(input())
M = int(input())
for i in range(M):
    node1, node2 = map(int, input().split())
    graph[node1].append(node2)
    graph[node2].append(node1)

dfs(1)
print(cnt)
