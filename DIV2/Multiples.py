class Multiples(object):

    def number(self, min, max, factor):
        result = 0
        for i in range(min, max+1):
            if i % factor == 0:
                result += 1
        return result
