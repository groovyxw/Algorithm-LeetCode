// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 

// Constraints:

// 1 <= nums.length <= 5000
// -104 <= nums[i] <= 104
// All values of nums are unique.
// nums is an ascending array that is possibly rotated.
// -104 <= target <= 104


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int sz = nums.size();
        if (sz == 0) {
            return -1;
        }
        int s = 0, e = sz - 1;
        while (s + 1 < e) {
            int mid = s + (e - s)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[s] < nums[mid]) {
                if (target >= nums[s] && target < nums[mid]){
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            } else{
                if (target > nums[mid] && target <= nums[e]) {
                    s = mid + 1;
                } else {
                    e = mid - 1;
                }
            }
        }
        if (nums[s] == target) {
            return s;
        }
        if (nums[e] == target ) {
            return e;
        }
        return -1;
    }

    //     int n = (int)nums.size();
    //     if (!n) {
    //         return -1;
    //     }
    //     if (n == 1) {
    //         return nums[0] == target ? 0 : -1;
    //     }
    //     int l = 0, r = n - 1;
    //     while (l <= r) {
    //         int mid = (l + r) / 2;
    //         if (nums[mid] == target) return mid;
    //         if (nums[0] <= nums[mid]) {
    //             if (nums[0] <= target && target < nums[mid]) {
    //                 r = mid - 1;
    //             } else {
    //                 l = mid + 1;
    //             }
    //         } else {
    //             if (nums[mid] < target && target <= nums[n - 1]) {
    //                 l = mid + 1;
    //             } else {
    //                 r = mid - 1;
    //             }
    //         }
    //     }
    //     return -1;
    // }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         if(!n) return -1;
        
//         int left = 0, right = n-1;
//         while(left <= right){
//             int mid = left + (right - left)/2;
//             if(nums[mid] == target){
//                 return mid;
//             }
//             if(nums[mid] >= nums[left]){
//                 if(nums[left] <= target && target < nums[mid]){
//                     right = mid - 1;
//                 }else{
//                     left = mid + 1;
//                 }
//             }else{
//                 if(target <= nums[right-1] && target > nums[mid]){
//                     left = mid + 1;
//                 }else{
//                     right = mid - 1;
//                 }
//             }
//             //cout<<"mid="<<mid<<" left="<<left<<" right="<<right<<endl;
//         }
        
//         return -1;
//     }
// };
