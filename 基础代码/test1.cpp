#include "test1.h"

double object_demo(vector<double> xin)
{
	//xin ‰»ÎŒ™3
	return pow(xin[0] - 1.5, 2) + pow(xin[1] - 2.5, 2) + pow(xin[2] - 3.5, 2);
}
//void demo_ga();
/*
int main()
{
	//vector<double> xin = { 0.0794, 0.2769, 0.9700, 1.3224, 2.3500, 2.9394, 3.6213, 4.0446, 4.6032, 5.9961 };
	//vector<double> cin = { 15,21,0.403,2000,0.04,40,1.2 };
	//cout << objectf(xin) << endl;
	
	vector<vector<double>> bounds = { {0, 0.2, 0.7, 1.3, 2.2, 2.7, 3.3, 3.8, 4.3 ,4},{0.1, 0.6, 1.1, 1.7, 2.6, 3.1, 3.7, 4.2, 4.7, 6} };
	int nvars = 10;
	Result r;
	r = ga_my(objectf, nvars, bounds);
	for (int k = 0; k < nvars; k++)
	{
		cout << r.x_fit[k] << " ";
	}
	cout << r.y_best << endl;
	


}
void demo_ga()
{
	vector<vector<double>> bounds = { {0,0,0},{5,5,5} };
	int nvars = 3;
	Result r;
	r = ga_my(object_demo, nvars, bounds);
	for (int k = 0; k < nvars; k++)
	{
		cout << r.x_fit[k] << " ";
	}
	cout << r.y_best << endl;
}
*/

