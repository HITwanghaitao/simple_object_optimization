#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include<cmath>
#include<vector>
#include<random>
#include<vector>
#include<fstream>
# include <cstdlib>
# include <iomanip>
# include <iomanip>
# include <cmath>
# include <ctime>
# include <cstring>

using namespace std;
using namespace std;





double gaussrand();//��׼��̬�ֲ�
double gaussrand_u_sigma(double u, double sigma);//�����ض�u,sigma��̬�ֲ�
vector<vector<double>> sample_norm(int N,int M);//��̬����
vector<vector<double>> sample_uniform(int N, int M);//���ȳ���
vector<vector<double>> sample_uniform_bounds(int N, vector<vector<double>> bounds);

string showTime();

/*
objf�����в���
vector<double> c = { 1.0,0.8,0.6,0.4,0.2 };
int N_vars = x.size();
for (int j = 0; j < N_vars; j++)
{
	c[nvars_choice[j] - 1] = x[j];
}*/