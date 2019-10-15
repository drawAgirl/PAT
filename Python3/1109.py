from collections import deque
from operator import attrgetter
class node:
    def __init__(self,name,height):
        self.name = name
        self.height = -height
n,k = map(int,input().split())
student = []
for _ in range(n):
    name,height = input().split()
    student.append(node(name,int(height)))
student.sort(key=attrgetter('height','name'))
each_row_people = n//k
base = 0
for i in range(k):
    cur_row_people = each_row_people
    if i == 0:
        cur_row_people += n % k
    q = deque()
    for index in range(cur_row_people):
        if index&1:
            q.appendleft(index+base)
        else:
            q.append(index+base)
    base += cur_row_people
    space = 0
    for each in q:
        print(student[each].name,end='')
        space += 1
        if space != cur_row_people:
            print(' ',end='')
        else:
            print()