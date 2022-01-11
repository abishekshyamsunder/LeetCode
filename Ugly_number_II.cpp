class Solution {
public:
    int nthUglyNumber(int n) {
        int p2=0,p3=0,p5=0;
        vector<int> ugly(1,1);
        int temp = 0;
        while(ugly.size()<=n)
        {
            
            temp = min(ugly[p2]*2, min(ugly[p3]*3, ugly[p5]*5));
            // cout<<temp<<" ";
            ugly.push_back(temp);
            if(temp == ugly[p2]*2)
                p2++;
            if(temp == ugly[p3]*3)
                p3++;
            if(temp == ugly[p5]*5)
                p5++;
        }
        return ugly[n-1];
        
        
    }
};
