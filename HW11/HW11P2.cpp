#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
class MyVector
{
private:
    int dim;
public:
    double *ele;
    MyVector(int dim);
    ~MyVector();
    void print();
    double Dis(MyVector *y);
};
MyVector::MyVector(int dim)
{
    this->dim = dim;
    ele = new double [dim];
}
MyVector::~MyVector()
{
    delete [] ele;
}
void MyVector::print()
{
    cout << "( ";
    for (int i = 0; i < dim-1; i++)
        cout << ele[i] << ", ";
    cout  << ele[dim-1] << ")" <<  "\n";
}
double MyVector::Dis(MyVector *y)
{
    double sum = 0;
    for (int i = 0; i < dim; i++)
        sum += pow(this->ele[i] - y->ele[i], 2);
    return sqrt(sum);
}
 
int main()
{
    int n = 0, m = 0, k = 0, j = 0;
    cin >> n;
    cin.ignore();
    cin >> m;
    cin.ignore();
    cin >> k;
    cin.ignore();
    cin >> j;
    MyVector *x[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = new MyVector (m);
        for (int l = 0; l < m; l++)
        {
            cin >> x[i]->ele[l];
            cin.ignore();
        }
    }
     
    int index = 0, *select = new int [k];
    select[0] = j - 1;
    double max = 0, min = 9999;
    for (int i = 1; i < k; i++)
    {   
        max = 0;
        for (int h = 0; h < n; h++)
        {
            min = 9999;
            for (int l = 0; l < i; l++)
            {
                bool repeat = false;
                for (int q = 0; q < i; q++)
                {
                    if (h == select[q])
                    {
                        repeat = true;
                        break;
                    }
                }
                if (repeat)
                    continue;
                double dis = x[h]->Dis(x[select[l]]);
              cout << h << " " << select[l] << " " << dis << endl;
                if (min > dis)
                {
                    min = dis;
//                  cout << min << endl;
                }
            }
             
            if (max < min && min != 9999)
            {
                max = min;
                index = h;
//              cout << max << endl;
            }
        }
        j = index;
        select[i] = j;
    }
    cout << select[0] + 1;
    for (int i = 1; i < k; i++)
        cout << ',' << select[i] + 1;
    return 0;
}

