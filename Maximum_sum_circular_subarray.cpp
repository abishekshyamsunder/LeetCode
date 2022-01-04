class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> track(nums.size(),0);
        vector<int> track_max(nums.size(),INT_MIN);
        int min_sum = 0;
        int max_sum = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum+nums[i];
            if(i==0)
            {
                track[i] = min(track[0],nums[i]);    
                track_max[i] = max(track[0],nums[i]);
            }
            else
            {
                track[i] = min(track[i-1]+nums[i],nums[i]);
                track_max[i] = max(track_max[i-1]+nums[i],nums[i]);
            }
                
            // cout<<i<<": "<<track[i]<<endl;
            min_sum = min(min_sum,track[i]);
            max_sum = max(max_sum,track_max[i]);
        }
        cout<<min_sum<<" "<<max_sum;
        if(sum-min_sum != 0)
            return max(sum - min_sum,max_sum);
        else
            return max_sum;
    }
};
