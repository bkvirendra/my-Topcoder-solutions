import itertools


def main():
    T = int(raw_input())
    n = []
    tests = []
    ans = []

    while T > 0:
        n.append(int(raw_input()))
        tests.append([int(i) for i in raw_input().split(" ")])
        T -= 1

    for i in xrange(0, len(n)):
        s = sorted(tests[i])
        l = len(s) - sum(j > n for j in s)
        arr = s[0:l]
        k = 0
        for pair in itertools.combinations(arr, 2):
            k += 1

        ans.append(k)

    for m in ans:
        print m


main()