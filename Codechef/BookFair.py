from math import sqrt


def main():
    t = int(raw_input())
    ts = []

    while t > 0:
        val = raw_input()
        ts.append(int(val))
        t -= 1

    for radius in ts:
        AB = 2 * radius
        ABsqr = AB*AB
        BCsqr = float(ABsqr)/2
        BC = sqrt(BCsqr)
        print("%.6f" %BC)

    return

main()
