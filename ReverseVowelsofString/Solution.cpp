string reverseVowels(string s)
{
    char Vowels[128] = {0};
    Vowels['A'] = 1;Vowels['a'] = 1;
    Vowels['E'] = 1;Vowels['e'] = 1;
    Vowels['I'] = 1;Vowels['i'] = 1;
    Vowels['O'] = 1;Vowels['o'] = 1;
    Vowels['U'] = 1;Vowels['u'] = 1;

    int i,  j;
    for(i = 0, j = s.size()-1; i< j;)
    {
	if(Vowels[s[i]] == 0) { i++; continue; }
	if(Vowels[s[j]] == 0) { j--; continue; }
	
	if(s[i] != s[j]) { char t = s[i]; s[i] = s[j]; s[j] = t; }

	i++; j--;
    }

    return s;
}
