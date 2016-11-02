vector<vector<int>> generate(int numRows) 
{
    vector<vector<int> > result;

    for(int i = 1; i <= numRows; i++)
    {
	vector<int> row;
	for(int j = 0; j < i; j++)
	{
	    if(result.size() == 0)
	    {
		row.push_back(1);
		break;
	    }

	    if(j == 0 || j == (i-1))
	    {
		row.push_back(1);
	    }
	    else
	    {
	        vector<int>& upper_row = result[i-2];
		row.push_back(upper_row[j-1] + upper_row[j]);
	    }
	}
	result.push_back(row);
    }

    return result;
}
