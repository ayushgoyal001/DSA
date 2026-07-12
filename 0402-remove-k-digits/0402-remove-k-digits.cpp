class Solution {
public:
    string removeKdigits(string num, int k) {
        string st;
        int n = num.length();
        if(k==n) return "0";
        for(int i = 0; i<n;i++){
            while(!st.empty() && k && st.back() > num[i]){
                st.pop_back();
                k--;
                  }
         if(!st.empty()){
            st.push_back(num[i]);

         }
         else{
            if(num[i]!='0'){
              st.push_back(num[i]);  
            }
         }
        }
        while(k && !st.empty()){
            st.pop_back();
            k--;
        }
        return st.empty()?"0":st;
    }
};