class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int element = 0;
        int maxarea = 0;
        int n = heights.size();
        for(int i = 0 ; i<n; i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                maxarea= max(maxarea,heights[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
           int nse = n;
           element = st.top();
           st.pop();
           int pse = st.empty()?-1:st.top();
            maxarea= max(maxarea,heights[element]*(nse-pse-1));
        }
        return maxarea;
    }
};