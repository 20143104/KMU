poem='''\
Programmingis fun
When the work is done
if you wanna make your also fun:
    use Python!
'''

f = open('poem.txt','w')
f.write(poem)
f.close()

f = open('poem.txt')

while True:
    line = f.readline()
    if len(line)==0:
        break

    print (line,)

f.close()