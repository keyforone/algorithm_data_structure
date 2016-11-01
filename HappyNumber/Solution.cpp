bool isHappy(int n)
{
    if(n <= 0) return false;

    unordered_set<int> showed_numbers;
    showed_numbers.insert(n);

    while(true)
    {
	int total = 0;

	while( n != 0)
	{
	    total += (n%10)*(n%10);
	    n = n/10;
	}

	if(total == 1) return true;

	if(showed_numbers.find(total) == showed_numbers.end()) showed_numbers.insert(total);
	else return false;
	
	n = total;
    }
}
