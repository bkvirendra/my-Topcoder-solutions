class TimeTravellingCellar(object):

	def determineProfit(self, profit, decay):
		max = 0
		for i in profit:
			for j in decay:
				if (i - j) > max:
					max = i - j
		return max
