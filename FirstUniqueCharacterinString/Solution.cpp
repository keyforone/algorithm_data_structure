int firstUniqChar(string s)
{
    int index[26];
    for(int i = 0; i < 26; i++) index[i] = -1;

    for(int i = 0; i < s.size(); i++)
    {
	if(index[s[i]-'a'] == -1)
	    index[s[i]-'a'] = i; 
	else 
	    index[s[i]-'a'] = -2;
    }

    int r = s.size();
    for(int i = 0; i < 26; i++)
    {
	if(index[i] != -1 && index[i] != -2 && index[i] < r)
	{
	    r = index[i];
	}
    }

    return r == s.size() ? -1 : r;
}
