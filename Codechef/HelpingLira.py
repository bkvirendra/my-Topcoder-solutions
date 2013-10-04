def main():
    n = int(raw_input())
    tri = []

    while n > 0:
        b = raw_input()
        tri.append([int(i) for i in b.split(" ")])
        n -= 1

    areas = []

    for vertex in tri:
        x1, y1, x2, y2, x3, y3 = vertex[0], vertex[1], vertex[2], vertex[3], vertex[4], vertex[5]
        areas.append(abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))/float(2))

    print str(len(areas) - areas[::-1].index(min(areas))) + " " + str(len(areas) - areas[::-1].index(max(areas)))

main()
