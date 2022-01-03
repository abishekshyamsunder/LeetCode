class Solution {
public:
    bool canJump(vector<int>& nums) {
        // if(nums.size()==1)
        //     return true;
        vector<int> jmp;
        nums.insert(nums.begin(),1);
        jmp.push_back(1);
        int size = nums.size();
        int temp = -1;
        for(int i=1;i<size-1;i++)
        {
            temp = max(jmp[i-1]-1,nums[i]);
            if(temp>0)
            {
                jmp.push_back(temp);
            }
            else
                return false;
        }
        return true;
    }
};
