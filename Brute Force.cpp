class Solution {
public:
    vector<int> ans;  // Stores the final result: the largest divisible subset

    /**
     * Recursive helper function to explore all subsets satisfying the divisibility condition.
     * 
     * @param nums         The sorted input array.
     * @param i            Current index in nums being considered.
     * @param prevelement  The last element included in the current subset (used for divisibility check).
     * @param current      The current subset being built.
     * @param largeans     Tracks the size of the largest valid subset found so far.
     */
    void helper(vector<int>& nums, int i, int prevelement, vector<int>& current, int &largeans) {
        // Skip further processing if the previous element was 0 to avoid division by zero
        if (prevelement == 0) {
            helper(nums, i + 1, prevelement, current, largeans);
            return;
        }

        // Base case: reached end of the array
        if (i >= nums.size()) {
            // Update the largest subset if the current one is longer
            if (current.size() > largeans) {
                largeans = current.size();
                ans = current;
            }
            return;
        }

        // Include current element if it is divisible by the previous element
        if (nums[i] % prevelement == 0) {
            current.push_back(nums[i]);
            helper(nums, i + 1, nums[i], current, largeans);  // Recurse with updated state
            current.pop_back();  // Backtrack
        }

        // Exclude current element and move forward
        helper(nums, i + 1, prevelement, current, largeans);
    }

    /**
     * Main function to find the largest subset where every pair (Si, Sj) satisfies:
     * Si % Sj == 0 or Sj % Si == 0
     * 
     * @param nums   The input vector of integers.
     * @return       The largest divisible subset.
     */
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort the array to make divisibility predictable
        vector<int> current;             // Temporary vector to build subsets
        int largeans = 0;                // To track the size of the largest subset found

        helper(nums, 0, 1, current, largeans);  // Start with 1 as the first 'prevelement'
        return ans;
    }
};
