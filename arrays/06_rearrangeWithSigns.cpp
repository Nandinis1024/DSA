// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should rearrange the elements of nums such that the modified array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.


//brute force
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int k = 0, l = 0;
        vector<int>positiveArray(n);
        vector<int>negativeArray(n);

        for (int i = 0; i < n; i++){
            if(nums[i] > 0){
                positiveArray[k] = nums[i];
                k++;
            }
            else if(nums[i] < 0){
                negativeArray[l] = nums[i];
                l++;
            }
        }
        // for(int i = 0; i < n; i++){
        // cout<<positiveArray[i]<<endl;
        // cout<< negativeArray[i]<<endl;
        // }
        int z = 0;
        for(int i = 0; i < n; i+=2){
            nums[i] = positiveArray[z];
            nums[i+1] = negativeArray[z];
            z++;
        }
        return nums;
    }

};

//optimal approach
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        int posIndex = 0;
        int negIndex = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                ans[posIndex] = nums[i];
                posIndex = posIndex + 2;
            }
            else if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex = negIndex + 2;
            }

        }

        return ans;
    }

};