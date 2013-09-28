class Bits(object):

	def minBits(self, n):
		getBin = lambda x: x >= 0 and str(bin(x))[2:] or "-" + str(bin(x))[3:]
		return len(getBin(n))
