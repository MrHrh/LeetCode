/*
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
示例 1:
输入: 123
输出: 321
*/

-----------------------------------------------------------------

//code

class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        
        int flag = 0;
        int ret = 0;
        string s;
        if(x < 0){
            if(x/2 <= -1073741824)
                return 0;
            x = 0-x;  
            flag = 1;
        } 
        
        while(1){
            s += (x%10);
            x = x/10;
            if(x==0) break;
        }
        for(int i = 0; i < s.length(); i++){
            ret += (int)(s[i]);
            if(i < s.length()-1)
            {
                if(ret > 2147483647/10)
                    return 0;
                ret *= 10;
            }
        }
        if(flag == 1) ret = 0 - ret;
        return ret;
    }
};



-------------------------------------------------------------
//最优解，官方解答
class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            //取余数
            int pop = x % 10;
            x /= 10;
            //最大32位有符号整数的最后一位是7
            if (ret > INT_MAX/10 || (ret == INT_MAX / 10 && pop > 7)) return 0;
            //最小32位有符号整数最后一位是8（负数，所以是-8）
            if (ret < INT_MIN/10 || (ret == INT_MIN / 10 && pop < -8)) return 0;
            ret = ret * 10 + pop;
        }
        return ret;
    }
};


//差距是真的大，，，，，，，，，
