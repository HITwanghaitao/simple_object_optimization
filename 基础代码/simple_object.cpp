#include "test1.h"
using namespace std;
double objectf(vector<double> xin, vector<double> extra) //用于优化
{
	vector<double> cin7 = { 15,21,0.403,2,0.04,0.04,1.2 };
	int choice = 1;

	return sim_model(xin, cin7, choice);
}

double objectf_cin(vector<double> cin5, vector<double> extra) //用于双层优化
{
	//vector<double> cin = { 15,21,0.403,2,0.04,0.04,1.2 };
	vector<double> cin7 = { 15,21,0.403,2,0.04,0.04,1.2 };
	for (int j = 2; j < 7; j++)
	{
		cin7[j] = cin5[j - 2];
	}
	vector<double> xin;
	xin = extra;
	int choice = 1;
	/*
	for (int j = 0; j < xin.size(); j++)
	{
		cout << xin[j] << " ";
	}
	cout << endl;
	for (int j = 0; j < cin7.size(); j++)
	{
		cout << cin7[j] << " ";
	}
	cout << endl;
	int temp;
	cout << "函数计算";
	std::cin >> temp;
	*/
	double y = -sim_model(xin, cin7, choice);
	//cout << y << endl;
	return y;
}

double objf1(vector<double> cin5)//用于计算偏差
{
	vector<double> xin = { 0.01746, 0.42222, 1.10000, 1.69365, 2.35873, 3.07460, 3.38889, 3.87619, 4.40159, 4.00000 };
	vector<double> cin7 = { 15,21,0.403,2,0.04,0.04,1.2 };
	for (int j = 2; j < 7; j++)
	{
		cin7[j] = cin5[j - 2];
	}
	return sim_model(xin, cin7, 1);
}
void model_ga();
void model_error();
void bi_ga();
double object_inside(vector<double>,vector<double>);

int inner_flag = 1;
//vector<vector<double>> bounds_c2 = { {0.2,1.5,0.03,0.02,1.0},{0.5,2.5,0.05,0.05,1.3} };
int main()
{
	//vector<double> xin = { 0.01746, 0.42222, 1.10000, 1.69365, 2.35873, 3.07460, 3.38889, 3.87619, 4.40159, 4.00000 };
	//vector<double> cin = { 15,21,0.403,2,0.04,0.04,1.2 }; 
	//cout << sim_model(xin, cin, 1) << endl;
	//model_ga();
	//model_error();
	bi_ga();
}
void model_ga()
{
	//vector<double> xin = { 0.0794, 0.2769, 0.9700, 1.3224, 2.3500, 2.9394, 3.6213, 4.0446, 4.6032, 5.9961 };
	//vector<double> cin = { 15,21,0.403,2000,0.04,40,1.2 };
	//cout << objectf(xin) << endl;

	vector<vector<double>> bounds = { {0, 0.2, 0.7, 1.3, 2.2, 2.7, 3.3, 3.8, 4.3 ,4},{0.1, 0.6, 1.1, 1.7, 2.6, 3.1, 3.7, 4.2, 4.7, 6} };
	int nvars = 10;
	Result r;
	//ofstream out("y1_stable_optimization_result.txt");
	//out << "y1确定性优化结果：" << endl;
	//out << "{";
	r = ga_my(objectf, nvars, bounds);
	for (int k = 0; k < nvars; k++)
	{
		cout << r.x_fit[k] << " ";
		//out << r.x_fit[k] << ",";
	}
	//out << "}" << endl;
	cout << r.y_best << endl;
	//out << r.y_best << endl;
}
void model_error()
{
	vector<vector<double>> bounds_test_c = { {0,5},{10,20},{50,100} };
	vector<vector<double>> bounds_c = { {0.2,0.6},{1.5,2.5},{0.03,0.05},{0.02,0.05},{1.0,1.3} };//不确定参数初始区间
	vector<vector<double>> bounds_c_d = { {0.39,0.417},{1.874,2.132},{0.039,0.041},{0.039,0.041},{1.170,1.231} };//不确定参数优化区间
	int N = 100;
	vector<vector<double>> lhs = sample_uniform_bounds(N, bounds_c);
	vector<double> y1m = {};
	ofstream out("y1_stable_error.txt");
	for (int j = 0; j < N; j++)
	{
		double y1 = objf1(lhs[j]);
		y1m.push_back(y1);
		out << y1 << endl;
		//cout << y1 << endl;
	}
	cout << "over" << endl;
}

void bi_ga()
{
	//vector<vector<double>> bounds = { {0, 0.2, 0.7, 1.3, 2.2, 2.7, 3.3, 3.8, 4.3 ,4},{0.1, 0.6, 1.1, 1.7, 2.6, 3.1, 3.7, 4.2, 4.7, 6} };
	vector<vector<double>> boundcc = { {0, 0.2, 0.7, 1.3, 2.2, 2.7, 3.3, 3.8, 4.3 ,4},{0.1, 0.6, 1.1, 1.7, 2.6, 3.1, 3.7, 4.2, 4.7, 6} };
	int nvars = 10;
	Result r;
	r = ga_my(object_inside, nvars, boundcc);
	for (int k = 0; k < nvars; k++)
	{
		cout << r.x_fit[k] << " ";
	}
	cout << -r.y_best << endl;
	
}

double object_inside(vector<double> xin, vector<double> extra)
{

	//cout << "调用内层最大化计算" << endl;
	//vector<double> xin;
	//xin = xin1;
	cout << "开始内层第 " << inner_flag << " 次:" << endl;
	inner_flag += 1;
	//int temp;
	//cin >> temp;
	//xin = xin2;
	int nvars_c = 5;
	vector<vector<double>> bounds_c2 = { {0.2,1.5,0.03,0.02,1.0},{0.5,2.5,0.05,0.05,1.3} };
	
	Result r;
	r = ga_my(objectf_cin, nvars_c, bounds_c2,xin);
	cout << "最大化寻优值:" << -r.y_best << endl;
	cout << "*****              ******" << endl;
	return -r.y_best;
}
