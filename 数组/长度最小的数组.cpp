/*
problem:给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
data:2026/03/03
Author:ZY
*/
class Solution{
public:
    int huadongchuangkou(vector<int>  &nums, int val){
        int i = 0; //起点 
        int result = nums.size();
        int sum = 0;
        for(int j = 0;j < nums.size(); j++){ // j为终点
            sum += nums[j];
            /*内部的while循环主要是用来移动起点的，移动的方式为不断地将起点的值从sum中减去，并将起点向右移动，
            直到sum小于val为止。这样就保证了在每次外层循环结束时，sum都是大于等于val的，从而可以更新result的值。*/
            while(sum >= val){
                int subL = j - i + 1;
                result = min(result, subL);
                sum -= nums[i]; // 关键是确定起点的移动时机
                i++;
            }
        }
        return result;
    }
};
