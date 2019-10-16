from functools import reduce
n=input()
print(int(reduce(lambda x,y:(x+y)/2,sorted(list(map(int,input().split()))))))