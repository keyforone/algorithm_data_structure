bool isAnagram(string s, string t)
{
    if(s.size() != t.size()) return false;

    int count[128];

    for(int i = 0; i < 128; i++) count[i] = 0;

    for(int i = 0; i < s.size(); i++) count[s[i]]++;

    for(int i = 0; i < t.size(); i++) count[t[i]]--;

    for(int i = 0; i < 128; i++)
    {
	if(count[i] != 0) return false;
    }

    return true;
}
