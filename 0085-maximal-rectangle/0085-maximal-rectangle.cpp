class Solution {
public:
    int largestHistArea(vector<int>& heights) {
        heights.push_back(0);       
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        heights.pop_back();           
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            maxArea = max(maxArea, largestHistArea(heights));
        }

        return maxArea;
    }
};