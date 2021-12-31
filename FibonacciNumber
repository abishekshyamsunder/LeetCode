class Solution {
public:
    int fib(int n) {
        int fib0 = 0;
        int fib1 = 1;
        for(int i=1;i<n;i++)
        {
            int temp = fib0;
            fib0 = fib1;
            fib1 = fib1 + temp;
            // cout<<temp<<" "<<fib0<<" "<<fib1<<endl;
        }
        cout<<fib1;
        if(n != 0)
            return fib1;
        else
            return 0;
            
    }
};
