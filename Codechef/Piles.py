from math import ceil

def main():
    t = int(raw_input())
    ts = []
    while t > 0:
        arr = raw_input().split()
        values = [int(i) for i in arr]
        ts.append(values)
        t -= 1
    results = []
    for testcase in ts:
        piles = testcase
        prev_pile, player_to_play = None, True
        while True:
            if piles[0] <= 1 and piles[1] <= 1:
                if prev_pile is None:
                    results.append(True)
                    break
                else:
                    results.append(prev_pile)
                    break
            else:
                pile1 = ceil((float(max(piles)) / 2))
                pile2 = pile1 - max(piles)
                piles = [pile1, pile2]
                prev_pile, player_to_play = player_to_play, not(player_to_play)
    for result in results:
        if result is False:
            print "B"
        if result is True:
            print "A"
    return

main()
