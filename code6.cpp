/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N


之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
*/

-------------------------------------------------------------------------

//code

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        //有多少行，string类型数组定义多少个元素
        vector<string> rows(Min(numRows, s.length()));
        int curRow = 0;
        bool reverse = false;
        
        for(int i = 0; i < s.length(); i++){
            //把当前位置的元素加到当前行
            rows[curRow] += s[i];
            //达到第一行或者最后一行的时候，curRow的增长方式翻转
            if(curRow == numRows-1 || curRow == 0) reverse = !reverse;
            curRow += reverse ? 1 : -1;
        }
        string ret;
        vector<string>::iterator it;
        //把元素按行拷贝到ret中，并返回
        for(it = rows.begin(); it < rows.end(); it++){
            ret += *it;
        }
        return ret;
    }
    
    int Min(int a, int b){
        if(a < b) return a;
        else return b;
    }
};
