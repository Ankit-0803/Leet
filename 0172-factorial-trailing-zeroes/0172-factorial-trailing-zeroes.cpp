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
// On the first division by 5, we count all numbers divisible by 5.
// On the second division by 5, we’re essentially counting numbers divisible by 25, because they were already counted once before and still survive another division.
// On the third division by 5, we count numbers divisible by 125