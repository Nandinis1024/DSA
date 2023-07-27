// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.


//optimal solution
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                int temp = nums[i];
                nums[i] = nums[k];
                nums[k] = temp;
                k++;
            }
        }
        for(int i = k; i < n; i++){
            if(nums[i] == 1){
                int temp = nums[i];
                nums[i] = nums[k];
                nums[k] = temp;
                k++;
            }
        }
   
    }
};

//better or bruteforce
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int count_0 = 0, count_1 = 0, count_2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                count_0++;
            }
            else if(nums[i] == 1){
                count_1++;
            }
            else if(nums[i] == 2){
                count_2++;
            }
        }
        cout<<count_0<<endl;
        cout<<count_1<<endl;
        cout<<count_2<<endl;

        for(int i = 0; i < count_0; i++){
            nums[i] = 0;
        }
        for(int i = count_0; i < count_0 + count_1; i++){
            nums[i] = 1;
        }
        for(int i = count_0 + count_1; i < n; i++){
            nums[i] = 2;
        }
        
    }
};

//optimal solution
void sortArray(vector<int>& arr, int n) {

    int low = 0, mid = 0, high = n - 1; // 3 pointers

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}