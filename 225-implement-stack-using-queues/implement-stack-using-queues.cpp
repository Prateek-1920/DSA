class MyStack {
public:
    queue<int> main;
    queue<int> aux;
    MyStack() {
        
    }
    
    void push(int x) {
        aux.push(x);
        while(!main.empty()){
            aux.push(main.front());
            main.pop();
        }
        while(!aux.empty()){
            main.push(aux.front());
            aux.pop();
        }
    }
    
    int pop() {
        int ans = main.front();
        main.pop();
        return ans;
    }
    
    int top() {
        return main.front();
    }
    
    bool empty() {
        if(main.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */