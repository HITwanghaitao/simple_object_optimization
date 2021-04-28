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

double objf(vector<int> nvars_choice, vector<double> c,int X_choice)//�����Ŵ��㷨����Ѱ��
{
	//nvars_choice��ʾ�ļ��������μ��Ŵ��㷨Ѱ��,�����1��2��3��4��5����ʾ��1��2��3��4��5�������μ�Ѱ��
	//c��ʾ�����������Ŵ��㷨�������ֵ,�䳤����1~5
	//X_choice ��ʾ���������������У���X_choice��ʵ��ţ���1��ʼ

	Data data;
	vector<double> pm_norm = data.pm_norm[X_choice-1];//��ȡ��X_choice���ģ����ʵ�������룬�������̬�ֲ�
	

	double eud = Eud(pm_norm, c,X_choice);//��������Ϊ��ʵ���������Ż���������X_choice������
	return eud;
}
int main()
{	
	ga_test();
	
}

void ga_test()//����gaѰ��
{
	clock_t startTime, endTime; //�������ʼ����ʱ��ͽ���ʱ��
	startTime = clock();        //��ʱ��ʼ
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
	endTime = clock();//��ʱ����
	ofstream out2("B_note.txt");
	out2 << "�й۲����,��������̬�ֲ�" << endl;
	cout << "run time:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	out2 << "run time:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	out2 << showTime() << endl;
	out2.close();
	
}
*/
