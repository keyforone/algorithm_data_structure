bool wordPattern(string pattern, string str)
{
    string strmap[26];
    map<string, char> substrsets;

    int head, tail;
    head = tail = 0;
    bool start = false;
    int counter = 0;
    for(int i = 0; i <= str.size(); i++)
    {
	if(!start)
	{
	    if(i == str.size() || str[i] == ' ') continue;
	    start = true;
	    head = i;
	    counter++;
	}
	else
	{
	    if(i != str.size() && str[i] != ' ') continue;
	    tail = i;
	    start = false;

	    string s = str.substr(head, tail-head);
	    char c = pattern[counter-1];

	    if(substrsets.find(s) == substrsets.end())
	    {
		if(!strmap[c-'a'].empty())
		    return false;
		strmap[c-'a'] = s;
		substrsets[s] = c;
	    }
	    else
	    {
		if(strmap[c-'a'].empty())
		    return false;
		if(substrsets[s] != c)
		    return false;
	    }
	}
    }

    return counter == pattern.size();
}
