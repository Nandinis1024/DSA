// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

//Brute Force
class Solution {
public:

    int linearSearch(vector<int>& nums, int x){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == x){
                return true;
            }
        }
        return false;

    }


    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), maxCount = 1;
        if(n == 0){
            return 0;
        }
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int count = 1;
            while(linearSearch(nums, x + 1) == true){
                x++;
                count++;
            }
            maxCount = max(maxCount, count);
        
        }
        return maxCount;
    }
};

//better
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), count = 1, maxCount = 1;
        if(n == 0){
            return 0;
        } 

        // map<int, int> freq;
        // for(int i = 0; i < n; i++){
        //     freq[i]++;
        // }

        sort(nums.begin(), nums.end());
        
        for(int i = 1;  i < n; i++){
            cout << count << " " << maxCount << endl;
            if(nums[i] != nums[i - 1]){
                if(nums[i] -  nums[i - 1] == 1){
                count++;
                maxCount = max(maxCount, count);
            }
            else {
                maxCount = max(maxCount, count);

                count = 1;

            }
            }
            
        }
                maxCount = max(maxCount, count);

        return maxCount ; 
    }
};

//optimal(using set)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), maxCount = 1;
        if(n == 0){
            return 0;
        }

        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int count = 1;
                int x = it;

                while(st.find(x + 1) != st.end()){
                    x = x + 1;
                    count = count + 1;
                }
                maxCount = max(maxCount,  count);
            }
        }
        return maxCount;
    
        
    }
};