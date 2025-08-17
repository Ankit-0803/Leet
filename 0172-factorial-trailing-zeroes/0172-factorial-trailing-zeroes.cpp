class Solution {
public:
    int trailingZeroes(int n) {
        int count =0;
        //keep dividing n by 5 and add to count
        while(n>0){
        n/=5;
        count+=n;
        }
        return count;
    }
};