/*
problem:给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
Data: 2026/3/2
Author by:ZY
*/
class Solution{
public:
    int youxushuzupingfang(vector<int> &nums){
        vector<int> result;
        int k = nums.size() - 1;
        for(int i = 0, int j = k; i <= j;){
            if(nums[i] * nums[i] > nums[j] * nums[j]){
                result[k--] = nums[i] * nums[i];
                i++;
            }else{
                result[k--] = nums[j] * nums[j];
                j--;
            }
        }
        return result;
    }
};
