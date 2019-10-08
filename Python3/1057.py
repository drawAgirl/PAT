def lowbit(x):
    return x&(-x)
n = int(input())
st = []
tree = [0 for i in range(n+1)]
def getsum(x):
    ans = 0
    i = x
    while i>0:
        ans += tree[i]
        i -= lowbit(i)
    return ans

def update(x,v):
    i = x
    while i<=n:
        tree[i] += v
        i += lowbit(i)

def peek():
    l = 1
    r = n
    k = (len(st)+1)//2
    while l< r:
        mid =(l+r)>>1
        if getsum(mid) >= k:
            r = mid
        else:
            l = mid+1
    print(l)
for _ in range(n):
    s = input()
    if s[1] == 'o':
        if len(st) == 0:
            print("Invalid")
        else:
            a = st[-1]
            st.pop()
            print(a)
            update(a,-1)
    elif s[1] == 'u':
        a,b=s.split()
        st.append(int(b))
        update(int(b),1)
    else:
        if len(st) == 0:
            print("Invalid")
        else:
            peek()
