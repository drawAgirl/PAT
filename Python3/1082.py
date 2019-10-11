number= ["ling","yi","er","san","si","wu","liu","qi","ba","jiu"]
radix=["Shi","Bai","Qian","Wan","Yi"]
s = input()
left = 0
right = len(s)-1
if s[0] == '-':
    print('Fu',end='')
    left +=1
while left +4<= right:
    right -=4
while left < len(s):
    flag = False
    isprint = False
    while left <= right:
        if left >0 and s[left] == '0':
            flag = True
        else:
            if flag:
                print(" ling",end='')
                flag = False
            if left > 0:
                print(' ',end='')
            print(number[ord(s[left])-ord('0')],end='')
            isprint = True
            if left != right:
                print(" {}".format(radix[right-left-1]),end='')

        left += 1
    if isprint and right != len(s)-1:
        print(" {}".format(radix[(len(s)-1-right)//4+2]),end='')
    right += 4