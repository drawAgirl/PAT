n=int(input())
father = [i for i in range(10010)]
forest = set()
isTree = {}
def findfather(x):
    a = x
    while x != father[x]:
        x = father[x]
    while a != father[a]:
        z = a
        a = father[a]
        father[z] = x
    return x

def Union(a,b):
    fa = findfather(a)
    fb = findfather(b)
    if fa != fb:
        father[fa] = fb

for _ in range(n):
    _,*birds = map(int,input().split())
    forest.add(birds[0])
    for bird in birds[1:]:
        Union(birds[0],bird)
        forest.add(bird)
cnt = 0
for bird in forest:
    fa = findfather(bird)
    if isTree.get(fa) is None:
        isTree[fa] = True
        cnt += 1
print(cnt,len(forest))
k = int(input())

for _ in range(k):
    a,b = map(int,input().split())
    fa = findfather(a)
    fb = findfather(b)
    if fa != fb:
        print("No")
    else:
        print("Yes")