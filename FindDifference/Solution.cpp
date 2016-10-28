char findTheDifference(string s, string t)
{
    unsigned int s_sum = 0;
    for(int i = 0; i < s.length(); i++)
    {
	s_sum += s[i];
    }

    unsigned int t_sum = 0;
    for(int i = 0; i < t.length(); i++)
    {
	t_sum += t[i];
    }

    return (char)(t_sum - s_sum);
}
