int longestPalindrome(string s)
{
    int counter[128];
    
    for(int i = 0; i < 128; i++) counter[i] = 0;

    for(int i = 0; i < s.size(); i++) counter[s[i]]++;

    int r = 0;
    bool has_odd = false;
    for(int i = 0; i < 128; i++)
    {
	if(counter[i] == 0) continue;

	if(counter[i]%2 == 0) 
	{
	    r += counter[i];
	}
	else 
	{
	    has_odd = true;
	    r += (counter[i]-1);
	}
    }

    return has_odd ? r+1 : r;
}
