f = open('square_detector.txt', 'r')
o = open('output.txt', 'w')

T = int(f.readline())

for t in xrange(T):
    n = int(f.readline())

    rows = []
    holes = []

    rows_c = [0] * n
    cols_c = [0] * n

    for r in xrange(n):
        l = list(f.readline())

        for m, item in enumerate(l):
            if item == "#":
                rows_c[r] += 1
                cols_c[m] += 1

        if l.count("#") > 0:
            rows.append(l.count("#"))
            s = "".join(l).replace("\n", "").split(".")
            y = s.count("#")
            holes.append(True) if y > 1 else holes.append(False)

    if True in holes:
        o.write("Case #" + str(t + 1) + ": NO\n")
        continue

    if all(x == rows[0] for x in rows) is False:
        o.write("Case #" + str(t + 1) + ": NO\n")
        continue

    if rows[0] * rows[0] != sum(rows):
        o.write("Case #" + str(t + 1) + ": NO\n")
        continue

    rows_c = filter(lambda a: a > 0, rows_c)
    cols_c = filter(lambda a: a > 0, cols_c)

    if all(x == rows_c[0] for x in rows_c) is False or all(x == cols_c[0] for x in cols_c) is False:
        o.write("Case #" + str(t + 1) + ": NO\n")
        continue

    o.write("Case #" + str(t + 1) + ": YES\n")
