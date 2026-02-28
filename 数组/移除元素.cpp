/*
problem:给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
Data: 2026/2/28
Author by:ZY
*/
// 解法1-暴力求解
// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution{
public:
    int RemoveElement(vector<int> &nums, int val){
        int size = nums.size();
        for(int i = 0; i < size; i++){
            if (nums[i] == val){
                for(int j = i+1;j < size; j++){
                    nums[j - 1] = nums[j];
                }
                i--; // 抵消外层循环的 i++，让 i 停留在当前下标，重新检查 “被前移过来的新元素”，避免漏掉连续匹配的元素；
                size--;
            }
        }
        return size;
    }
};

// 解法2-双指针法
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};
