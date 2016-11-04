bool isIsomorphic(string s, string t)
{
    int s_map[128];
    int t_map[128];

    for(int i = 0; i < 128; i++)
    {
	s_map[i] = t_map[i] = -1;
    }

    for(int i = 0; i < s.size(); i++)
    {
	if(s_map[s[i]] == -1)
	{
	    if(t_map[t[i]] != -1)
		return false;
	    s_map[s[i]] = t[i];
	    t_map[t[i]] = s[i];
	    s[i] = t[i];
	}
	else
	{
	    if(s_map[s[i]] != t[i])
		return false;
	    s[i] = t[i];
	}
    }

    return true;
}
