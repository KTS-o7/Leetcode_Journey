class MinStack {
public:
    stack<int> s;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int val) {
        if(mins.empty() || mins.top()>=val){
            s.push(val);
            mins.push(val);
        }
        else
            s.push(val);
    }
    
    void pop() {
        if(s.top()==mins.top()){
            s.pop();
            mins.pop();
        }
        else
            s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

// Time complexity: O(1)
// Space complexity: O(n) where n is the number of elements in the stack

// This implements the O(1) getMin() operation.

/*
The minStack will maintain the minimum element for every level
This can also be implemented via a hashing function which will remove the need of minStack
*/

// Approach 2

class MinStack{
    public:
    stack<int>st;
    int minEle;
    MinStack(){
        minEle=INT_MAX;
    }

    void push(int x){
        if(x>=minEle)
            st.push(x);
        else{
            st.push(2*x-minEle);
            minEle=x;
        }
    }

    void pop(){
        if(st.top()<minEle){
            minEle=2*minEle-st.top();
        }
        st.pop();
    }

    int top(){
        if(st.top()<minEle)
            return minEle;
        return st.top();
    }

    int getMin(){
        return minEle;
    }
};