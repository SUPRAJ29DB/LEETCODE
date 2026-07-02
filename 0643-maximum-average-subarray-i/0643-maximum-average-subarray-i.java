class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n=nums.length;
        double curr=0;
        for(int i=0;i<k;i++){
            curr+=nums[i];
        }
        double max=curr;
        for(int i=k;i<n;i++){
            curr+=nums[i]-nums[i-k];
            if(curr>max) max=curr;
            
        }
        return max/ k;
    }
}