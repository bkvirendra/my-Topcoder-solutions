class AlienAndPassword(object):
    def getNumber(self, S):
        a = []
        for i in list(S):
            if not a:
                a.append(i)
            else:
                if a[-1] != i:
                    a.append(i)

        return len(a)
