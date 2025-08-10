class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int candidate=nums[0];
        for(int i=1; i<n; i++){
          if(nums[i]==candidate)count++;
          else count--;
          if(count==0){
            candidate=nums[i];
            count=1;
          }
        }return candidate;
        
    }
};
// We use the Boyer–Moore Majority Vote Algorithm to find the majority element in O(n) time and O(1) space.
// The algorithm has two main ideas:
// Keep a candidate element and a count.
// Traverse the array:
// If the current element equals the candidate → increment count.
// Else → decrement count.
// If count becomes 0 → choose the current element as the new candidate and reset count to 1.
// Since the majority element appears more than ⌊n/2⌋ times, it will survive as the candidate at the end.