#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

class UserName {

    public:
        string newMember(vector <string> existingNames, string newName) {
            int i, j, result = 0;
            for(i=0;i<existingNames.size();i++) {
                if(newName == existingNames[i]) {
                    result = 1;
                }
            }
            if(result == 1) {
                for(i=1;i<50;i++) {
                    result = 0;
                    string newUsername = newName;
                    stringstream k;
                    k << i;
                    newUsername += k.str();
                    for(j=0; j<existingNames.size(); j++) {
                        if(newUsername == existingNames[j]) {
                            result = 1;
                        }
                    }
                    if (result == 0) {
                        return(newUsername);
                    }
                }
            } else {
                return(newName);
            }
        }
};
