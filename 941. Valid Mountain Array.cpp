// Given an array of integers arr, return true if and only if it is a valid mountain array.

// Recall that arr is a mountain array if and only if:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

// Example 1:

// Input: arr = [2,1]
// Output: false
// Example 2:

// Input: arr = [3,5,5]
// Output: false
// Example 3:

// Input: arr = [0,3,2,1]
// Output: true


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        int i = 0, j = arr.size() - 1;
        while (i < arr.size()-1 && arr[i] < arr[i+1]) {
            i++;
        }
        while (j > 0 && arr[j] < arr[j-1]) {
            j--;
        }
        return (i == j) && (i != 0) && (j != arr.size()-1);
        
        // if (arr.size() < 3) {
        //     return false;
        // }
        // int inc_cnt = 0, dec_cnt = 0;
        // for (auto i = 1; i < arr.size(); i++) {
        //     if (arr[i] == arr[i-1]) {
        //         return false;
        //     } else if (arr[i] > arr[i-1]) {
        //         if (dec_cnt) {
        //             return false;
        //         }
        //         inc_cnt++;
        //     } else {
        //         if (inc_cnt == 0) {
        //             return false;
        //         }
        //         dec_cnt++;
        //     }
        // }
        // return ((dec_cnt > 0) && (inc_cnt > 0));
    }
};
