from sys import stdin


def main():
    fun = lambda: map(int, stdin.readline().split(" "))

    n = fun()

    values = fun()

    change = 0

    for i in range(0, n[0]):
        value = values[i]

        if value == 25:
            change += 1

        if value == 50:
            if change == 0:
                print "NO"
                return
            else:
                change -= 1

        if value == 100:
            if change < 3 or change == 0:
                print "NO"
                return
            else:
                change -= 3

    if change >= 0:
        print "YES"
    return

main()
