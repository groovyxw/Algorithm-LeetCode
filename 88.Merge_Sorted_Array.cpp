class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1;
        int index2 = n - 1;
        int index = m + n - 1;

        while (index1 >= 0 && index2 >= 0) {
            if (nums1[index1] > nums2[index2]) {
                nums1[index--] = nums1[index1--];
            } else {
                nums1[index--] = nums2[index2--];
            }
        }
        while (index1 >= 0) {
            nums1[index--] = nums1[index1--];
        }
        while (index2 >= 0) {
            nums1[index--] = nums2[index2--];
        }
        return;
        
        // int index1 = m - 1;
        // int index2 = n - 1;
        // int index = m + n - 1;
        // while(index2 >= 0){
        //     if(index1 >= 0){
        //         if(nums1[index1] > nums2[index2]){
        //             nums1[index--] = nums1[index1--];
        //         }else{
        //             nums1[index--] = nums2[index2--];
        //         }
        //     }else{
        //         nums1[index--] = nums2[index2--];
        //     }
        // }
    }
};

//Follow up in python
public class Solution {
    /*
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    public int[] mergeSortedArray(int[] A, int[] B) {
        if(A == null || A.length == 0) return B;
        if(B == null || B.length == 0) return A;
        int[] res = new int[A.length + B.length];
        int idx = 0;
        int pa = 0;
        for(int i=0;i<B.length;i++){
            int position = binarySearch(A, B[i]);
            while(pa < position){
                res[idx++] = A[pa++];
            }
            res[idx++] = B[i];
        }
        while(pa < A.length){
            res[idx++] = A[pa++];
        }
        return res;
    }
    
    private int binarySearch(int[] A, int target){
        int left = 0;
        int right = A.length-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(A[mid] == target) return mid;
            if(target < A[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }
}
