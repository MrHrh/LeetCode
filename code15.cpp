/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

*/

//-----------------------------------------------------------------------
//code

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<3)
            return {};
        
        sort(nums.begin(),nums.end());
        int res=accumulate(nums.begin(),nums.begin()+3,0);
        int mn=abs(target-res);
        for(int i=0;i<nums.size();i++){
            int fix=target-nums[i];
            int l=i+1,r=nums.size()-1;
            //对撞指针
            while(l<r){
                if(nums[l]+nums[r]==fix)
                    return target;
                else {
                    if(abs(nums[l]+nums[r]-fix)<mn){
                        mn=abs(nums[l]+nums[r]-fix);
                        res=nums[l]+nums[r]+nums[i];
                    }
                    if(nums[l]+nums[r]>fix)
                        r--;
                    else if(nums[l]+nums[r]<fix)
                        l++;
                }
            }
        }
        return res;
    }
};
