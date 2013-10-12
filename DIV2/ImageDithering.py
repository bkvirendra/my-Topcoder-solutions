class ImageDithering(object):

    def count(self, dithered, screen):
        d = list(dithered)
        count = 0
        for element in screen:
            e = list(element)
            for i in e:
                if i in d:
                    count += 1
        return count
