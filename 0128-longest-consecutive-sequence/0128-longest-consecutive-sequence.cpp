class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int longest=1, cnt=0, last=INT_MIN;

        for(int x: nums){
            if(x-1==last){
                cnt++;
                last=x;
            }
            else if(last!=x){
                cnt=1;
                last= x;
                 }
              longest=max(longest, cnt);
        }
           return longest;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna