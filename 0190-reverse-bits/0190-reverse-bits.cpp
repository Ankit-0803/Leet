class Solution {
public:
    int reverseBits(int n) {
        unsigned int result =0;
        for(int i=0; i<32; i++){
            int bit=n&1; //extracts the last bit of n
            result=(result<<1)|bit; 
            n>>=1; //shift n right to process to next bit
        }
        return result;
    }
};