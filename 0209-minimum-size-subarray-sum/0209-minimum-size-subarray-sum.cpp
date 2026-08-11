class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_length = INT_MAX;
        int current_sum = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            current_sum += nums[right];

           
            while (current_sum >= target) {
                min_length = min(min_length, right - left + 1);
                current_sum -= nums[left];
                left++;
            }
        }

        return min_length == INT_MAX ? 0 : min_length;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna