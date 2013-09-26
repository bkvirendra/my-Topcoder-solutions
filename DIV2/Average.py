class Average(object):

    def belowAvg(self, math, verbal):
        scores = []
        count = 0
        for i in range(0, len(math)):
            scores.append(math[i] + verbal[i])
        totalAvg = sum(scores) / len(scores)
        for score in scores:
            if score < totalAvg:
                count += 1
        return count
