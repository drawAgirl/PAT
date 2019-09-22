word = input()
side = (len(word)+2)//3
bottom = len(word)-side-side
for i in range(side-1):
    print(word[i],end="")
    for _ in range(bottom):
        print(" ",end="")
    print(word[len(word)-1-i])
for i in range(side-1,side+bottom+1):
    print(word[i],end="")