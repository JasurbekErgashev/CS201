class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> even, odd;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        vector<int> ans;
        int e = 0, o = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                ans.push_back(even[e]);
                e++;
            }else{
                ans.push_back(odd[o]);
                o++;
            }
        }
        return ans;
    }
};
