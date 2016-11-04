bool isValid(string s)
{
    if(s.empty()) return true;

    stack<char> st;
    for(int i = 0; i < s.size(); i++)
    {
	if(st.empty()) { st.push(s[i]); continue; }

	if(s[i] == '(' || s[i] == '[' || s[i] == '{') { st.push(s[i]); continue; }

	if(s[i] == ')')
	{
	    if(st.top() != '(') return false;
	    st.pop(); continue;
	}
	if(s[i] == ']')
	{
	    if(st.top() != '[') return false;
	    st.pop(); continue;
	}
	if(s[i] == '}')
	{
	    if(st.top() != '{') return false;
	    st.pop(); continue;
	}
	return false;
    }

    return st.empty();
}
