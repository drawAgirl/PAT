n = int(input())
data = input().split()
ans = 0
cnt = 0
for m in data:
    try:
        temp = float(m)
    except:
        print("ERROR: {} is not a legal number".format(m))
        continue
    if temp > 1000 or temp < -1000 or round(temp,2)!=temp:
        print("ERROR: {} is not a legal number".format(temp))
        continue
    ans += temp
    cnt += 1
if cnt == 1:
    print("The average of 1 number is %.2f"%ans);
elif cnt == 0:
    print("The average of 0 numbers is Undefined")
else:
    print("The average of %d number is %.2f"%(cnt,ans/cnt))