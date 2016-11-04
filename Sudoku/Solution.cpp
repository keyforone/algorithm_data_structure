bool isValidSudoku(vector<vector<char>>& board)
{
    for(int i = 0; i < 9; i++)
    {
	int digit[9] = { 0 };
	for(int j = 0; j < 9; j++)
	{
	    int c = board[i][j];
	    if(c == '.') continue;
	    if(digit[c-'1'] != 0) return false;
	    digit[c-'1']++;
	}
    }

    for(int i = 0; i < 9; i++)
    {
	int digit[9] = { 0 };
	for(int j = 0; j < 9; j++)
	{
	    int c = board[j][i];
	    if(c == '.') continue;
	    if(digit[c-'1'] != 0) return false;
	    digit[c-'1']++;
	}
    }

    for(int i = 0; i < 9; i += 3)
    {
	for(int j = 0; j < 9; j += 3)
	{
	    int start_x = i;
	    int start_y = j;
	    for(int m = start_x; m < start_x+3; m++)
	    {
	        int digit[9] = { 0 };
		for(int n = start_y; n < start_y+3; n++)
		{
		    int c = board[m][n];
		    if(c == '.') continue;
		    if(digit[c-'1'] != 0) return false;
		    digit[c-'1']++;
		}
	    }
	}
    }
    return true;
}

bool isValidSudoku(vector<vector<char>>& board)
{
    int bits1[9][9] = { 0 };
    int bits2[9][9] = { 0 };
    int bits3[9][9] = { 0 };

    for(int i = 0; i < 9; i++)
    {
	for(int j = 0; j < 9; j++)
	{
	    char c = board[i][j];
	    if(c == '.') continue;
	    int digit = c - '1';
	    int k = i/3*3 + j/3;
	    if(bits1[i][digit] | bits2[j][digit] | bits3[k][digit])
		return false;
	    bits1[i][digit] = bits2[j][digit] = bits3[k][digit] = 1;
	}
    }

    return true;
}
