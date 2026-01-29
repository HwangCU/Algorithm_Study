a,b,c = map(int, input().split())

dat = [0] * 101

for i in range(3):
    s,t = map(int, input().split())

    for j in range(s,t):
        dat[j] += 1
sum = 0

for i in dat:
    if i == 1: sum += a*i
    elif i == 2: sum += b*i
    elif i == 3: sum += c*i

print(sum)