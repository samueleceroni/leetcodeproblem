#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common = "";
        if(strs.size() == 0) return common;
        for(int i = 0; i<strs[0].length(); i++){
            char currChar = strs[0][i];
            for(int j = 0; j<strs.size(); j++){
                if(strs[j].size() < i
                || strs[j][i] != currChar)
                    return common;
            }
            common += currChar;
        }
        return common;
    }
};