def factors(n):
    return set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))


def main():
    n = int(raw_input())
    t = []

    while n > 0:
        b = raw_input()
        t.append(int(b))
        n -= 1

    for e in t:
        count = 0
        f = list(factors(e))
        for i in f:
            if i == 7 or i == 4:
                if i == 7:
                    count += 1
                if i == 4:
                    count += 1
            else:
                if "4" in str(i):
                    count += 1
                elif "7" in str(i):
                    count += 1
        print count


main()