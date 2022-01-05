class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        // Same logic, keep track of negative also as it can any time change to +ve;
        nums.insert(nums.begin(),0);
        int ret_val = INT_MIN;
        vector<int> longest_pos(nums.size(),0);
        vector<int> longest_neg(nums.size(),0);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                longest_pos[i] = longest_pos[i-1]+1;
                if(longest_neg[i-1] == 0)
                    longest_neg[i] = 0;
                else
                    longest_neg[i] = longest_neg[i-1]+1;
            }
            else if(nums[i]<0)
            {
                longest_neg[i] = longest_pos[i-1] + 1;
                if(longest_neg[i-1] == 0)
                    longest_pos[i] = 0;
                else
                    longest_pos[i] = longest_neg[i-1]+1;
            }
            else if(nums[i]==0)
            {
                longest_pos[i] = 0;
                longest_neg[i] = 0;
            }
            ret_val = max(ret_val,longest_pos[i]);
            // cout<<nums[i]<<" "<<longest_pos[i]<<" "<<longest_neg[i]<<endl;
        }
        return ret_val;
    }
};
