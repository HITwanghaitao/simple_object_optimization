// Geneti_algorithm.cpp : 遗传算法实现过程。更新于2020.5.3
//开发人员：陈帅   开始日期：2019.8.5-8.8         邮箱：chenshuai0614@hrbeu.edu.cn
#ifndef PCH_H
#define PCH_H
#include <iostream>
# include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include<random>
#include<ctime>
using namespace std;


using namespace std;
//产生随机小数或整数
class RandomNumber {
public:
	RandomNumber() {
		srand(1234567);    //析构函数，在对象创建时数据成员执行初始化操作
	}
	int integer(int begin, int end)
	{
		return rand() % (end - begin + 1) + begin;
	}
	double decimal(double a, double b)
	{
		return double(rand() % 10000) / 10000 * (b - a) + a;
	}
};
struct Result
{
	double x_fit[10] = { 0 };
	double y_best = 0;
};
//ga用于定义优化变量范围，以及遗传算法过程中的选择、交叉、变异算子、解码、个体适应度计算等函数。
class ga
{
private:
	//==========================遗传算法参数设置=============================
	int  N_genetic;                //种群规模，太小产生病态基因；种群规模太大，难以收敛，一般0-100
	double M_pgentic;            //变异概率，与种群多样性有关，一般0.0001-0.2
	double C_pgentic;             //交叉概率，概率太大，容易错失最优个体，太小布恩那个有效更新种群，一般0.4-0.99.
	int E_gentic;                 //进化代数，太小，算法不容易收敛，太大增加时间和资源浪费，一般100-500.
	int L_variable;                //个体变量的字符串长度(基因数)
	double precision;
	int N_variable;                 //个体变量的个数
	double (*func)(vector<double> xin,vector<double> cin); //
	
	
public:
	vector<double> Extra;
	Result result;
	vector<vector<double>>x_i;          //优化变量
	vector<double>x_best;               //最优个体
	vector<vector<int>>x_binary;        //个体染色体
	vector<double> fitness;             //个体适应度;由于适应度函数要比较排序并在此基础计算选择概率，适应度函数的值应该取正值。
	double best_fitness;                //种群最优适应度
	vector<double> sumfitness;          //前面个体适应度和
	vector<double> P_i;                 //个体被选择的概率	
	//vector<double>x_low = { 0 };     //优化变量最小值
	//vector<double>x_high = { 10 };     //优化变量最大值
	vector<double>x_low ;     //优化变量最小值
	vector<double>x_high ;     //优化变量最大值
	RandomNumber r;
	void initialize();//初始化，产生初始种群
	vector<double> Real_trans(vector<int>x_binary);   //二进制转换为实数
	void SetParameters(double (*objf)(vector<double>, vector<double>), int nvars,vector<vector<double>> bounds,vector<double> extra);   
	//void SetParameters(double (*objf)(vector<double>, vector<double>), int nvars, vector<vector<double>> bounds); //设置算法参数
	void Optimization_iteration();
	void select_operator();             //选择算子
	void crossover_operator();          //交叉算子
	void mutate_operator();             //变异算子	
};
double function(vector<double> x); //目标函数

Result ga_my(double (*objf)(vector<double>, vector<double>), int nvars, vector<vector<double>> bounds, vector<double> extra = vector<double>(5));
//Result ga_my(double (*objf)(vector<double>, vector<double>), int nvars, vector<vector<double>> bounds);
#endif //PCH_H