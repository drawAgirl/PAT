# from operator import attrgetter
# n,m = map(int,input().split())
# people = []
# ans = {}
# class student:
#     def __init__(self,id,Program,Math,English):
#         self.id = id
#         self.Program = -Program
#         self.Math = -Math
#         self.English = -English
#         self.average = (self.Program+self.Math+self.English)/3
# for _ in range(n):
#     id,Program,Math,English = map(int,input().split())
#     temp = student(id,Program,Math,English)
#     people.append(temp)
# orders = ['average','Program','Math','English']
# for i,order in enumerate(orders):
#     people.sort(key=attrgetter(order))
#     rank = 1
#     if ans.get(people[0].id) == None:
#         ans[people[0].id] = [rank,i]
#     # for each in people:
#     for j in range(1,len(people)):
#         if i == 0:
#             if ans.get(people[j].id) == None:
#                 if people[j].average == people[j-1].average:
#                     ans[people[j].id] =
#

class student:
    def __init__(self, C, M, E, ID):
        self.grade = [round((C + M + E) / 3), C, M, E]
        self.id = ID
        self.rank = [-1, -1, -1, -1]


def main():
    n,m = map(int,input().split())
    students = {}
    for x in range(n):
        ID,*line = input().split()
        C = int(line[0])
        M = int(line[1])
        E = int(line[2])
        s = student(C, M, E, ID)
        students[ID] = s
    for x in range(4):
        p = sorted(students.values(), key=lambda i: -i.grade[x])
        p[0].rank[x] = 1
        for i in range(1, n):
            p[i].rank[x] = i + 1
            if p[i].grade[x] == p[i - 1].grade[x]:
                p[i].rank[x] = p[i - 1].rank[x]
    for x in range(m):
        line = input()
        try:
            unit = students[line]
            temp = zip(unit.rank, ['0A', '1C', '2M', '3E'])
            temp = sorted(temp)
            print(str(min(unit.rank)), temp[0][1][-1])
        except:
            print('N/A')


main()