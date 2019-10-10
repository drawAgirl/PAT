from fractions import Fraction
a,b = input().split()
c=['+','-','*','/']
a = Fraction(a)
b = Fraction(b)

def show(a):
    if a.denominator == 1:
        if a.numerator < 0:
            print("({})".format(a.numerator),end='')
        else:
            print(a.numerator,end='')
    elif abs(a.numerator) > abs(a.denominator):
        if a.numerator < 0:
            print("(-{} {}/{})".format(abs(a.numerator)//a.denominator,abs(a.numerator)%a.denominator,a.denominator),end='')
        else:
            print("{} {}/{}".format(a.numerator//a.denominator,a.numerator%a.denominator,a.denominator),end='')
    else:
        if a.numerator< 0:
            print("({})".format(a),end='')
        else:
            print(a,end='')

for each in c:
    show(a)
    print(" {} ".format(each),end='')
    show(b)
    print(" = ",end='')
    if each =='+':
        show(a+b)
    elif each == '-':
        show(a-b)
    elif each =='*':
        show(a*b)
    else:
        try:
            show(a/b)
        except:
            print("Inf")
    print()
