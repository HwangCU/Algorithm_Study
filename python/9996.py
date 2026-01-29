n = int(input())
s,t = input().split("*")

for i in range(n):
    IN = input()
    print(IN[:len(s)], IN[-len(t):])
    if((len(IN) >= (len(s)+len(t))) and (s == IN[:len(s)]) and (t == IN[-len(t):])):
        print("DA")
    else:
        print("NE")