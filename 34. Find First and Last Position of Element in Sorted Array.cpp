// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]

//因为取中点除2的运算是偏左的
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {-1,-1};
        }
        int s = 0, e = nums.size() - 1;
        int first = binarySearch(nums, target, true);
        if (first == -1) {
            return {-1, -1};
        }
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
    int binarySearch(vector<int> &nums, int target, bool firstorlast) {
        int s = 0, e = nums.size() - 1;
        while (s + 1 < e) {
            int mid = s + (e - s)/2;
            if (nums[mid] == target) {
                if (firstorlast) {
                    e = mid;
                } else {
                    s = mid;
                }
            } else if (nums[mid] < target) {
                s = mid;
            } else {
                e = mid;
            }
        }
        int first = -1, last = -1;
        if (firstorlast) {
            if (nums[e] == target) {
                first = e;
            }
            if (nums[s] == target) {
                first = s;
            }
            return first;
        } else {
            if (nums[s] == target) {
                last = s;
            }
            if (nums[e] == target) {
                last = e;
            }
            return last;
        }
        return -1;
    }


    //     if(nums.size() == 0) {
    //         return {-1,-1};
    //     }
    //     int leftIndex = binarySearch(nums, target, true);
    //     if(nums[leftIndex] != target){
    //         return {-1, -1};
    //     }
    //     //cout<<"Find the last element......"<<endl;
    //     int rightIndex = binarySearch(nums, target, false);
    //     return {leftIndex, rightIndex};
        
    // }
    // int binarySearch(vector<int>& nums, int target, bool lower) {
    //     int left = 0, right = nums.size() - 1;
    //     while(left < right) {
    //         int mid = (left + (right - left)/2);
    //         //cout<<"left="<<left<<" right="<<right<<" mid="<<mid<<endl;
    //         if(nums[mid] == target) {
    //             if(lower) {
    //                 right = mid;
    //             }else {
    //                 left = mid + 1;
    //             }
    //         }else if(nums[mid] > target) {
    //             right = mid - 1;
    //         }else {
    //             left = mid + 1;
    //         }
    //     }
    //     if(!lower){
    //         if(nums[left] == target){
    //             return left;
    //         }else{
    //             return left - 1;
    //         }
    //     }
    //     return left;
    // }
    
};
