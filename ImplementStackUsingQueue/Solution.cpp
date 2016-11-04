class Stack {
    public:
	    // Push element x onto stack.
	    void push(int x) {
		if(primary.empty() && secondry.empty()) primary.push(x);
		else if(primary.empty()) secondry.push(x);
		else if(secondry.empty()) primary.push(x);
	    }
	    
	    // Removes the element on top of the stack.
	    void pop() {
		if(primary.empty())
		{
		    int len = secondry.size();
		    for(int i = 0; i < len; i++)
		    {
			if(i != (len-1))
			    primary.push(secondry.front());
			secondry.pop();
		    }
		}
		else
		{
		    int len = primary.size();
		    for(int i = 0; i < len; i++)
		    {
			if(i != (len-1))
			    secondry.push(primary.front());
			primary.pop();
		    }
		}
	    }
	    
	    // Get the top element.
	    int top() 
	    {
		if(primary.empty()) return secondry.back();
		else return primary.back();
	    }
	    
	    // Return whether the stack is empty.
	    bool empty() {
		return primary.empty() && secondry.empty();
	    }
    private:
	    queue<int> primary;
	    queue<int> secondry;
};
