#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin){
  
  for(int i=0; i<N; i++)
       cout << i*dx + xmin << "\t" << p[i] << endl;
}

void fill(double* p, const int N, const double dx, const double xmin){
   
  for(int i=0; i<N; i++){
    double x = i*dx + xmin;
    p[i] = exp(-x*x);
  }
}

void deriv(double* p, const int N, const double dx){
  
  double A;
  double B = 0;
  
  for(int i=0; i<N-1; i++){
    
    A = B;
    B = p[i];
    p[i] = (p[i+1] - A) / (2*dx);
    
  }
  p[N-1] = -p[N-2]/(2*dx);
}


int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  // call to function which fills array p here
  fill(p,N,dx,xmin);
  // call to function which calculates the derivative
  deriv(p,N,dx);
  
  print(p,N,dx,xmin);

  return 0;
}
