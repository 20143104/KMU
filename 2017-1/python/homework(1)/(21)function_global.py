x=50

def fun():
    global x

    print('x is',x)
    x=2
    print('Changed global x to',x)


fun()
print('Value of x is',x)