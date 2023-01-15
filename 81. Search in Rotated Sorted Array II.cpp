// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

 

// Example 1:

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// nums is guaranteed to be rotated at some pivot.
// -104 <= target <= 104
 

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;

        while ( e > 0 && nums[e] == nums[s]) {
            --e;
        }
        
        while (s + 1 < e) {
            int mid = s + (e - s)/2;
            if ((nums[mid] == target) || (nums[s] == target) || (nums[e] == target)) {
                return true;
            } else if (nums[s] <= nums[mid]) {
                if (nums[s] < target && target < nums[mid]) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }

        }
        return (nums[s] == target || nums[e] == target);


        // int n = nums.size();
        // if (0 == n) {
        //     return false;
        // }
        // if ( 1 == n) {
        //     return nums[0] == target;
        // }
        // int left = 0, right = n -1;
        // while (left <= right) {
        //     int mid = left + (right - left)/2;
        //     if (nums[mid] == target) {
        //         return true;
        //     }

        //     if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
        //         ++left;
        //         --right;
        //     } else if(nums[left] <= nums[mid]) {
        //         if (target >= nums[left] && target < nums[mid]) {
        //             right = mid - 1;
        //         } else {
        //             left = mid + 1;
        //         }
        //     } else {
        //         if (target > nums[mid] && target <= nums[right]) {
        //             left = mid + 1;
        //         } else {
        //             right = mid - 1;
        //         }
        //     }
        // }
        // return false;


    }
};
