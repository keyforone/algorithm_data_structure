int titleToNumber(string s)
{
    int total = 0;
    int factor;

    int i = s.size()-1;
    int j = 0;
    for(; i >= 0; i--, j++)
    {
	if( j == 0) factor = 1;
	else factor = 26*factor;

	int num = (s[i]-'A'+1);
	total += num*factor;
    }

    return total;
}
