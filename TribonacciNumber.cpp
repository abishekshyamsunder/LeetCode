class Solution {
public:
    int tribonacci(int n) {
        int trib0 = 0;
        int trib1 = 1;
        int trib2 = 1;
        
        for(int i=3;i<=n;i++)
        {
            int temp = trib0;
            trib0 = trib1;
            trib1 = trib2;
            trib2 = trib2 + trib0 + temp;
            // cout<<temp<<" "<<trib0<<" "<<trib1<<" "<<trib2<<" "<<endl;
        }
        if(n>=3)
            return trib2;
        else if(n==2 || n==1)
            return 1;
        else
            return 0;
        
        
    }
};
