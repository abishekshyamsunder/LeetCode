class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1)
            return nums[0];
        else if(nums.size()==0)
            return 0;
        vector<int> mp;
        mp.push_back(nums[0]);
        int size = nums.size();
        int j = 0;
        for(int i=1;i<size;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                if(j>=1)
                    mp[j] = max(mp[j],mp[j-1]);
                j++;
                if(nums[i]>=nums[i-1]+2)
                    mp.push_back(nums[i]+mp[j-1]);
                else if(j>=2)
                    mp.push_back(nums[i]+mp[j-2]);
                else
                    mp.push_back(nums[i]);
                    
            }
            else
            {
                mp[j] = mp[j] + nums[i];
            }
        }
        
        
        for(int i=0;i<mp.size();i++)
            cout<<mp[i]<<" ";
        
        if(mp.size()>=2)
            return max(mp[mp.size()-1],mp[mp.size()-2]);
        else return mp[0];
    }
};
