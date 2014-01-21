from itertools import combinations

class WinterAndMandarins(object):
    def getNumber(self, bags, K):
        b = set(combinations(bags, K))
        arr = []
        for i in b:
            arr.append(max(i) - min(i))
        return min(arr)
