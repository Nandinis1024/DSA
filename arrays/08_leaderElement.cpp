

//brute force
ector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> ans;
    int n = a.size(), x;
    for(int i = 0; i < n-1; i++){
        bool leader = true;
        for(int j = i + 1; j < n; j++){
            if(a[i] <= a[j]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(a[i]);
        }
    }
    ans.push_back(a[n-1]);
    sort(ans.begin(), ans.end());
    return ans;

}
//optimal
vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> ans;
    int n = a.size(), max = INT_MIN;
    for(int j = n-1; j >= 0; j--){
        if(a[j] > max){
            max = a[j];
            ans.push_back(max);
        }
    }
    return ans;
}