vector<int> getRow(int rowIndex) 
{
    vector<int> result;
    for(int i = 1; i <= rowIndex+1; i++)
    {
	int previous = 1;
	for(int j = 0; j < i; j++)
	{
	    if(i == 1) { result.push_back(1); break; }
	    if(j == 0) continue;
	    if(j == i-1) { result.push_back(1); break; }
	    int t = previous + result[j];
	    previous = result[j];
	    result[j] = t;
	}
    }
    return result;
}
