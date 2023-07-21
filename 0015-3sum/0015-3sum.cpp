class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
            sort(nums.begin(),nums.end());
        set<vector<int>> result;
        vector<vector<int>> res;

        for(int i = 0; i < nums.size(); i++){
            int left,right;
            left = i + 1;
            right = nums.size() - 1;
            if(i > 0 && nums[i] == nums[i - 1]){    
                continue;
            }
            if (nums[i] > 0){
                break;
            }
            while(left < right){
                int check = nums[i] + nums[left] + nums[right];
                if (check == 0){
                    result.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (check < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
       for(auto triplets : result)
            res.push_back(triplets);
        return res;
    }
};