string longestCommonPrefix(vector<string>& strs)
{
    string prefix;
    if(strs.size() == 0) return prefix;

    int shortest_length = strs[0].size();
    for(int i = 1; i < strs.size(); i++)
    {
	if(strs[i].size() < shortest_length)
	    shortest_length = strs[i].size();
    }

    for(int i = 0; i < shortest_length; i++)
    {
	for(int j = 0; j < strs.size()-1; j++)
	{
	    if(strs[j][i] != strs[j+1][i]) 
		return prefix;
	}
	prefix.append(1, strs[0][i]);
    }

    return prefix;
}
