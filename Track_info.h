#pragma once
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <fstream>

/*
For Testing purposes
	Track_Info TI;
	Single_Run_Info SRI;
	time_t CT = time(nullptr);
	SRI._Add_Timing(CT, 1);
	SRI._Add_Timing(CT, 2);
	SRI._Add_Timing(CT, 3);
	TI.Add_Track(SRI);
	cout << TI.Search_on_Time(CT).size();
Expected result 3
	*/

using namespace std;

class Run_Moment {
public:
	time_t _moment;
	double _steps_num;

	Run_Moment(time_t _new_moment, double _new_steps_num)
	{
		this->_moment = _new_moment;
		this->_steps_num = _new_steps_num;
	}
};

class Single_Run_Info
{
public:
	int _timings_amount;
	string _run_comment;
	vector <Run_Moment> _timings;

	Single_Run_Info()
	{
		this->_run_comment = "";
		this->_timings_amount = 0;
	}
	int _Add_Timing(time_t _new_moment, double _new_steps_num)
	{
		Run_Moment new_moment = Run_Moment(_new_moment, _new_steps_num);
		this->_timings.push_back(new_moment);
		this->_timings_amount++;
		return 1;

	}
};

class Track_Info //Описание всех забегов 
{
public:
	string _track_comment;
	int _runs_amount;
	vector <Single_Run_Info> _runs;

	Track_Info()
	{
		this->_track_comment = "";
		this->_runs_amount = 0;
	}
	int Add_Track(Single_Run_Info _new_run)
	{
		this->_runs_amount++;
		this->_runs.push_back(_new_run);
		return 1;
	}
	vector<int> Search_on_Time(time_t req_time)
	{
		vector<int> res;
		for (int i = 0; i < this->_runs_amount; i++)
		{
			for (int j = 0; j < (this->_runs[i])._timings_amount; j++)
			{
				if (((this->_runs[i])._timings[j])._moment == req_time)
				{
					res.push_back(i);
				}
			}
		}
		return res;
	}
};




