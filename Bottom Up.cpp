class Solution {
public:
    /**
     * Function to find the largest divisible subset from the given array.
     * A subset S is considered valid if for every pair (Si, Sj), either Si % Sj == 0 or Sj % Si == 0.
     */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Edge case: if the array contains only one element, return it
        if (nums.size() == 1)
            return nums;

        int n = nums.size();
        vector<int> ans(n, 1);   // ans[i]: length of the largest subset ending at index i
        vector<int> last(n, -1); // last[i]: stores the index of the previous element in the subset ending at i

        // Initialize each element to point to itself (for reconstruction purposes)
        for (int i = 0; i < n; i++)
            last[i] = i;

        sort(nums.begin(), nums.end()); // Sort the array to ensure increasing order for divisibility checks

        int endbestindex = 0;  // Stores the index where the largest subset ends
        int maxlength = 1;     // Length of the largest subset found

        // Build the DP table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // Check if nums[i] is divisible by nums[j]
                if (nums[i] % nums[j] == 0) {
                    // If including nums[i] increases the size of subset ending at i
                    if (ans[j] + 1 > ans[i]) {
                        ans[i] = ans[j] + 1;
                        last[i] = j;  // Update path for reconstruction
                    }

                    // Update the max length and its ending index if needed
                    if (maxlength < ans[i]) {
                        maxlength = ans[i];
                        endbestindex = i;
                    }
                }
            }
        }

        // Reconstruct the subset using 'last' array
        vector<int> answer;
        int prev = -1;
        while (endbestindex != prev) {
            answer.push_back(nums[endbestindex]);
            prev = endbestindex;
            endbestindex = last[endbestindex];
        }

        // Subset is already in correct order (ascending)
        return answer;
    }
};
