class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int sliding_sum = 0;
        int s = 0,e = 0;
        for(int i=0;i<nums.size();i++)
        {
            sliding_sum = sliding_sum + nums[i];
            e = i;
            if(sliding_sum >= target)
            {
                // cout<<"1: "<<s<<" "<<e<<endl;
                min_len = min(min_len, e-s+1);
                while(sliding_sum >= target && s<= e)
                {
                    sliding_sum = sliding_sum - nums[s];
                    s++;
                    if(sliding_sum>=target)
                        min_len = min(min_len, e-s+1);
                    
                }
                // s--;
                // sliding_sum = sliding_sum + nums[s];
                cout<<"2: "<<s<<" "<<e<<endl;
                
                
            }
        }
        if(min_len == INT_MAX)
            min_len = 0;
        return min_len;
    }
};
