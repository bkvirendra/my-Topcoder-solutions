class CmpdWords(object):

    def ambiguous(self, lang):
        compound = {}
        ambigous = []

        for word in lang:

            for dict_word in lang:

                if word != dict_word:
                    compound_word1 = word + dict_word
                    compound_word2 = dict_word + word

                    if compound_word1 in lang:
                        # ambigous, 1st case
                        ambigous.append(compound_word1)
                    else:
                        if compound_word1 in compound:
                            # append the nodes
                            compound[compound_word1].append([word, dict_word])
                        else:
                            compound[compound_word1] = []

                    if compound_word2 in lang:
                        ambigous.append(compound_word2)
                    else:
                        if compound_word2 in compound:
                            compound[compound_word2].append([dict_word, word])
                        else:
                            compound[compound_word2] = []

        for word, combinations in compound.iteritems():
            if len(combinations) > 2:
                ambigous.append(word)

        return len(list(set(ambigous)))
