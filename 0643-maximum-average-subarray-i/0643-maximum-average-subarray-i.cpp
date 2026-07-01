class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      int n = nums.size();
        long long current= 0;
        for(int i=0;i<k;i++){
            current+=(nums[i]);
        }
        int max=current;
        for(int i=k;i<n;i++){
            current+=nums[i]-nums[i-k];
            if (current>max){
            max=current;
            }
        }
        return (double)max/ k;
    }
    
};