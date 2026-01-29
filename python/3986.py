n = int(input())
ans = 0

for _ in range(n):
    stack = []
    _list = list(input())
    for i in _list:
        if 0 == len(stack):
            stack.append(i)
        elif stack[-1] == i:
            stack.pop(-1)
        else:
            stack.append(i)

    if 0 == len(stack):
        ans += 1 

print(ans)