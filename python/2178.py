from collections import deque
n,m = map(int, input().split())
arr = []

for _ in range(n):
    arr.append(list(map(int, input())))

dy = [-1,1,0,0]
dx = [0,0,-1,1]

q = deque()
q.append((0,0))

while q:
    y,x = q.popleft()
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        
        if (ny<0 or ny>=n or nx<0 or nx>=m): continue
        if arr[ny][nx] == 0: continue
        if arr[ny][nx] == 1:
            arr[ny][nx] = arr[y][x]+1
            q.append([ny,nx])

print(arr[n-1][m-1])