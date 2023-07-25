class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0;i<nums1.size();i++){
            bool sign = false;
            for(int j = 0;j<nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    sign = true;
                }
                if(sign && nums1[i] < nums2[j]){
                    ans.push_back(nums2[j]);
                    sign = false;
                    break;
                }
            }
            if(sign){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};