from collections import deque

dy = [-1,1,0,0]
dx = [0,0,-1,1]

def BFS(y,x):
    q = deque()
    q.append((y,x))
    visited[y][x] = 1

    while q:
        cy, cx = q.popleft()

        for i in range(4):
            ny = cy+dy[i]
            nx = cx+dx[i]

            if 0<=ny<n and 0<=nx<m and _map[ny][nx] == 1 and visited[ny][nx] == 0:
                q.append((ny,nx))
                visited[ny][nx] = 1
                
                
T = int(input())

for t in range(T):
    m,n,k = map(int, input().split())
    _map = [[0]*m for _ in range(n)]
    visited = [[0]*m for _ in range(n)]
    cnt = 0
    for _ in range(k):
        x,y = map(int,input().split())
        _map[y][x] = 1

    for i in range(n):
        for j in range(m):
            if(_map[i][j] == 1 and visited[i][j] == 0):
                BFS(i,j)
                cnt += 1
    print(cnt)
