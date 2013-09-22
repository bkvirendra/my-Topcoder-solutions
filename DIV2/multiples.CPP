#include<iostream>

class Multiples {

	public:
        int number(int min, int max, int factor) {
            int count = 0;
            int i;
            for(i=min;i<=max;i++) {
                if (i % factor == 0) {
                    count = 1 + count;
                }
            }
            return count;
        }

};
