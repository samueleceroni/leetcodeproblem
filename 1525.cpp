#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

    int numSplits(const string &s) {
        vector<int> singleLeftCount(s.length()), singleRightCount(s.length());
        unordered_set<char> singleLeftSet, singleRightSet;
        for(int i = 0; i<s.length()-1; i++){
            singleLeftSet.insert(s[i]);
            singleLeftCount[i] = singleLeftSet.size();
            singleRightSet.insert(s[s.length() - 1 - i]);
            singleRightCount[s.length() - 1 - i] = singleRightSet.size();
        }
        int sol = 0;
        for(int i = 0; i<s.length()-1;i++){
            if(singleLeftCount[i] == singleRightCount[i+1])
                sol++;
        }
        return sol;
    }

int main(){
    string s = "aacaba";
    cout << numSplits(s);
}