// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.

//brute force
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = 0;
                for(int k = i; k <= j; k++){
                    sum = sum + nums[k];
                }
                maxi = max(maxi, sum);

            }
        }
        return maxi;
    }
};
// First, we will run a loop(say i) that will select every possible starting index of the subarray. The possible starting indices can vary from index 0 to index n-1(n = size of the array).
// Inside the loop, we will run another loop(say j) that will signify the ending index of the subarray. For every subarray starting from the index i, the possible ending index can vary from index i to n-1(n = size of the array).
// After that for each subarray starting from index i and ending at index j (i.e. arr[i….j]), we will run another loop to calculate the sum of all the elements(of that particular subarray).

//better solution
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                
                sum = sum + nums[j];
                maxi = max(maxi, sum);

            }
        }
        return maxi;
    }
};
//  If we carefully observe, we can notice that to get the sum of the current subarray we just need to add the current element(i.e. arr[j]) to the sum of the previous subarray i.e. arr[i….j-1].

// Assume previous subarray = arr[i……j-1]
// current subarray = arr[i…..j]
// Sum of arr[i….j] = (sum of arr[i….j-1]) + arr[j]

// This is how we can remove the third loop and while moving j pointer, we can calculate the sum.

//optimal solution
//KADANE'S ALGORITHM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();    
        long long maxi = LONG_MIN;
        long long sum = 0;

        for (int i = 0; i < n; i++) {

            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;
            }

    
            if (sum < 0) {
                sum = 0;
            }
        }

    return maxi;
}
    
};
//you wont believe but i initially thought of this too.