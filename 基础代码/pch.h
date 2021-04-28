// Geneti_algorithm.cpp : �Ŵ��㷨ʵ�ֹ��̡�������2020.5.3
//������Ա����˧   ��ʼ���ڣ�2019.8.5-8.8         ���䣺chenshuai0614@hrbeu.edu.cn
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
//�������С��������
class RandomNumber {
public:
	RandomNumber() {
		srand(1234567);    //�����������ڶ��󴴽�ʱ���ݳ�Աִ�г�ʼ������
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
//ga���ڶ����Ż�������Χ���Լ��Ŵ��㷨�����е�ѡ�񡢽��桢�������ӡ����롢������Ӧ�ȼ���Ⱥ�����
class ga
{
private:
	//==========================�Ŵ��㷨��������=============================
	int  N_genetic;                //��Ⱥ��ģ��̫С������̬������Ⱥ��ģ̫������������һ��0-100
	double M_pgentic;            //������ʣ�����Ⱥ�������йأ�һ��0.0001-0.2
	double C_pgentic;             //������ʣ�����̫�����״�ʧ���Ÿ��壬̫С�����Ǹ���Ч������Ⱥ��һ��0.4-0.99.
	int E_gentic;                 //����������̫С���㷨������������̫������ʱ�����Դ�˷ѣ�һ��100-500.
	int L_variable;                //����������ַ�������(������)
	double precision;
	int N_variable;                 //��������ĸ���
	double (*func)(vector<double> xin,vector<double> cin); //
	
	
public:
	vector<double> Extra;
	Result result;
	vector<vector<double>>x_i;          //�Ż�����
	vector<double>x_best;               //���Ÿ���
	vector<vector<int>>x_binary;        //����Ⱦɫ��
	vector<double> fitness;             //������Ӧ��;������Ӧ�Ⱥ���Ҫ�Ƚ������ڴ˻�������ѡ����ʣ���Ӧ�Ⱥ�����ֵӦ��ȡ��ֵ��
	double best_fitness;                //��Ⱥ������Ӧ��
	vector<double> sumfitness;          //ǰ�������Ӧ�Ⱥ�
	vector<double> P_i;                 //���屻ѡ��ĸ���	
	//vector<double>x_low = { 0 };     //�Ż�������Сֵ
	//vector<double>x_high = { 10 };     //�Ż��������ֵ
	vector<double>x_low ;     //�Ż�������Сֵ
	vector<double>x_high ;     //�Ż��������ֵ
	RandomNumber r;
	void initialize();//��ʼ����������ʼ��Ⱥ
	vector<double> Real_trans(vector<int>x_binary);   //������ת��Ϊʵ��
	void SetParameters(double (*objf)(vector<double>, vector<double>), int nvars,vector<vector<double>> bounds,vector<double> extra);   
	//void SetParameters(double (*objf)(vector<double>, vector<double>), int nvars, vector<vector<double>> bounds); //�����㷨����
	void Optimization_iteration();
	void select_operator();             //ѡ������
	void crossover_operator();          //��������
	void mutate_operator();             //��������	
};
double function(vector<double> x); //Ŀ�꺯��

Result ga_my(double (*objf)(vector<double>, vector<double>), int nvars, vector<vector<double>> bounds, vector<double> extra = vector<double>(5));
//Result ga_my(double (*objf)(vector<double>, vector<double>), int nvars, vector<vector<double>> bounds);
#endif //PCH_H