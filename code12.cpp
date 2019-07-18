/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
	I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
	X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
	C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
示例 1:
输入: "III"
输出: 3
*/

//------------------------------------------------------------------------------
/code 我的解法

class Solution {
public:
    int romanToInt(string s) {
        map<string, int> char_map;
        char_map.insert(make_pair("I", 1));
        char_map.insert(make_pair("V", 5));
        char_map.insert(make_pair("X", 10));
        char_map.insert(make_pair("L", 50));
        char_map.insert(make_pair("C", 100));
        char_map.insert(make_pair("D", 500));
        char_map.insert(make_pair("M", 1000));
        char_map.insert(make_pair("IV", 4));
        char_map.insert(make_pair("IX", 9));
        char_map.insert(make_pair("XL", 40));
        char_map.insert(make_pair("XC", 90));
        char_map.insert(make_pair("CD", 400));
        char_map.insert(make_pair("CM", 900));
        
        int ret = 0;
        string tmp;
        string si;
        string sip;
        for(int i = 0; i < s.size(); i++)
        {
            si = s[i];
            sip = s[i+1];
            
            if(char_map[si] < char_map[sip]){
                tmp = s.substr(i,2);
                if(i+1 >= s.size()) break;
                i++;
            }
            else tmp = s[i];
            ret += char_map[tmp];
        }
        return ret;
    }
};

//code 精选题解

class Solution {
public:
    int romanToInt(string s) {
        int result=0;//存放结果
        map<char,int> luomab;//建立罗马表
        //插入对应关系
        luomab.insert(map<char,int>::value_type('I',1));
        luomab.insert(map<char,int>::value_type('V',5));
        luomab.insert(map<char,int>::value_type('X',10));
        luomab.insert(map<char,int>::value_type('L',50));
        luomab.insert(map<char,int>::value_type('C',100));
        luomab.insert(map<char,int>::value_type('D',500));
        luomab.insert(map<char,int>::value_type('M',1000));
        for(int i=0;i<s.length();i++)
        {
            if(luomab[s[i]]>=luomab[s[i+1]])
                result+=luomab[s[i]];
            else
            {
                result+=(luomab[s[i+1]]-luomab[s[i]]);
                i++;
            }
        }
        return result;
    }
};

/*
两种解法比较
大体思路都相同：比较当前位和下一位，若当前位小于下一位，则转为数字的值是由这两位组合而成的罗马数字代表的值，若当前位不小于下一位，当前位独立的值即为数字的值
在这里我处理不好的地方在于，没有很好地利用当前位小于下一位时的这种情况，使得数据结构和操作都复杂化，使得效率变低
当使用下一位减去当前位的值表示数值时，就可以将map表的类型定义为map<char, int>而不是map<string, int>，程序中其他地方出现的string也都可以用char代替，这是
效率提高的一个重要原因，还有一个地方我发现向map中插入时，map<char,int>::value_type('M',1000)比make_pair('M',1000)效率会高一些
*/
