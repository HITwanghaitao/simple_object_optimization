#include "pch.h"
//=============================设置参数====================================
int jflag = 0;
int kflag = 0;//定义
vector<double> xin_flag1 = {}; //用于优化的初始化部分
vector<double> xin_flag2 = {}; //用于优化的后部分

void ga::SetParameters(double (*objf)( vector<double>,vector<double>),int nvars,vector<vector<double>> bounds, vector<double> extra)
//void ga::SetParameters(double (*objf)(vector<double>, vector<double>), int nvars, vector<vector<double>> bounds)
{
	int extra_size = extra.size();
	Extra.resize(extra_size);
	Extra = extra;
	N_variable = nvars;
	x_low.resize(N_variable);
	x_high.resize(N_variable);
	func = objf;
	for (int j = 0; j < N_variable; j++)
	{
		x_low[j] = bounds[0][j];
		//cout << "x_low[" << j + 1 << "]=" << x_low[j] << endl;
		x_high[j] = bounds[1][j];
		//cout << "x_high[" << j + 1 << "]=" << x_high[j] << endl;
	}

	N_genetic = 10;                //种群规模，太小产生病态基因；种群规模太大，难以收敛，一般0-100
	M_pgentic = 0.25;            //变异概率，与种群多样性有关，一般0.0001-0.2
	C_pgentic = 0.5;             //交叉概率，概率太大，容易错失最优个体，太小布恩那个有效更新种群，一般0.4-0.99.
	E_gentic = 100;                 //进化代数，太小，算法不容易收敛，太大增加时间和资源浪费，一般100-500.
	precision = 0.001;
	L_variable = int(log((x_high[0] - x_low[0]) / precision + 1) / log(2));//个体变量的字符串长度(基因数)
	//N_variable = 2;

}
//***************************
//二进制转换为实数
//******************************
vector<double> ga::Real_trans(vector<int>x_binary)
{
	vector<int>x_decimal(N_variable);
	vector<double>x(N_variable);
	for (int j = 0; j < N_variable; j++)
	{
		for (int k = j * L_variable, l_gen = 0; k < (j + 1) * L_variable; k++, l_gen++)
		{
			x_decimal[j] = x_decimal[j] + x_binary[k] * pow(2, l_gen);
		}
		//x[j] = x_low[0] + double(x_decimal[j]) / (pow(2, L_variable) - 1) * (x_high[0] - x_low[0]);
		x[j] = x_low[j] + double(x_decimal[j]) / (pow(2, L_variable) - 1) * (x_high[j] - x_low[j]);
	}
	return x;
}
//*******************
//初始化并赋值
//*******************
void ga::initialize()
{
	/*
	//extern RandomNumber r;       //定义全局随机数
	x_i.resize(N_genetic, vector<double>(N_variable));
	x_best.resize(N_variable);
	fitness.resize(N_genetic);
	x_binary.resize(N_genetic, vector<int>(N_variable * L_variable)); //优化变量二进制
	for (int i = 0; i < N_genetic; i++)
	{
		//================================基因编码===============================================
		for (int j = 0; j < N_variable * L_variable; j++)
		{
			x_binary[i][j] = r.integer(0, 1);
			//cout << x_binary[i][j];
		}
		//cout << endl;
		//x_i[i] = Real_trans(x_binary[i]);
		//fitness[i] = 1 / function(x_i[i]);

		//xin1 = x_i[i];//变量提取点
		fitness[i] = 1 / func(x_i[i]);
		//jflag = jflag + 1;

		//cout << "第一处:" << jflag <<endl;
		//cout << fitness[i] << endl;
	}
	x_best = x_i[0];                      //初始化最优个体
	best_fitness = fitness[0];
	for (int i = 1; i < N_genetic; i++)
	{
		if (best_fitness < fitness[i])
		{
			best_fitness = fitness[i];
			x_best = x_i[i];
		}
	}
	*/
	x_i.resize(N_genetic, vector<double>(N_variable));
	x_best.resize(N_variable);
	fitness.resize(N_genetic);
	x_binary.resize(N_genetic, vector<int>(N_variable * L_variable)); //优化变量二进制
	for (int i = 0; i < N_genetic; i++)
	{
		//================================基因编码===============================================
		for (int j = 0; j < N_variable * L_variable; j++)
		{
			x_binary[i][j] = r.integer(0, 1);
			//cout << x_binary[i][j];
		}
		//cout << endl;

		
		
		x_i[i] = Real_trans(x_binary[i]);
		vector<double> d = { 1,2,3,4 };
		fitness[i] = 1 / func(x_i[i],Extra);
		//fitness[i] = 1 / func(x_i[i], d);
		jflag += 1;
	}
	x_best = x_i[0];                      //初始化最优个体
	best_fitness = fitness[0];
	for (int i = 1; i < N_genetic; i++)
	{
		if (best_fitness < fitness[i])
		{
			best_fitness = fitness[i];
			x_best = x_i[i];
		}
	}
}
void ga::Optimization_iteration()
{

	
	clock_t startTime, endTime; //定义程序开始运行时间和结束时间
	startTime = clock();        //计时开始
	//ofstream out("遗传算法优化结果.txt");
	for (int i = 0; i < E_gentic; i++)
	{
		//cout << i << "代" << endl;
		select_operator();  //选择父代更新个体
		crossover_operator();  //有交配权的所有父代进行交叉
		mutate_operator();     //个体变异
		for (int j = 0; j < N_genetic; j++)
		{
			//fitness[j] = 1 / function(x_i[j]);

			vector<double> d = { 1,2,3,4 };
			fitness[j] = 1 / func(x_i[j],Extra);
			//fitness[j] = 1 / func(x_i[j], d);
	
			//cout << "第er处:"  << endl;
			if (best_fitness < fitness[j])
			{
				best_fitness = fitness[j];
				x_best = x_i[j];
			}
		}   //种群选优
		//out << i << fixed << setw(12) << setprecision(5) << 1 / best_fitness << endl;

	}
	//out << "最优变量:" << endl;
	for (int i = 0; i < N_variable; i++)
	{
		//out << "x" << i << "=" << fixed << setw(12) << setprecision(5) << x_best[i] << endl;//输出最优变量
		//cout << "x" << i << "=" << fixed << setw(12) << setprecision(5) << x_best[i] << endl;
		result.x_fit[i] = x_best[i];
	}
	//out << "最优值=" << fixed << setw(12) << setprecision(5) << 1 / best_fitness << endl;
	//cout << "第一处:" << jflag << endl;
	//cout << "第er处:" << kflag << endl;
	//kflag = 0;
	//jflag = 0;
	//cout << "最优值=" << fixed << setw(12) << setprecision(5) << 1 / best_fitness << endl;
	result.y_best = 1/best_fitness;
	endTime = clock();//计时结束
	//out << "run time:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	cout << "run time:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	//out.close();
	
}

//*******************
//选择算子函数
//*******************
void ga::select_operator()
{

	double totalfit = 0, p_i;
	sumfitness.resize(N_genetic);
	P_i.resize(N_genetic);
	//extern RandomNumber r;       //随机数
	vector<vector<int>>new_x_binary(N_genetic, vector<int>(N_variable * L_variable));//储存选择产生的新个体
	for (int i = 0; i < N_genetic; i++)
	{
		sumfitness[i] = totalfit + fitness[i];
		totalfit = totalfit + fitness[i];
	}
	//计算个体概率
	for (int i = 0; i < N_genetic; i++)
	{
		P_i[i] = sumfitness[i] / totalfit;
	}
	//选择父代
	for (int i = 0; i < N_genetic; i++)
	{
		p_i = r.decimal(0, 1.0);
		//利用轮盘法选择个体
		if (p_i <= P_i[0])
			new_x_binary[i] = x_binary[0];
		else
		{
			for (int j = 0; j < N_genetic - 1; j++)
			{
				if (p_i > P_i[j] && p_i <= P_i[j + 1])
					new_x_binary[i] = x_binary[j + 1];
			}
		}
	}
	//更新个体
	x_binary = new_x_binary;
}
//*******************
//交叉算子函数，两点交叉
//*******************
void ga::crossover_operator()
{
	int  cpoint1, cpoint2, t;                //交叉点cpoint1, cpoint2生成,t为替换值
	double p_c;                              //随机产生交叉概率
	//extern RandomNumber r;       //随机数
	for (int i = 0; i < N_genetic; i = i + 2)
	{//随机产生两个交叉点的数
		cpoint1 = r.integer(0, N_variable * L_variable - 1);
		cpoint2 = r.integer(0, N_variable * L_variable - 1);
		if (cpoint2 < cpoint1)
		{
			t = cpoint2; cpoint2 = cpoint1; cpoint1 = t;
		}
		p_c = r.decimal(0, 1.0);
		//交叉过程
		if (p_c < C_pgentic)
		{
			for (int j = cpoint1; j <= cpoint2; j++)
			{
				t = x_binary[i][j]; x_binary[i][j] = x_binary[i + 1][j]; x_binary[i + 1][j] = t;
			}
		}
	}
}
//*******************
//变异算子函
//*******************
void ga::mutate_operator()
{
	int  mpoint;//变异点mpoint生成
	double p_m;
	//extern RandomNumber r;       //定义全局随机数
	for (int i = 0; i < N_genetic; ++i)
	{//随机产生变异点
		mpoint = r.integer(0, N_variable * L_variable - 1);
		p_m = r.decimal(0, 1.0);
		if (p_m < M_pgentic)
			if (x_binary[i][mpoint] == 0)
			{
				x_binary[i][mpoint] = 1;
			}
			else {
				x_binary[i][mpoint] = 0;
			}
	}
	//变异后的染色转换为实数
	for (int i = 0; i < N_genetic; i++)
	{
		x_i[i] = Real_trans(x_binary[i]);
	}
}
double function(vector<double> x)
{
	return  pow(x[0]-1.5,2) + pow(x[1]-4.5,2);
}

Result ga_my(double (*objf)(vector<double>, vector<double>), int nvars, vector<vector<double>> bounds,vector<double> extra)
//Result ga_my(double (*objf)(vector<double>, vector<double>), int nvars, vector<vector<double>> bounds)
{
	//cout << "test" << endl;
	ga GA;          //定义全局遗传算法相关函数
	//vector<double> extra = { 1,2,3,4 };
	//=========================设置算法参数====================
	GA.SetParameters(objf, nvars,  bounds,extra);
	//========================初始化并赋值=====================
	GA.initialize();
	//=====================优化迭代并输出结果=======================
	GA.Optimization_iteration();

	Result y = GA.result;
	return y;
}