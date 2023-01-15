// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4
// Example 2:

// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1
 

// Constraints:

// 1 <= nums.length <= 104
// -104 < nums[i], target < 104
// All the integers in nums are unique.
// nums is sorted in ascending order.


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while ( s + 1 < e) {
            int mid = s + (e - s)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }

            
        }
        if (nums[s] == target) {
            return s;
        }
        if (nums[e] == target) {
            return e;
        }
        return -1;
      
      
        // int left = 0, right = nums.size()-1;
        // //cout<<left<<" "<<right<<endl;
        // while(left <= right) {
        //     int mid = left + (right - left) / 2;
        //     if(nums[mid] == target) {
        //         return mid;
        //     }else if(nums[mid] > target) {
        //         right = mid - 1;
        //     }else {
        //         left = mid + 1;
        //     }
        //     //cout<<left<<" "<<right<<endl;
        // }
        // return -1;
    }
};
