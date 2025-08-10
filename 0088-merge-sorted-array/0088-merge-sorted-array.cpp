class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1; //last element of nums1
        int j=n-1; //last element of nums2
        int k=m+n-1; 
        while(i>=0 && j>=0){ //start traversing from the end of nums1 and filling the greater element through two pointer approach
            if(nums1[i]>nums2[j]){
                nums1[k]=nums1[i];
                i--;
            }
            else{
                nums1[k]=nums2[j];
                j--;
            }
            k--;
            
        }
        //if elements of nums2 are still remaining, directly add them in nums1
        while(j>=0){
            nums1[k]=nums2[j];
            j--;
            k--;
        }
        
    }
};