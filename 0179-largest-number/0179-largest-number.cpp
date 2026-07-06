class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        
        // Custom comparator to sort strings based on concatenation
        sort(strNums.begin(), strNums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        // Edge case: if the largest number is "0", the result is just "0"
        if (strNums[0] == "0") {
            return "0";
        }
        
        // Concatenate all strings
        string result = "";
        for (const string& str : strNums) {
            result += str;
        }
        
        return result;
    }
};