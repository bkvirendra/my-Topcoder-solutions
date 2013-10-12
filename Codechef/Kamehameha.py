def main():
    """
    t = int(raw_input())
    arr = []

    while t > 0:
        st = int(raw_input())
        while st > 0:
            b = raw_input()
            arr.append([[int(i) for i in b.split(" ")]])
            st -= 1
        t -= 1
    """
    arr = [
        [
            [0, 0],
            [0, 1],
            [1, 0]
        ]
    ]

    for grid in arr:
        m = max(max(grid)) + 1
        Mat = [[0 for x in xrange(m)] for x in xrange(m)]

        for d in grid:
           Mat[d[0]][d[1]] = 1

        print Mat

        cols = rows = []
        i = j = 0

        for c in zip(*Mat):
            cols.append(sum(c))

        for r in Mat:
            rows.append(sum(r))

        print cols
        print rows

main()