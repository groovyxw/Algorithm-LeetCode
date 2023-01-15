// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// You must write an algorithm with O(log n) runtime complexity.


// Example 1:

// Input: nums = [1,3,5,6], target = 5
// Output: 2
// Example 2:

// Input: nums = [1,3,5,6], target = 2
// Output: 1
// Example 3:

// Input: nums = [1,3,5,6], target = 7
// Output: 4
 
// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
     
        int s = 0, e = nums.size() - 1;
        if (nums[s] >= target) {
            return s;
        }
        if (nums[e] < target) {
            return e + 1;
        }
        
        while (s + 1 < e) {
            int mid = s + (e - s)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                e = mid;
            } else {
                s = mid;
            }
        }
        
        return e;
     
     
     
     
//         int s = 0, e = nums.size() - 1;

//         while (s + 1 < e) {
//             int mid = s + (e - s)/2;
//             if (nums[mid] == target) {
//                 return mid;
//             } else if (nums[mid] > target) {
//                 e = mid - 1;
//             } else {
//                 s = mid + 1;
//             }
//         }
//         if (nums[s] >= target) {
//             return s;
//         }
//         if (nums[e] < target) {
//             return e + 1;
//         }
//         return e;
     
     
        // int left = 0, right = nums.size() - 1;
        // while(left <= right) {
        //     int mid = left + (right - left)/2;
        //     if(nums[mid] == target) {
        //         return mid;
        //     }else if(nums[mid] < target) {
        //         left = mid + 1;
        //     }else {
        //         right = mid - 1;
        //     }
        // }
        // return left;
    }
};
