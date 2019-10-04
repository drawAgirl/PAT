Cmax,D,Davg,n = map(eval,input().split())
st = []
for _ in range(n):
    a,b = map(eval,input().split())
    st.append((a,b))
st.append((0,D))
st.sort(key=lambda x:x[1])
if st[0][1] != 0:
    print("The maximum travel distance = 0.00")
else:
    now = 0
    ans = 0
    nowTank=0
    MAX = Cmax*Davg
    while now < n:
        k = -1
        priceMin = 10000
        for i in range(now+1,n+1):
            if st[i][1] - st[now][1] > MAX:
                break
            if st[i][0] < priceMin:
                priceMin = st[i][0]
                k = i
                if priceMin < st[now][0]:
                    break
        if k == -1:
            break
        need = (st[k][1]-st[now][1])/Davg
        if priceMin < st[now][0]:
            if nowTank < need:
                ans += (need-nowTank)*st[now][0]
                nowTank = 0
            else:
                nowTank -= need
        else:
            ans += (Cmax-nowTank)*st[now][0]
            nowTank = Cmax-need
        now = k
    if now == n:
        print("%.2f"%ans)
    else:
        print("The maximum travel distance = %.2f"%(st[now][1]+MAX))