class Solution {
public:
    double helper(double x, long long n){
        //base case, n==0
        if(n==0)return 1.0;
        double half=helper(x, n/2);
        // If n is even: just square the half
        if(n%2==0)return half*half;
        // If n is odd: square the half and multiply by x once more
        else return half*half*x;
    }
    double myPow(double x, int n) {
        //convert to long long to handle INT_MIN properly
        long long power=n;
        return power<0?1.0/helper(x, -power):helper(x,power);
    }
};