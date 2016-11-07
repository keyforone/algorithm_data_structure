uint32_t reverseBits(uint32_t n)
{
    if( n == 0) return 0;
    uint32_t m = 0;
    for(int i = 0; i < 32; i++)
    {
	m = m<<1;
	m +=  (n&1);
	n = n>>1;
    }
    return m;
}
