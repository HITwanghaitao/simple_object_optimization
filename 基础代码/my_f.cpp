#include "my_f.h"

using namespace std;
using namespace arma;
void my_f::vc_out(vector<double> vc)
{
    cout << "vc.size()=" << vc.size() << endl;
    for (vector<double>::iterator it = vc.begin(); it < vc.end(); it++)
    {
        cout << *it << " ";

    }
    cout << endl;
}

double my_f::vc_max(vector<double> vc)
{
    sort(vc.begin(), vc.end());
    return *(vc.end() - 1);
}

void my_f::mat_out(mat M)
{
    int row = M.n_rows;
    int col = M.n_cols;
    for (int j = 0; j < row; j++)
    {
        for (int k = 0; k < col; k++)
        {
            cout << M(j, k) << " ";
        }
        cout << endl;
    }
}

void my_f::get_data(string filename, vector<vector<double>>& c_data, int D)
{

    ifstream data(filename);
    double d;
    vector<double> temp;

    int i = 0;
    while (data >> d)
        //V.push_back(d);//将数据压入堆栈。//
    {
        i = i + 1;
        temp.push_back(d);
        if (i == D)
        {
            c_data.push_back(temp);
            temp = {};
            i = 0;
        }
    }
    data.close();
}
double sim_model(vector<double> xin, vector<double> cin, int choice)
{

    Data a = Data(xin, cin);
    Data::staticDo(a);
    double y[4] = { 0 };
    double standard[] = { 537993.627149521, 2204.83053828361, 0.0380720009900398, 506562517.872436 };
    //y[0]= Data::GetMaxI(a)/standard[0];
    y[0] = Data::GetMaxI(a) ;
    y[1] = Data::GetMaxV(a) ;
    y[2] = Data::GetEff(a) ;
    y[3] = Data::GetHot(a) ;
    return y[choice - 1];

}