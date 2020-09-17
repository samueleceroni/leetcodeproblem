Symbol       Value
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
        return romanToInt(s, 0, s.length()-1);
    }
private:
    int romanToInt(const string &s, int a, int z){
        if(z < a) return 0;
        vector<int> suffMaxPos;
        int currMax = 0, maxSum = 0;
        for(int i = z; i>=a; i--){
            if(rToI[s[i]]>=currMax){
                currMax = rToI[s[i]];
                suffMaxPos.push_back(i);
                maxSum += currMax;
            }
        }
        reverse(suffMaxPos.begin(), suffMaxPos.end());
        int toRemove = 0;
        for(int i = 0; i<suffMaxPos.size()-1; i++){
            toRemove += romanToInt(s, suffMaxPos[i]+1, suffMaxPos[i+1]-1);
        }
        return currMax - toRemove;        
    }
};