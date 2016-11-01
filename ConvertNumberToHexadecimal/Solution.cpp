string toHex(int num)
{
    //unsigned long max_num = 4294967296;
    unsigned long max_num = 1;
    for(int i = 0; i < 32; i++)
    {
	max_num = max_num<<1;
    }
    unsigned long postive_num;
    if(num < 0) postive_num = max_num + num;
    else postive_num = num;

    if(num == 0) return "0";

    string character[16] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f" };

    string s;
    while(postive_num != 0)
    {
	s  = character[postive_num%16] + s;
	postive_num = postive_num/16;
    }

    return s;
}
