
int arrangeCoins(int n)
{
    if( n < 0) return 0;

    unsigned long x = (unsigned long)sqrt(8*(unsigned long)n+1);

    return (x-1)/2;
}

