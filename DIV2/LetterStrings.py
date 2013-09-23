class LetterStrings(object):

    def sum(self, s):
        count = 0
        for e in s:
            for i in e:
                if i != "-":
                    count += 1
        return count
