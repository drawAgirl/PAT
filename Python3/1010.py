n1,n2,tag,radix = input().split()
radix = int(radix)
def convert(n,radix):
    cnt = 0
    for i,j in enumerate(reversed(n)):
        temp = int(j) if j.isdigit() else ord(j)-ord('a')+10
        cnt += temp*pow(radix,i)
    return cnt
def find_radix(n,num):
    max_element = max(n)
    low = (int(max_element) if max_element.isdigit() else ord(max_element)-ord('a')+10)+1
    high = max(low,num)
    while low<=high:
        mid = (low+high)//2
        t=  convert(n,mid)
        if t > num:
            high = mid -1
        elif t==num:
            return mid
        else:
            low = mid+1
    return -1
ans = find_radix(n2,convert(n1,radix)) if tag=='1' else find_radix(n1,convert(n2,radix))
if ans == -1:
    print("Impossible")
else:
    print("{}".format(ans))

