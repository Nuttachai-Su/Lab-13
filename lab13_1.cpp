#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double a[],int n,double b[]){
    for (int i=0; i<n; i++) b[0] += a[i]; //Arithmetic Mean
    b[0] = b[0] / n;

    for (int i=0; i<n; i++) b[1] += pow(a[i] - b[0], 2); //Standard Deviation
    b[1] = b[1] / n;
    b[1] = pow(b[1],0.5);

    b[2] = 1; //Geometric Mean
    for (int i=0; i<n; i++) b[2] *= a[i];
    b[2] = pow(b[2],1.0/n);

    for (int i=0; i<n; i++) b[3] += 1/a[i]; //Harmonic Mean
    b[3] = n / b[3];

    for (int i=0; i<n; i++) if(b[4]<a[i]) b[4] = a[i];

    b[5] = a[0];
    for (int i=0; i<n; i++) if(b[5]>a[i]) b[5] = a[i];

}