class Solution {
public:
    long double myPow2(int n)
    {
        if(n==-1)
            return (1.0/2);
        else if(n==1)
            return (2.0);
        else if(n == 0)
            return 1;
        long double temp = myPow2(n/2);
        if(n<0)
        {
            temp = temp * temp;
            if(n%2 !=0)
                temp = temp * (1.0/2);
            return temp;
        }
        else if(n>0)
        {
            temp = temp * temp;
            if(n%2 !=0)
                temp = temp * 2;
            return temp;
        }
        return 0;
            
    }
    double myPow(double x, int n) {
        if(n==-1)
            return (1.0/x);
        else if(n==1)
            return (x);
        else if(n == 0)
            return 1;
        double temp = myPow(x, n/2);
        if(n<0)
        {
            temp = temp * temp;
            if(n%2 !=0)
                temp = temp * (1.0/x);
            return temp;
        }
        else if(n>0)
        {
            temp = temp * temp;
            if(n%2 !=0)
                temp = temp * x;
            return temp;
        }
        return 0;
    }
};
