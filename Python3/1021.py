n=int(input())
couple = {}
party = {}
for _ in range(n):
    a,b=map(int,input().split())
    couple[a] = b
    couple[b] = a
_ = input()
people = list(map(int,input().split()))
for each in people:
    party[each] = 1
single = []
for dog in people:
    if couple.get(dog) is None:
        single.append(dog)
    elif party.get(couple[dog]) is None:
        single.append(dog)
print(len(single))
single.sort()
for i in range(len(single)):
    print("%05d"%single[i],end='')
    if i != len(single)-1:
        print(' ',end='')