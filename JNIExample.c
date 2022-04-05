#include <stdio.h>
#include <jni.h>
#include "JNIExample.h"


#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>

using namespace std;
// Âðåìÿ çàïèñàíî â int äëÿ óïðîùåíèÿ òåñòèðîâàíèÿ, ìîæíî áûñòðî çàìåíèòü íà time_t
class Run_Record //1 òî÷êà çàáåãà 
{
public:
	int _time;
	double _lat;//øèðîòà
	double _lng;//äîëãîòà
	void Print() {
		cout << this->_lat << " " << this->_lng << " " << this->_time<<endl;
	}
};

class Single_Person_Run //Îïèñàíèå âñåõ çàáåãîâ 
{
public:
	int _size; //êîëè÷åñòâî òî÷åê
	vector<Run_Record> _Records; //Âåêòîð ñ òî÷êàìè çàáåãà
	Single_Person_Run()//Êîíñòðóêòîð, ñîäàþùèé ïóñòîé çàáåã
	{
		this->_size = 0;
	}
	void Add_Record(int new_time, double new_lat, double new_lng)//Äîáàâëÿåò 1 çàïèñü
	{
		Run_Record new_record;
		new_record._lat = new_lat;
		new_record._lng = new_lng;
		new_record._time = new_time;
		this->_Records.push_back(new_record);
		this->_size++;
	}
	void Print_All() //Âûâåñòè âñå ñòðîêè â êîíñîëü
	{
		for (int i = 0; i < this->_size; i++)
		{
			cout << this->_Records[i]._lat << " " << this->_Records[i]._lng << " " << this->_Records[i]._time<<endl;
		}
	}
	Run_Record Search_on_time(int req_time) //Èùåò çàïèñü(òîëüêî 1) ïî âðåìåíè.
	{
		for (int i = 0; i < this->_size; i++)
		{
			if (this->_Records[i]._time == req_time) return this->_Records[i];
		}
		Run_Record res;
		res._lat = 0;
		res._lng = 0;
		res._time = -1;
		return res;
		cout << "Hey, user, there's nothing to see here(requested time not found)" << endl;
	}
	
};

int man()
{
	Single_Person_Run A;
	/*A.Add_Record(1, 1.0, 1.0);
	A.Add_Record(2, 1.3, 2.4);
	A.Add_Record(2, 1.5, 3.4);
	A.Print_All();*/

	A.Search_on_time(2).Print();
}

int Dasha (int a, int b) {
return (a+b);

}

JNIEXPORT void JNICALL Java_JNIExample_sayHello
  (JNIEnv *env, jobject object, jint len) {
Single_Person_Run A;
        /*A.Add_Record(1, 1.0, 1.0);
        A.Add_Record(2, 1.3, 2.4);
        A.Add_Record(2, 1.5, 3.4);
        A.Print_All();*/

        A.Search_on_time(2).Print();
 /* printf("Hello from C!");*/
}
