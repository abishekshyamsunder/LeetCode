class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int min_sum = INT_MIN;
        vector<int> track(nums.size(),INT_MIN);
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                min_sum = max(max_sum,nums[i]);
                track[i] = max_sum;
                
            }
            else
            {
                track[i] = max(nums[i],track[i-1]+nums[i]);
                max_sum = max(max_sum,track[i]);
            }
        }
        return max_sum;
    }
};
