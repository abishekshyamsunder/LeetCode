class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int s = 0, e = 0;
        int count = 0;
        int prod = 1;
        for(int i=0;i<nums.size();i++)
        {
            prod = prod * nums[i];
            e = i;
            if(prod<k)
            {
                count = count + e - s + 1;     
                // cout<<count<<" "<<e<<" "<<s<<endl;
            }
            else
            {
                while(prod>=k && s<=e)
                {
                    prod = prod / nums[s];
                    s++;
                }
                // cout<<"Inside else: "<<prod<<" "<<e<<" "<<s<<endl;
                if(s == e)
                {
                    if(prod<k)
                    {
                        count++;
                    }
                    else
                    {
                        s = i+1;
                    }
                }
                else
                {
                    // cout<<"Here: "<<i;
                    count = count + e - s + 1;
                }
            }
        }
        return count;
    }
};
