a = list(input())
b = list(input())
dic = {}
for each in b:
    dic[each] = 1
for each in a:
    if dic.get(each) == None:
        print("%c"%each,end='')
