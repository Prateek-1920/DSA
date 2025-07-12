class MyQueue {
public:
    stack<int> main;
    stack<int> aux;
    MyQueue() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        if(aux.empty()){
            while(!main.empty()){
                aux.push(main.top());
                main.pop();
            }
        }
        int val = aux.top();
        aux.pop();
        return val;
    }
    
    int peek() {
          if(aux.empty()){
            while(!main.empty()){
                aux.push(main.top());
                main.pop();
            }
        }
        int val = aux.top();
        return val;
    }
    
    bool empty() {
        return main.empty() && aux.empty();
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