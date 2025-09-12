class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0; 
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)return mid;
            //left half is sorted
            if(nums[low]<=nums[mid]){
                //target is in left half
                if(nums[low]<=target && target<nums[mid]){
                high=mid-1;
                }
                //target is in right half
                else
                low=mid+1;
            }
            //right half is sorted
            else{
                //target is in right half
                if(nums[mid]<target && target<=nums[high]){
                    low=mid+1;
                }
                //target is in left half
                else
                high=mid-1;
            }
        }
        return -1;
    }
};