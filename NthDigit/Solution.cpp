int findNthDigit(int n)
{
    int len = 1;
    int base = 1;

    while(n > 9L*len*base)
    {
	n -= 9L*len*base;
	len++;
	base = base*10;
    }

    start = base + (n-1)/len;
    int remaining = (n-1)%len;
    while(remaining-- > 0)
    {
	base /= 10;
    }
     return (start/base)%10;
}
