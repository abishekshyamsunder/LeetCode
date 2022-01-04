class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> count_p(26,0);
        vector<int> count_s(26,0);
        vector<int> ret_val;
        for(int i=0;i<p.size();i++)
        {
            count_p[p[i]-'a']++;
        }
        // for(int i=0;i<26;i++)
        // {
        //     cout<<count_p[i]<<" ";
        // }
        int i = 0,j = p.size()-1;
        for(int k = 0;k<=j && k<s.size();k++)
        {
            count_s[s[k]-'a']++;
        }
        // for(int k=0;k<26;k++)
        // {
        //     cout<<count_s[k]<<" ";
        // }
        for(i,j;j<s.size();i++,j++)
        {
            if(i!=0)
            {
                count_s[s[i-1]-'a']--;
                count_s[s[j]-'a']++;
            }
            if(count_p == count_s)
                ret_val.push_back(i);
            
        }
        return ret_val;
    }
};
