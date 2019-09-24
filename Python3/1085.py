n,m = map(int,input().split())
number = list(map(int,input().split()))
number.sort()

# def binary_search(array,key,index): # return the index 二分方法也超时
#     if array[-1] <= key:
#         return n
#     low = index+1
#     high = n-1
#     while low < high:
#         mid = (low+high)//2
#         if array[mid] <= key:
#             low = mid+1
#         else:
#             high = mid
#     return low
# ans = 1
# for i in range(n):
#     j = binary_search(number,number[i]*m,i)
#     ans = max(ans,j-i)
# print("%d"%ans)

i = 0
j = 0
cnt = 1
while i<n and j<n:
    while j<n and number[j] <= number[i]*m:
        cnt = max(cnt,j-i+1)
        j = j + 1
    i = i+ 1
print("%d"%cnt)