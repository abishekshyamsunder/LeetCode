class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > mat(R, vector<int>(C)); 
        sort(nums.begin(), nums.end());
        set<vector<int> > matset;
        if(nums.size()>=3)
        {
            for(int i=0;i<nums.size()-2;i++)
            {            
                int l = i + 1;
                int r = nums.size()-1;
                while(l<r)
                {
                    while(l!=i+1 && l < nums.size() && nums[l]==nums[l-1])
                        l++;
                    while(r!=nums.size()-1 && r >i && nums[r]==nums[r+1])
                        r--;
                    if(nums[i]+nums[l]+nums[r] == 0 && l<r)
                    {
                        cout<<nums[i]<<","<<nums[l]<<","<<nums[r]<<endl;
                        vector<int> triple;
                        triple.push_back(nums[i]);
                        triple.push_back(nums[l]);
                        triple.push_back(nums[r]);
                        matset.insert(triple);
                        r--;
                        l++;
                    }
                    else if(nums[i] + nums[l] + nums[r] > 0)
                        r--;
                    else
                        l++;
                }
            }
        }
        mat.assign( matset.begin(), matset.end() );
        return mat;
    }
};
