class num:
    def __init__(self,n):
        self.n = n
    def __lt__(self, other):
        return self.n+other.n < other.n+self.n
    def __gt__(self, other):
        return self.n+other.n > other.n+self.n
    def __ge__(self, other):
        return self.n+other.n >= other.n+self.n
    def __eq__(self, other):
        return self.n+other.n == other.n+self.n
    def __le__(self, other):
        return self.n+other.n <= other.n+self.n
n,*number = input().split()
data = []
for n in number:
    data.append(num(n))
data.sort()
ans = ""
for each in data:
    ans = ans + each.n
flag = True
for each in ans:
    if flag and each == '0':
        continue
    elif each != '0':
        flag = False
    print(each,end='')
if flag:
    print("0")

