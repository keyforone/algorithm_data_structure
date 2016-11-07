int lengthOfLastWord(string s) 
{
    int last_word_length = 0;
    if(s.empty()) return last_word_length;

    bool start = false;
    for(int i = s.size()-1; i >= 0; i--)
    {
	if(start)
	{
	    if(s[i] == ' ') return last_word_length;
	    last_word_length++;
	}
	else
	{
	    if(s[i] == ' ') continue;
	    start = true;
	    last_word_length++;
	}
    }

    return last_word_length;
}
