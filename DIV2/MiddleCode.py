class MiddleCode(object):

    def encode(self, s):
        s = list(s)
        t = []
        l = len(s)
        while l != 0:
            if len(s) % 2 == 0:
                # even
                if s[len(s) / 2] > s[(len(s) / 2) - 1]:
                    t.append(s.pop((len(s) / 2) - 1))
                    l = len(s)
                elif s[len(s) / 2] < s[(len(s) / 2) - 1]:
                    t.append(s.pop(len(s) / 2))
                    l = len(s)
                else:
                    t.append(s.pop(len(s) / 2))
                    l = len(s)
            else:
                # odd
                t.append(s[len(s) / 2])
                l = len(s)
        return "".join(t)


a = MiddleCode()
print a.encode("ordw")