class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = 0,j = 0;
        string s1 = "";
        while(j<s.length())
        {
            if(s[j] == '#')
            {
                if(i!=0)
                    i--;
                j++;
            }
            else
            {
                s[i] = s[j];
                i++;
                j++;
            }
        }
        for(int k = 0;k<i;k++)
        {
            s1 = s1 + s[k];
        }
        i = 0;
        j = 0;
        string s2 = "";
        while(j<t.length())
        {
            if(t[j] == '#')
            {
                if(i!=0)
                    i--;
                j++;
            }
            else
            {
                t[i] = t[j];
                i++;
                j++;
            }
        }
        for(int k = 0;k<i;k++)
        {
            s2 = s2 + t[k];
        }
        cout<<s1<<":"<<s2;
        if(s1 == s2)
            return true;
        else
            return false;
        
    }
};
