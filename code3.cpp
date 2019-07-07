/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
------------------------------------------------------------------
//code

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int len = 0;
        int endlen = 0;
        if(s.length()==1)
            return 1;
        for(; i < s.length(); i++)
        {
            int j = i+1;
            int k = j;
            int flag = 0;
            for(; j >= i; j--)
            {
                if((j != k)&&(s[k] == s[j]))//不同下标的字符相等时，退出这次循环，i向后走一位继续找
                {
                    flag = 1;
                    len = k - i;
                    break;
                }
                if(flag == 0 && j == i) //当没有相同字符时j向后走一位继续找
                {                
                    len = k -i + 1;
                    j = k + 1;
                    k = j; 
                }
                if (j > s.length() - 1 && k > s.length()-1)
                {
                    if(len > endlen) return len;
                    else return endlen;
                }
            }
            if(endlen < len)
            {
                endlen = len;
            }
        }
        return endlen;
    }
};

--------------------------------------------------------
//new code
/*
力扣上面最优解法
优化的滑动窗口：当发现一个重复的字符时，滑动窗口的左索引i直接跳到前一个相同字符的下一个位置，而不是i++
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int n = s.length();
        map<char, int> Map_tmp;
        map<char, int>::iterator iter; 
        int i= 0, ans = 0;
        
        for(int j = 0; j<n; j++){
           if( (iter = Map_tmp.find(s[j])) != Map_tmp.end() ){
               i = max(i, iter->second);
           } 
            ans = max(ans, j-i+1);
            Map_tmp[(s[j])] = j+1;
        }
        return ans;
    }
};
