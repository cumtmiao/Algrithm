/*
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
*/
//采用random_shuffle()函数，随机返回一个序列的随机序列。
class Solution {
public:
    Solution(vector<int> nums) {
        for(int i=0;i<nums.size();i++)
        {
            data.push_back(nums[i]);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return data;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res;
        for(int i=0;i<data.size();i++)
        {
            res.push_back(data[i]);
        }
        random_shuffle(res.begin(),res.end());
        return res;
    }
    vector<int> data;
};