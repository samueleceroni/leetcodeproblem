#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
private:
    unordered_map<char, int> rToI;
public:
    int romanToInt(string &s) {
        rToI['I'] = 1;
        rToI['V'] = 5;
        rToI['X'] = 10;
        rToI['L'] = 50;
        rToI['C'] = 100;
        rToI['D'] = 500;
        rToI['M'] = 1000;
        
        int tot = 0;
        int currMax = 0;
        for (int i = s.length()-1; i>=0; i--){
            if(rToI[s[i]]>=currMax){
                currMax =rToI[s[i]]; 
                tot+=currMax;
            } else {
                tot -= rToI[s[i]];
            }
        }
        return tot;
    }
};