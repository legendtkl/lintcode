class MinStack {
public:
	void push(int x) {
		s1.push(x);
		if(s2.empty() || s2.top()>=x)
			s2.push(x);
	}
	void pop() {
		if(s1.top()==s2.top())
			s2.pop();
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}
	stack<int> s1,s2;
};
