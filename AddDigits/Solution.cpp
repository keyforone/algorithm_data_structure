int addDigits(int num)
{
    if(num == 0) return 0;

    int r = (num%9);

    return (r == 0) ? 9 : r;
}

int addDigits(int num)
{
    if(num < 10) return num;

    while(true)
    {
	int r = 0;
        while(num >= 10)
        {
	    r += (num%10);
	    num = (num/10);
        }
	r += num;

	if(r < 10)
	    return r;
	num = r;
    }
}
