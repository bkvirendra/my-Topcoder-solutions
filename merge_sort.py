count = 0


def merge(l, r):
    global count
    result = []
    i = j = 0
    while i < len(l) and j < len(r):
        if l[i] < r[j]:
            result.append(l[i])
            i += 1
        else:
            result.append(r[j])
            count += (len(l) - i)
            j += 1
    result.extend(l[i:])
    result.extend(r[j:])
    return result


def sort(arr):
    if len(arr) < 2:
        return arr
    m = len(arr) / 2
    left = sort(arr[:m])
    right = sort(arr[m:])
    return merge(left, right)


f = open("/home/virendra/IntegerArray.txt", "r")
arr = []
for line in f:
    arr.append(eval(line.strip()))

sort(arr)
print count
