class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int span = n / 4 + 1;

        for (auto i = 0; i < n; i += span) {
            auto lower_itr = lower_bound(arr.begin(), arr.end(), arr[i]);
            auto upper_itr = upper_bound(arr.begin(), arr.end(), arr[i]);
            if (upper_itr - lower_itr >= span) {
                return arr[i];
            }
        }
        return -1;

        // int n = arr.size();
        // int cur = arr[0];
        // int cnt = 0;

        // for (auto e : arr) {
        //     if (cur == e) {
        //         cnt++;
        //         if (cnt * 4 > n) {
        //             return cur;
        //         }
        //     } else {
        //         cur = e;
        //         cnt = 1;
        //     }
        // }
        // return -1;
    }
};




class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int span = n / 4 + 1;
        for (int i = 0; i < n; i += span) {
            auto [iter_l, iter_r] = equal_range(arr.begin(), arr.end(), arr[i]);
            if (iter_r - iter_l >= span) {
                return arr[i];
            }
        }
        return -1;
    }
};
