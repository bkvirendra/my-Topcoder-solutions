class WolfDelaymaster(object):

    def check(self, str):
        w = o = l = f = 0
        for n, i in enumerate(str):
            if i == "w":
                w += 1
                if len(str) - 1 == n:
                    return "INVALID"
                else:
                    if str[n + 1] == "w" or str[n + 1] == "o":
                        pass
                    else:
                        return "INVALID"
            if i == "o":
                o += 1
                if len(str) - 1 == n:
                    return "INVALID"
                else:
                    if str[n + 1] == "o" or str[n + 1] == "l":
                        pass
                    else:
                        return "INVALID"
            if i == "l":
                l += 1
                if len(str) - 1 == n:
                    return "INVALID"
                else:
                    if str[n + 1] == "l" or str[n + 1] == "f":
                        pass
                    else:
                        return "INVALID"
            if i == "f":
                f += 1
                if len(str) - 1 == n:
                    pass
                else:
                    if str[n + 1] == "f" or str[n + 1] == "w":
                        pass
                    else:
                        return "INVALID"
        if w == o == l == f:
            return "VALID"
        else:
            return "INVALID"


a = WolfDelaymaster()
print a.check("wwolfwoollff")
