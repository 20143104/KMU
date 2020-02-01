import re
def reverse(text):
    return text[::-1]

def is_palindrome(text):
    return text ==reverse(text)


something = input('Enter text: ')
something = re.sub("[,*.-/(/)/]", "", something)
something = something.replace(" ", "")
something = something.lower()

if(is_palindrome(something)):
    print("Yes")
else:
    print(reverse(something))
    print("no")
