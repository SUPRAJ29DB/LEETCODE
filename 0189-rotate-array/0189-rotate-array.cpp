class Solution {
public:
    void reverse(vector<int> &arr, int l, int r) {
        while (l < r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }

    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k %= n; // Handle cases where k is greater than array length
        
        // 1. Reverse the entire array
        reverse(arr, 0, n - 1);
        
        // 2. Reverse the first k elements
        reverse(arr, 0, k - 1);
        
        // 3. Reverse the remaining elements
        reverse(arr, k, n - 1);
    }
};