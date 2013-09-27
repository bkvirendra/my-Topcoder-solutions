import itertools


class LittleElephantAndPermutationDiv2(object):

    def getNumber(self, N, K):
        a = [i for i in range(1, N+1)]
        c = 0
        for j in itertools.permutations(a):
            for k in itertools.permutations(a):
                su = 0
                for m in range(0, len(k)):
                    su += max(j[m], k[m])
                if su >= K:
                    c += 1
        return c
