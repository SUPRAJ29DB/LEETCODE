class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int n=nums.size();
        // int freq=0, nums=0;
        //bruteforce
        // for(int i=0;i<n;i++){
        //     int freq=0;
        //     for(int j=0;j<n;j++){
        //         if (nums[i]==nums[j])
        //         freq++;
        //     }
        //     if (freq>n/2){
        //         return nums[i];
        //     }
        // }
        // return -1;
        int count = 0;
        int candidate = 0;

        for (int x : nums) {
            if (count == 0)
                candidate = x;

            if (candidate == x)
                count++;
            else
                count--;
        }

        return candidate;
        }
    
};