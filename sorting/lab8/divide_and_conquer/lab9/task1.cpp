class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> appears;
        for(int i = 0; i < n; i++){
            appears[nums[i]]++;
        }
        for(auto a : appears){
            if(a.second > floor(n/2))
                return a.first;
        }
        return -1;
    }
};
