string getHint(string secret, string guess)
{
    int bulls = 0;
    int cows = 0;
    int digits[2][10] = { 0 };
    int digitscounts = secret.size();

    for(int i = 0; i < digitscounts; i++)
    {
	if(secret[i] == guess[i]) { bulls++; continue; }

	if(digits[1][secret[i]-'0'] > 0) { cows++; digits[1][secret[i]-'0']--; }
	else { digits[0][secret[i]-'0']++; }

	if(digits[0][guess[i]-'0'] > 0) { cows++; digits[0][guess[i]-'0']--; }
	else { digits[1][guess[i]-'0']++; }
    }

    string s;
    return s+bulls+"A"+cows+"B";
}
