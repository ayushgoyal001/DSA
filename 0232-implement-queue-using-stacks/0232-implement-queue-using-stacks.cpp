class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()!=true){
            int x = s2.top();
            s2.pop();
            return x;
        }
        else{
            int s = s1.size();
            for(int i = 0; i<s;i++){
                s2.push(s1.top());
                s1.pop();
            }
            int x = s2.top();
            s2.pop();
            return x;
        }
       
    }
    
    int peek() {
          if(s2.empty()!=true){
          return s2.top();
        }
        else{
            int s = s1.size();
            for(int i = 0; i<s;i++){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        return s2.empty()&&s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */