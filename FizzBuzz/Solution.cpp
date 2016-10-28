vector<string> fizzBuzz(int n)
{
    vector<string> v;

    if(n <= 0) return v;

    static string Fizz = "Fizz";
    static string Buzz = "Buzz";
    static string FizzBuzz = "FizzBuzz";

    int iter = 1;

    while(iter <= n)
    {
	if((iter%15) == 0)
	{
	    v.push_back(FizzBuzz);
	}
	else if((iter%5) == 0)
	{
	    v.push_back(Buzz);
	}
	else if((iter%3) == 0)
	{
	    v.push_back(Fizz);
	}
	else
	{
	    stringstream ss;
	    ss<<iter;
	    string s;
	    ss>>s;

	    v.push_back(s);
	}
	iter++;
    }

    return v;
}
