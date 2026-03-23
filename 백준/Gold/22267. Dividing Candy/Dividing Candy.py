n=int(input())
a=list(map(int,input().split()))

x = [0]*(10**5+30)
for e in a:
    x[e] += 1

for i in range(len(x)-1):
    x[i+1] += x[i] // 2
    x[i] %= 2

res = set()
for i in range(len(x)):
    if x[i]: res.add(i)

if n >= 2:
    print("Y" if len(set(res)) <= 2 else "N")
else:
    print("N")