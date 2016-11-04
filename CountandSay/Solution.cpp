string countAndSay(int n)
{
    string s;
    
    if(n <= 0) return s;

    for(int i = 1; i <= n; i++)
    {
	if(s.empty()) { s  = "1"; continue; }

	stringstream ss;
	int counts = 1;
	for(int j = 1; j < s.size(); j++)
	{
	    if(s[j] == s[j-1])
	    {
		counts++;
	    }
	    else
	    {
		ss << counts << s[j-1];
		counts = 1;
	    }
	}
	ss << counts << s[s.size()-1];
	
	s = ss.str();
    }

    return s;
}
