n = int(input())
ans = ''
for i in range(n):
    a = input()
    a = a[::-1]
    length = len(a)
    if i == 0:
        ans = a
        continue
    else:
        length2 = len(ans)
        min_len = min(length,length2)
        for j in range(min_len):
            if ans[j] != a[j]:
                ans = ans[:j]
                break
ans = ans[::-1]
if(len(ans) == 0):
    print("nai")
else:
    print("%s"%ans)
