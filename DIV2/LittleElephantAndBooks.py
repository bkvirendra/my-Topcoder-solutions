class LittleElephantAndBooks(object):

    def getNumber(self, pages, number):
        s = sorted(pages)
        s.insert(number - 1, s.pop(number))
        return sum(s[:number])


a = LittleElephantAndBooks()

print a.getNumber((74, 86, 32, 13, 100, 67, 77), 2)
