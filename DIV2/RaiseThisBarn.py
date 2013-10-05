import re

class RaiseThisBarn(object):

    def calc(self, str):
        if str.count("c") == 0:
            return str.count(".") - 1
        if str.count("c") % 2 != 0:
            return 0
        occ = str.count("c") / 2
        occ_index = [m.start() for m in re.finditer(r"c", str)][occ - 1]
        occ_2nd_index = [m.start() for m in re.finditer(r"c", str)][occ]
        dots = abs(occ_index - occ_2nd_index) - 1
        return dots + 1


a = RaiseThisBarn()
print a.calc(".c.c...c..ccccc.c..c.c.cc..ccc")