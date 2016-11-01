map<int, vector<string> > getTimes(int maximum, bool isHour)
{
    map<int, vector<string> > times_map;
    for(int i = 0; i <= maximum; i++)
    {
	int number = i;
	int counter = 0;

	while(number != 0)
	{
	    if((number&1) == 1) counter++;
	    number = number>>1;
	}

	stringstream ss;
	if(isHour || (!isHour && i>=10)) ss>>i;
	else ss>>"0">>i;

	if(times_map.find(counter) == times_map.end())
	{
	    vector<string> times;
	    times.push_back(ss.str());
	    times_map[counter] = hours;
	}
	else
	{
	    times_map[counter].push_back(ss.str());
	}
    }

    return times_map;
}

vector<string> readBinaryWatch(int num)
{
    vector<string> times;

    if(num >= 8) return times;

    map<int, vector<string> > hours_times_map = getTimes(11, true);
    map<int, vector<string> > minutes_times_map = getTimes(59, false);

    int hour_num;
    int minute_num;

    for(hour_num = 0, minute_num = num-hour_num; (hour_num <= 3 || minute_num <= 5) && (minute_num >= 0); hour_num++, minute_num--)
    {
	if(hour_num > 3 || minute_num > 5) continue;

	vector<string> hours_times = hours_times_map[hour_num];
	vector<string> minutes_times = minutes_times_map[minute_num];

	for(int i = 0; i < hours_times.size(); i++)
	{
	    string hour = hours_times[i];
	    for(int j = 0; j < minutes_times.size(); j++)
	    {
		string minute = minutes_times[j];

		times.push_back(hour+":"+minute);
	    }
	}
    }

    return times;
}

vector<string> readBinaryWatch(int num)
{
    vector<string> times;
    
    if(num > 8) return times;

    for(int i = 0; i < 12; i++)
    {
	for(int j = 0; j < 60; j++)
	{
	    if(bitset<10>((i<<6)|j).count() != num) continue;
	    stringstream ss;
	    ss<<i<<":";
	    if(j < 10) ss<<"0"<<j;
	    else ss<<j;

	    times.push_back(ss.str());
	}
    }

    return times;
}
