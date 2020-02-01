import sys
import time

f = None

try:
    f = open("poem.txt")

    while True:
        line =  f.readline()
        if len(line) == 0:
            break
        print(line)
        sys.stdout.flush()
        print("Press ctrl+c now")
        time.sleep(2)

except IOError:
    print ("Could not find file poem.txt")
except KeyboardInterrupt:
    print ("!! You cancelled the reading from the file.")
finally:
    if f:
        f.close()
print ("(Cleaning up: Closed the file)")