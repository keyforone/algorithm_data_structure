int rob(vector<int>& nums)
{
    int max_left = 0;
    int max_right = 0;

    for(int i = 0; i < nums.size(); i++)
    {
	int max_t = max_left + num[i];
	if(max_right > max_left)
	    max_left = max_right;
	max_right = maxt_t;
    }

    return max_left > max_right ? max_left : max_right;
}
