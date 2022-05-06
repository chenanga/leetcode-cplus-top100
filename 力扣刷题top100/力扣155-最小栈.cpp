#include<iostream>
#include<stack>


using namespace std;

// class MinStack {
// public:
//     MinStack() {
//         minStack.push(INT_MAX);
//     }

//     void push(int val) {
//         myStack.push(val);
//         if (val <= minStack.top()) //这里取等于是万一有几个相同元素入栈，最后出栈时候也需要11对应出栈。如果只有一个入最小栈，出栈了一个，最小栈的元素就出去，后续元素都更大。所以使用等号，让所有相等的都如栈
//             minStack.push(val);
//     }

//     void pop() {
//         if (minStack.top() == myStack.top())
//             minStack.pop();
//         myStack.pop();
//     }

//     int top() {
//         return myStack.top();
//     }

//     int getMin() {
//         return minStack.top();
//     }
// private:
//     stack<int> minStack;
//     stack<int> myStack;
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 //大佬题解，往栈里面插元组
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if (st.size() == 0) {
            st.push({ x, x });
        }
        else {
            st.push({ x, min(x, st.top().second) });
        }
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
private:
    stack<pair<int, int>> st;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */



int main() {

	system("pause");
	return 0;
}