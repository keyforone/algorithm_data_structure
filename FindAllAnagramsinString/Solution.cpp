vector<int> findAnagrams(string s, string p)
{
    vector<int> index;

    if(s.size() < p.size()) return index;

    int counter[128] = { 0 };
    for(int i = 0; i < p.size(); i++)
	counter[p[i]-'a']++;

    for(int i = 0; i + p.size() <= s.size();)
    {
	int start = i;
	int end = i+p.size()-1;

	int counter_check[128] = { 0 };
	memcpy(counter_check, counter, 128);

	bool except = false;
	bool anagram = true;
	int j = start;
	for(; j <= end; j++)
	{
	    if(counter[s[j]-'a'] == 0)
	    {
		except = true;
		break;
	    }
	    counter_check[s[j]-'a']--; 
	    if(counter_check[s[j]-'a'] < 0)
	    {
		anagram = false;
		break;
	    }
	}
	if(except) { i = j+1; continue;}
	if(!anagram) { i++; continue; }

	for(int k = 0; k < 128; k++)
	{
	    if(counter_check[k] != 0) { anagram = false; break; }
	}

	if(anagram)
	{
	    index.push_back(i++);

	    while(i+p.size() <= s.size())
	    {
		if(s[i+p.size()-1] != s[i-1])
		    break;
		index.push_back(i++);
	    }
	    i++;
	}
	else
	{
	    i++;
	}
    }

    return index;
}

bool compareCounter(int (&scounter)[], int (&pcounter)[])
{
    for(int i = 0; i < 26; i++)
    {
	if(scounter[i] != pcounter[i]) return false;
    }

    return true;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> index;

    if(s.size() < p.size()) return index;

    int scounter[26] = { 0 };
    int pcounter[26] = { 0 };
    for(int i = 0; i < p.size(); i++)
    {
	scounter[s[i]-'a']++;
	pcounter[p[i]-'a']++;
    }

    if(compareCounter(scounter, pcounter))
	index.push_back(0);

    for(int i = p.size(); i < s.size(); i++)
    {
	scounter[s[i]-'a']++;
	scounter[s[i-p.size()]-'a']--;

	if(compareCounter(scounter, pcounter))
	    index.push_back(i-p.size()+1);
    }

    return index;
}
