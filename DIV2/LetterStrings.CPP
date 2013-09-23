#include<iostream>
#include<vector>
#include<typeinfo>
#include<string>

using namespace std;

class LetterStrings {
    public:
        int sum(vector <string> s) {
            int i, j = 0;
            int count = 0;
            for(i=0;i<s.size();i++) {
                for(j=0;j<s[i].length();j++) {
                    if(s[i][j] != '-') {
                        count ++;
                    }
                }
            }
            return count;
        }
};
