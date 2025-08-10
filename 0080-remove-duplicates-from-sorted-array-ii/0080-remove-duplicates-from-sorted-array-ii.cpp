class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n;
        int k=2;
        for(int i=2; i<n; i++){
            //compare the current element with element at position k-2
            //if they are different current one can stay
            if(nums[i]!=nums[k-2]){
                nums[k]=nums[i];  //overwrite the element at kth position and increment k by 1
                k++;
            }
        }return k;
    }
};