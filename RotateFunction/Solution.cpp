int maxRotateFunction(vector<int>& A)
{
    int F = 0;
    int sum = 0;
    for(int i = 0; i < A.size(); i++)
    {
	F += i*A[i];
	sum += A[i];
    }

    int max =  F;
    for(int i = 1; i < A.size(); i++)
    {
	F = F + sum - A.size()*A[A.size()-i];
	if(F > max)
	    max = F;
    }

    return max;
}
