#include "pch.h"
#include "my_functions.h"
#include <sstream>
#include <iostream>
#include <string>
/*
void single_out();
void ga_test();
//void ga_test_order();
void my_sensitive(int c_choice);

double objf(vector<int> nvars_choice, vector<double> c,int X_choice)//用于遗传算法参数寻优
{
	//nvars_choice表示哪几个参数参加遗传算法寻优,例如｛1，2，3，4，5｝表示第1，2，3，4，5个参数参加寻优
	//c表示参数变量，遗传算法传入变量值,其长度在1~5
	//X_choice 表示拉丁超立方抽样中，第X_choice个实验号，从1开始

	Data data;
	vector<double> pm_norm = data.pm_norm[X_choice-1];//获取第X_choice组的模型真实参数输入，其符合正态分布
	

	double eud = Eud(pm_norm, c,X_choice);//输入依次为真实参数，待优化参数，第X_choice组数据
	return eud;
}
int main()
{	
	ga_test();
	
}

void ga_test()//用于ga寻优
{
	clock_t startTime, endTime; //定义程序开始运行时间和结束时间
	startTime = clock();        //计时开始
	int LHS_N = 100;
	int nvars = 5;
	vector<int> nvars_choice = { 1,2,3,4,5 };
	vector<vector<double>> bounds = { {0.8,0.6,0.4,0.2,0.0},{1.2,1.0,0.8,0.6,0.4} };


	ofstream out("B.txt");
	for (int j = 0; j < 5; j++)
	{
		out << "c" << j + 1 << " ";
	}
	out << "y_fit" << endl;
	Result y_100[100];
	for (int j = 1; j <= LHS_N; j++)
	{
		Result y = ga_my(objf, nvars, nvars_choice, bounds, j);
		for (int k = 0; k < 5; k++)
		{
			out << y.x_fit[k] << " ";
		}
		out << y.y_best << endl;
		y_100[j - 1] = y;
	}

	out.close();
	endTime = clock();//计时结束
	ofstream out2("B_note.txt");
	out2 << "有观测误差,参数呈正态分布" << endl;
	cout << "run time:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	out2 << "run time:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	out2 << showTime() << endl;
	out2.close();
	
}
*/
