x=50

def fun(x):
    print('x is', x)
    x=2
    print('Changed local x to', x)

fun(x)
print('x is still', x)