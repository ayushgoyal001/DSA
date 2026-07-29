class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cnt1 = 0;
        int cnt2 = 0;
        int el1 = 0 ;
        int el2 = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]==el1){
                cnt1++;
            }
             else if( nums[i]== el2){
                cnt2++;
            }
            else if(cnt1 == 0 && nums[i]!=el2){
                cnt1++;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i]!=el1){
                cnt2++;
                el2 = nums[i];
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int count1 = 0;
        int count2 = 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i]==el1) count1++;
            else if(nums[i]==el2) count2++;
        }
        if(count1 > nums.size()/3) ans.push_back(el1);
        if(count2>nums.size()/3) ans.push_back(el2);
        return ans;
    }
};