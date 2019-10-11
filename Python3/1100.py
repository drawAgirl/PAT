earths = ["tret","jan","feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov","dec"]
mars= ["","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"]
n=int(input())
for _ in range(n):
    s = input()
    try:
        a = int(s)
        if a>=13:
            b = a%13
            a = a//13
            if b:
                print(mars[a],earths[b])
            else:
                print(mars[a])
        else:
            print(earths[a])
    except:
        if len(s) <= 4:
            try:
                print("%d"%(earths.index(s)))
            except:
                print("%d"%(mars.index(s)*13))
        else:
            a,b = s.split()
            print("%d"%(13*(mars.index(a))+earths.index(b)))
