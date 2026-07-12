class Solution {
public:
    vector<int> nge(vector<int>& nums){
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            nge[i] = st.empty()? n:st.top();
            st.push(i);
        }
        return nge;
    }
     vector<int> pse(vector<int>& nums){
        int n = nums.size();
        vector<int> pse(n) ;
        stack<int> st;
        for(int i = 0 ; i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            pse[i] = st.empty()? -1:st.top();
            st.push(i);
        }
        return pse;
    }
     vector<int> nse(vector<int>& nums){
        int n = nums.size();
        vector<int> nse(n) ;
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            nse[i] = st.empty()? n:st.top();
            st.push(i);
        }
        return nse;
    }
     vector<int> pge(vector<int>& nums){
        int n = nums.size();
        vector<int> pge(n) ;
        stack<int> st;
        for(int i = 0 ; i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            pge[i] = st.empty()? -1:st.top();
            st.push(i);
        }
        return pge;
    }
    long long subarrayMaxsum(vector<int>& nums){
        int n = nums.size();
        vector<int> ngee = nge(nums);
        vector<int> pgee = pge(nums);
        long long sum = 0;
        for(int i = 0; i<n;i++){
            int left = i - pgee[i];
            int right = ngee[i] - i;
            long long freq = left * right *1LL;
            long long val = (freq*nums[i]*1LL);
            sum += val;
        }
        return sum;
    }
        long long subarrayMinsum(vector<int>& nums){
        int n = nums.size();
        vector<int> nsee = nse(nums);
        vector<int> psee = pse(nums);
        long long sum = 0;
        for(int i = 0; i<n;i++){
            int left = i - psee[i];
            int right = nsee[i] - i;
            long long freq = left * right *1LL;
            long long val = (freq*nums[i]*1LL);
            sum += val;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long sum = subarrayMaxsum(nums)-subarrayMinsum(nums);
        return sum;
    }
};