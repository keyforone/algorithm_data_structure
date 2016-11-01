string addStrings(string num1, string num2)
{
    string s;

    string digits[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

    int i, j;
    int next_digit = 0;
    for(i = num1.size()-1, j = num2.size()-1; i>=0 && j>=0 ; i--,j--)
    {
	int index = ((num1[i] - '0') + (num2[j] - '0') + next_digit)%10;
	next_digit = ((num1[i] - '0') + (num2[j] - '0') + next_digit)/10;
	s = digits[index] + s;
    }

    if(i >= 0)
    {
	for(;i>=0;i--)
	{
	    int index = ((num1[i] - '0') + next_digit)%10;
	    next_digit = ((num1[i] - '0') + next_digit)/10;
	    s = digits[index] + s;
	}
    }
    else if( j >= 0)
    {
	for(;j>=0;j--)
	{
	    int index = ((num2[j] - '0') + next_digit)%10;
	    next_digit = ((num2[j] - '0') + next_digit)/10;
	    s = digits[index] + s;
	}
    }

    return s;
}
