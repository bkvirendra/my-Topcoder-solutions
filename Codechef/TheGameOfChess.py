def main():
    t = int(raw_input())
    ts = []

    while t > 0:
        val = raw_input()
        ts.append(int(val))
        t -= 1

    for players in ts:
        n = players
        no_of_passes = 0
        while True:
            if n <= 2:
                break
            temp_pass = 0
            if n % 2 == 1:
                # give pass
                temp_pass += 1
                n = (n - 1)/2
                no_of_passes += temp_pass
                n += temp_pass
            else:
                n = n/2
        print no_of_passes
    return

main()
