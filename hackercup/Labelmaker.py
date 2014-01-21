f = open('labelmaker_input.txt', 'r')
o = open('output.txt', 'w')

T = int(f.readline())

for t in xrange(T):
    ln = f.readline()
    letters = list(ln.split(" ")[0])
    n = int(ln.split(" ")[1])

    # convert the number to base of len(letters)