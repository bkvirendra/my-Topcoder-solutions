from sys import stdin


def main():
    fun = lambda: map(int, stdin.readline().split(" "))

    n = fun()

    values = fun()

    change25 = 0
    change50 = 0

    for i in range(0, n[0]):
        value = values[i]

        if value == 25:
            change25 += 1

        if value == 50:
            if change25 == 0:
                print "NO"
                return
            else:
                change25 -= 1
                change50 += 1

        if value == 100:
            if change50 == 0 or change25 < 3:
                print "NO"
                return
            else:
                if change50 > 0 and change25 > 0:
                    change50 -= 1
                    change25 -= 1
                else:
                    change25 -= 3

    print "YES"
    return

main()
