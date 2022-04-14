#pragma once
#include <stdio.h>
#include <map>
#include <vector>

//#include <iostream>
//using namespace std;

/*FOR TESTING PURPOSES
Track_Info A;
	A.Begin_Record();
	A.Add_On_Time(0, 1);
	A.Add_On_Time(1, 2);
	A.Begin_Record();
	A.Add_On_Time(1, 4);
	A.Begin_Record();
	A.Add_On_Time(0, 5);
	A.Add_On_Time(1, 6);
	A.Add_On_Time(1, 7);

	for (int i = 0; i < 10; i++) cout << A.Search_On_Time(0, 10)[i]<<" ";
	cout << endl;
	for (int i = 0; i < 10; i++) cout << A.Compare(0,2)[i] << " ";
	EXPECTED OUTPUT */

const int MAX_VALUE= 100; //<=100
const int MIN_VALUE= 20;//>0 <MAX_VALUE

using namespace std;


class On_Time_Record
{
private:
	int _values_amount;
	vector<int> _values;
public:
	On_Time_Record()
	{
		_values_amount = 0;
	}

	bool Add_Record(int new_runs_number, int new_value)
	{
		if (new_runs_number <= this->_values_amount)
		{
			this->_values[new_runs_number-1] = new_value;
			return 1;
		}
		while (_values_amount < new_runs_number-1)
		{
			this->_values.push_back(-1);
			_values_amount++;
		}
		this->_values.push_back(new_value);
		this->_values_amount++;
		return 1;
	}

	int* Search_Values(int req_amount)
	{
		int* res = new int[req_amount];
		for (int i = 0; i<req_amount; i++) 
			res[i] = -1;
		int res_pos = 0;
		for (int i = 0; i < this->_values_amount; i++)
		{
			if (_values[i] != -1)
			{
				res[res_pos] = _values[i];
				res_pos++;
				if (res_pos == req_amount)
					return res;
			}
		}
		return res;
	}
};

class Track_Info 
{
private:
	int _runs_number;
	int _current_recorded_run;
	map<int, On_Time_Record> _results_on_time;
	
public:
	Track_Info()
	{
		_runs_number = 0;
		_current_recorded_run = -1;
	}

	void Begin_Record()
	{
		_runs_number++;
		_current_recorded_run = _runs_number;
	}

	bool Add_On_Time(int new_time, int new_value)
	{
		if (_current_recorded_run == -1) return 0;
		this->_results_on_time[new_time].Add_Record(_runs_number, new_value);
		
	}
	
	int* Search_On_Time(int req_time, int req_amount)
	{
		return _results_on_time[req_time].Search_Values(req_amount);
	}

	int* Compare(int req_time, int req_result)
	{

		int* found_values = _results_on_time[req_time].Search_Values(10);
		//return found_values;
		int* res = new int[10];
		for (int i = 0; i < 10; i++) res[i] = -1;
		int res_pos = 1;
		for (int i = 0; i < 10; i++)
			res[i] = -1;
		int min_val, max_val;
		
		if (found_values[0] > req_result)
		{
			max_val = found_values[0];
			min_val = req_result;
		}
		else
		{
			min_val = found_values[0];
			max_val = req_result;
		}
		for (int i = 0; ((i < 10) * (found_values[i] != -1)); i++)
		{
			if (min_val > found_values[i]) min_val = found_values[i];
			if (max_val < found_values[i]) max_val = found_values[i];
		}
		res[0] = (int)((req_result - min_val)*1.00 / (max_val - min_val) * (MAX_VALUE - MIN_VALUE))+MIN_VALUE;
		for (int i = 0; i < 10; i++)
		{
			if (found_values[i] == -1) return res;
			res[res_pos]= (int)((found_values[i] - min_val) * 1.00 / (max_val - min_val) * (MAX_VALUE - MIN_VALUE))+MIN_VALUE;
			res_pos++;
			if (res_pos == 10) return res;
		}
		return res;
		
	}
};



