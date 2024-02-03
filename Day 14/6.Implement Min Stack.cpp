class MinStack {
public:
    stack<long long int> s;
    long long int min;

    MinStack() {}

    void push(long long int val) {
        if (s.empty()) {
            min = val;
            s.push(val);
        } else if(val >= min) {
            s.push(val);
        } else if (val < min) {
            s.push((2 * val)-min);
            min = val;
        }
    }

    void pop() {
        if(s.top()>=min){
            s.pop();
        }else if(s.top()<min){
            min = (2*min)-s.top();
            s.pop();
        }
    }

    long long int top() { 
        if(s.empty())return -1;
        else if(s.top()>=min)return s.top();
        else return min;
    }

    long long int getMin() { return s.empty() ? 0 : min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */