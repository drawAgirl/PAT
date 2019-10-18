m,n = map(int,input().split())
tree = list(map(int,input().split()))
dic = {x:True for x in tree}
cur = -1
for _ in range(m):
    a,b = map(int,input().split())
    if dic.get(a) is None and dic.get(b) is None:
        print("ERROR: %d and %d are not found."% (a,b))
        continue
    elif dic.get(a) is None:
        print("ERROR: %d is not found."%a)
        continue
    elif dic.get(b) is None:
        print("ERROR: %d is not found."%b)
        continue
    for each in tree:
        cur = each
        if (each >= a and each <= b) or (each >=b and each <= a):
            break
    if cur == a:
        print("%d is an ancestor of %d."%(a,b))
    elif cur == b:
        print("%d is an ancestor of %d."%(b,a))
    else:
        print("LCA of %d and %d is %d."%(a,b,cur))
