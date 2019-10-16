n=int(input())
lines = [None]
which_line = {}
for i in range(1,n+1):
    _,*line = map(int,input().split())
    for each in line:
        if which_line.get(each) is None:
            which_line[each] = []
        which_line[each].append(i)
    lines.append(line)


k = int(input())
for _ in range(k):
    start,destination = map(int,input().split())
