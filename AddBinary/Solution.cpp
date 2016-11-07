string addBinary(string a, string b)
{
    if(a.empty()) return b;
    if(b.empty()) return a;

    string s;

    int i = a.size()-1;
    int j = b.size()-1;
    int left = 0;
    for( ; i >= 0 && j >= 0; i--,j--)
    {
	char sum = (a[i]-'0') + (b[j]-'0') + left;
	left = ((sum/2) == 1 ? 1 : 0);
	s.insert(0, 1, (sum%2 == 1 ? '1' : '0'));
    }

    while(i >= 0)
    {
	char sum = a[i]-'0'+left;
	left = ((sum/2) == 1 ? 1 : 0);
	s.insert(0, 1, (sum%2 == 1 ? '1' : '0'));
	i--;
    }

    while(j >= 0)
    {
	char sum = b[j]-'0'+left;
	left = ((sum/2) == 1 ? 1 : 0);
	s.insert(0, 1, (sum%2 == 1 ? '1' : '0'));
	j--;
    }

    if(left == 1)
	s.insert(0, 1, '1');

    return s;
}
