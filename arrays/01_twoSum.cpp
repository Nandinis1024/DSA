//Brute Force Approach

//In this approach, we run a loop to pick each element of the array. for ech element, we run another loop that picks each element and checks if both of their sum equals the target input provided. if yes, we simply return the first pair we come accross. 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, j = 0, m = 0, n = 0;
        for (; i < nums.size(); i++){
            for(j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){

                    m = i;
                    n = j;
                    break;
                }
            }
        }
        return {m, n};
    }
};
//Optimal Approach
//This is a two pointer approach. here, we run a pointer that runs from index 0 (i) and another one that runs from the last index (j). we run a loop while i < j. there are three conditions we check
// If arr[i] + arr[j] > sum, we will decrement the right pointer.
// If arr[i] + arr[j] < sum, we will increment the left pointer.
// If arr[i] + arr[j] == sum, we will return the result.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size(),i = 0, j = n-1;
        sort(nums.begin(), nums.end());
        while (i < j){
            if(nums[i] + nums[j] > target){
                j--;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else if(nums[i] + nums[j] == target){
                break;
            }
        }
        return {i, j};

        
    }
};
//however this approach has a problem that if theyy ask u to return the indices, then u return the indices of the sorted array and not the original array. this will give wrong answer if the original array is already not sorted. so you can do things like, create a copy of the original array in the beginning. when u find the pair that adds to the desired sum via two pointer method. you compare the actual indes of these elements in the original array and return those indexes.
//like this:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> original(n);

        for (int i = 0; i < n; i++) {
            original[i] = nums[i];
        }
        for (int i = 0; i < n; i++) {
            cout << original[i] << endl;
        } 
        
        int i = 0, j = n-1, x = 0, y = 0;
        sort(nums.begin(), nums.end());
        while (i < j){
            if(nums[i] + nums[j] > target){
                j--;
            }
            else if(nums[i] + nums[j] < target){
                i++;
            }
            else if(nums[i] + nums[j] == target){
                break;
            }
        }
        for (int k = 0; k < n; k++) {
            if(original[k] == nums[i]){
                x = k;
                break;
            }
        }

         for (int k = 0; k < n; k++) {
            if(original[k] == nums[j]){
                y = k;
            }
        }
        
       return {x, y}; 
    }
};