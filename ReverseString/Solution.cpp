std::string reverse_string(std::string& s)
{
    if(s.empty()) return s;

    int head = 0;
    int tail = s.length()-1;

    while(head < tail)
    {
	char t = s[head];
	s[head] = s[tail];
	s[tail] = t;

	head++;
	tail--;
    }

    return s;
}
