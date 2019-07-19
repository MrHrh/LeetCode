/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

//-----------------------------------------------------------------------------
//code
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //先对数组进行排序
        sort(nums.begin(), nums.end());
        //边界条件判断
        if(nums.size() < 3 || nums.front() > 0 || nums.back() < 0) return {};
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++)
        {
            int index = nums[i];
            //当当前值和前一个值相等时，直接跳过，避免重复，因为以前一个值为核心的所有可能都已经列出，无需再次判断
            if(i > 0 && index == nums[i-1]) continue;
            int left = i + 1;
            int right = nums.size()-1;
            while(left < right)
            {
                if(nums[left] + nums[right] + index == 0)
                {
                    //当促成相等时的左右两个值的位置为当前位置加1，或者最大位置时，说明第一次找到满足条件的组合，直接push_back
                    if(left == i + 1 || right == nums.size()-1)
                    {
                        res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                    //如果两端有一个值和上一次的值相等，那么这个结果就是重复的，这种情况成立时已经至少有一组解了
                    else if(nums[left] == nums[left-1]) left++;
                    else if(nums[right] == nums[right+1]) right--;
                    //其他的普通情况，push_back
                    else
                    {
                         res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                    }
                }
                else if(nums[left] + nums[right] + index < 0)  left++;
                else right--;
            }
            
        }
        return res;
    }
};
