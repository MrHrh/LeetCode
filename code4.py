"""
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
"""

-----------------------------------------------------------------------
#code

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        nums1.extend(nums2)
        nums1.sort()
        length = len(nums1)
        if length == 1:
            return nums1[0]
        if length%2 == 0:
            return (nums1[(int)(length/2)]+nums1[(int)((length/2)-1)])/2
        else:
            index = (int)(length/2)
            return nums1[index]
        
