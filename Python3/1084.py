a = input()
b = input()
dic = {}
for each in b:
    if ord(each) >= ord('a') and ord(each) <= ord('z'):
        dic[chr(ord(each) - 32)] = 1
    elif ord(each)>=ord('A') and ord(each) <= ord('Z'):
        dic[chr(ord(each) + 32)] = 1
    dic[each] = 1
for each in a:
    if dic.get(each) == None:
        dic[each] = 1
        if ord(each) >= ord('a') and ord(each) <= ord('z'):
            # print("1:")
            print("%c"%(chr(ord(each)-32)),end="")
            dic[chr(ord(each)-32)] = 1
        elif ord(each)>=ord('A') and ord(each) <= ord('Z'):
            dic[chr(ord(each)+32)] = 1
            print("%c"%each,end='')
        else:
            # print("2:")
            print("%c"%each,end='')
