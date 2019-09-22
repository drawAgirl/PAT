n = int(input())
male = []
female = []
for _ in range(n):
    a = list(input().split())
    a[3] = int(a[3])
    if a[1] == 'M':
        male.append(a)
    else:
        female.append(a)
if len(male) == 0:
    female = sorted(female,key=lambda x:x[3],reverse=True)
    print("%s %s"%(female[0][0],female[0][2]))
    print("Absent")
    print("NA")
elif len(female) == 0:
    print("Absent")
    male = sorted(male,key=lambda x:x[3])
    print("%s %s"%(male[0][0],male[0][2]))
    print("NA")
else:
    female = sorted(female,key=lambda x:x[3],reverse=True)
    male = sorted(male,key=lambda x:x[3])
    print("%s %s"%(female[0][0],female[0][2]))
    print("%s %s" % (male[0][0], male[0][2]))
    print("%d"%(female[0][3]-male[0][3]))

