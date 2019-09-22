number = input().split()
a,b,c = map(int,number[0].split('.'))
x,y,z = map(int,number[1].split('.'))
r = (c+z)%29
q = ((c+z)//29+b+y)%17
p = ((c+z)//29+b+y)//17+a+x
print("%d.%d.%d"%(p,q,r))