/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/


//code
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> myVec;
        if(digits.size() < 1) return myVec;
        
        vector<string> myVec1 = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        myVec.push_back("");
        
        for(int i = 0; i < digits.size(); i++)
        {
            int index = digits[i] - '2';
            int len = myVec.size();
            for(int j= 0; j < len; j++)
            {
                for(int k = 0; k < myVec1[index].size(); k++)
                    myVec.push_back(myVec[j]+myVec1[index][k]);
            }
            myVec.erase(myVec.begin(), myVec.begin()+len);
        }
        return myVec;
    }   
};
