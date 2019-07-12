/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true


示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
*/

//-------------------------------------------------------------------------------

//code
//自己解法
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        
        vector<char> vec;
        int num = 0;
        while((num = x%10) != 0 || (x/10 != 0)){
            vec.push_back(num);
            x /= 10;
        }
        
        int i = 0;
        int j = vec.size()-1;
        while(j > i){
            if(vec[i] != vec[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};

//------------------------------------------------------------
//code
 官方解析
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        return x == revertedNumber || x == revertedNumber/10;
    }
};
