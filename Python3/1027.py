radix = ['0','1','2','3','4','5','6','7','8','9','A','B','C']
a,b,c = map(int,input().split())
print("#",end="")
print("%c%c"%(radix[a//13],radix[a%13]),end="")
print("%c%c"%(radix[b//13],radix[b%13]),end="")
print("%c%c"%(radix[c//13],radix[c%13]),end="")
