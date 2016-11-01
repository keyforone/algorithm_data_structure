int maxProfit(vector<int>& prices)
{
    int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++)
    {
 	minPrice = min(minPrice, prices[i]);
	maxPro = max(maxPro, prices[i] - minPrice);
    }

    return maxPro
}

int maxProfit(vector<int>& prices)
{
    if(prices.size() == 0) return 0;
    if(prices.size() == 1) return 0;

    stack<int> st;

    for(int i = 0; i <= (prices.size()-2); i++)
    {
	st.push(prices[i+1]-prices[i]);
    }

    int max_profit = 0;
    int profit = 0;
    while(!st.empty())
    {
	if(profit + st.top() <= 0)
       	{ 
	    profit = 0; 
	    st.pop(); 
	    continue; 
	}
	
	profit += st.top(); st.pop();
	if(profit > max_profit) max_profit = profit;
    }

    return max_profit;
}

