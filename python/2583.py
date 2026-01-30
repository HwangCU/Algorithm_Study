import sys
sys.setrecursionlimit(10**6)
m,n,k = map(int, input().split())

dy = [-1,1,0,0]
dx = [0,0,-1,1]
cnt = 0

def dfs(y,x):
    global cnt
    for i in range(4):
        nx = x+dx[i]
        ny = y+dy[i]

        if nx<0 or nx>=n or ny<0 or ny>=m : continue
        if visited[ny][nx]==0 and _map[ny][nx] == 0:
            visited[ny][nx] = 1
            cnt += 1
            dfs(ny,nx)
    return cnt
_map = [[0]*n for _ in range(m)]
visited = [[0]*n for _ in range(m)]

for _ in range(k):
    y1,x1,y2,x2 = map(int, input().split())

    for i in range(x1,x2):
        for j in range(y1,y2):
            _map[i][j] = 1

result = []

for i in range(m):
    for j in range(n):
        if visited[i][j] == 0 and _map[i][j] == 0:
            cnt = 1
            visited[i][j] = 1
            result.append(dfs(i,j))
result.sort()
print(len(result))
for i in result:
    print(i,end=' ')

