a = []
for i in range(1,10):
    a.append(int(input()))

a.sort()
for i in range(0,9):
    for j in range(i+1,9):
        sum = 0
        for k in range(0,9):
            if (k != i) & (k != j):
                sum += a[k]
        if sum == 100:
            for ak in range(9):
                if(ak != i) & (ak != j):
                    print(a[ak])
            exit()