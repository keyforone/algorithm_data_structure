class Queue 
{
public:
Queue()
{
    on_primary = true;
}

void reverseStack(stack<int>& from, stack<int>& to)
{
    while(!from.empty())
    {
	to.push(from.top());
	from.pop();
    }
}
// Push element x to the back of queue.
void push(int x)
{
    if(on_primary) 
    {
	primary.push(x);
    }
    else
    {
	reverseStack(secondry, primary);
	primary.push(x);
	on_primary = true;
    }
}

// Removes the element from in front of queue.
void pop(void)
{
    if(on_primary)
    {
	reverseStack(primary, secondry);
	secondry.pop();
	on_primary = false;
    }
    else
	secondry.pop();
}

// Get the front element.
int peek(void)
{
    if(on_primary)
    {
	reverseStack(primary, secondry);
	on_primary = false;
	return secondry.top();
    }
    else
	return secondry.top();
}

// Return whether the queue is empty.
bool empty(void)
{
    return on_primary ? primary.empty() : secondry.empty();
}

private:

stack<int> primary;
stack<int> secondry;
bool on_primary;

};
