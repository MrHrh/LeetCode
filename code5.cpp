/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
*/

-----------------------------------------------------------------
//code

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0) return "";
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); i++){
            //当回文串的中心是字符串中的某个字符时，求最大长度：“aba”
            int len1 = expendAroundCenter(s, i, i); 
            //当回文串的中心在两个字符之间时，求最大长度：“abba”
            int len2 = expendAroundCenter(s, i, i+1);
            int len = Max(len1, len2);
            //当最新的回文串长度比之前所有已找到的长度都大时，更新最长回文串的长度
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        } 
        //返回从start下标开始，长度为end-start+1的子串
        return s.substr(start, end-start+1);
    }
    int Max(int a, int b){
        if(a > b) return a;
        else return b;
    }
    //返回当前下标作为中心时最长回文串的长度
    int expendAroundCenter(string s, int left, int right){
        int L = left, R = right;
        while(L >= 0 && R < s.length() && s[L] == s[R]){
            L--;
            R++;
        }
        return R - L - 1;
    }
};
