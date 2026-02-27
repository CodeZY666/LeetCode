/*
problem:给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
Data: 2026/2/27
Author by:ZY
*/
// 解法1-左闭右闭
class Solution{
public:
    int Search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = left + ((right -left)/2);
            if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};

// 解法2-左闭右开
class Solution{
public:
    int Search(vector<int> &num, int target){ // 修正拼写错误 Serch → Search
        int left = 0;
        int right = num.size(); // 左闭右开区间 [left, right)
        while (left < right){ // 区间不为空时循环
            // 位运算替代除法，等价于 (right-left)/2，避免溢出
            int mid = left + ((right - left)  >> 1);
            if(num[mid] > target){
                right = mid; // 目标在左半区，右边界设为mid（不包含）
            }else if(num[mid] < target){
                left = mid + 1; // 目标在右半区，左边界设为mid+1（包含）
            }else{
                return mid; // 找到目标，返回索引
            }
        }
        return -1; // 未找到目标
    }
};
