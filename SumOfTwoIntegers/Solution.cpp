int getSum(int a, int b)
{
    int t = (a&b);

    while(t != 0)
    {
	a = (a^b);
	b = t<<1;

	t = (a&b);
    }

    return a|b;
}
