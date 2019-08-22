//https://leetcode.com/problems/target-sum/
class Solution {
public:
            int count = 0;

    void helper(vector<int> &nums, int i, int sum, int S) {
        if(i == nums.size()) {
            if(sum == S) count++;
        } else {
            helper(nums,i+1,sum+nums[i],S);
            helper(nums,i+1,sum-nums[i],S);
        }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        helper(nums,0,0,S);
        return count;
    }
};