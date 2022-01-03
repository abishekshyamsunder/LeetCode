class Solution {
public:
    int jump(vector<int>& nums) {
        // nums.insert(nums.begin(),1);
        // vector<int> jump(nums.size());
        vector<int> num_jmp(nums.size(),INT_MAX/2);
        num_jmp[0] = 0;
        int temp = -1;
        int size = nums.size();
        if(size==1)
            return 0;
        for(int i=0;i<size;i++)
        {
            temp = nums[i]+i;
            for(int j=i+1;j<=temp;j++)
            {
                if(j<size)
                    num_jmp[j] = min(num_jmp[j], num_jmp[i]+1);
                else
                {
                    break;
                }
            }
            if(temp >= nums.size()-1)
            {
                num_jmp[size-1] = min(num_jmp[i]+1, num_jmp[size-1]);
                break;
            }
        }
        return num_jmp[size-1];
    }
};
