// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

//Brute Force approach
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int count_i = 0;
            for(int j = 0; j < n; j++){
                    if(nums[i] == nums[j]){
                        count_i++;
                    }
            }
            if (count_i > n/2){
                return nums[i];
            }
        }
        return -1;
        
    }

};
//since the time complexity is O(n*n), therefore some test cases with bulky array inputs exceed time limits. there fore, we seek to apply an algorithm that takes linear time complexity.

//better solution using hash maps
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    int n = nums.size();

    //declaring a map:
    map<int, int> mpp;

    //storing the elements with its occurnce:
    for (int i = 0; i < n; i++) {
        mpp[nums[i]]++;
    }
    for (auto it : mpp) {
        if (it.second > (n / 2)) {
            return it.first;
        }
    }

    return -1;
    }
};

//Moore's Voting algorithm 
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int counter = 0, element = NULL;

        for(int i = 0; i < n; i++){
            if(counter == 0){
                counter = 1;
                element = nums[i];
            }
            else if(element == nums[i]){
                counter++;
            }
            else{
                counter--;
            }
            
        }

        int counter_2 = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == element){
                counter_2++;
            }
        }

        if(counter_2 > n/2){
            return element;
        }
        else{
            return -1;
        }
        
    }
};
// Initialize 2 variables:
// Count –  for tracking the count of element
// Element – for which element we are counting
// Traverse through the given array.
// If Count is 0 then store the current element of the array as Element.
// If the current element and Element are the same increase the Count by 1.
// If they are different decrease the Count by 1.
// The integer present in Element should be the result we are expecting 