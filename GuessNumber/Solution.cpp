int guessNumber(int n)
{
    if(n < 1) return 0;

    int step = (n+1)>>1;
    int num = 0;
    int x = 1;
    do
    {
	num += x*step;
	x = guess(num);
	step = step>>1 ? step>>1 : 1;
    }while(x != 0);

    return num;
}
