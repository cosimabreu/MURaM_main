#include "mem.h"

float *f1dim(int x1l,int x1h)
{
  return new float [x1h-x1l+1] - x1l;
}

void del_f1dim(float *p,int x1l,int x1h)
{
  delete[] (p+x1l);
}
float **f2dim(int x1l,int x1h,int x2l,int x2h)
{
  int nx1=x1h-x1l+1,nx2=x2h-x2l+1;
  float **p;
  p=new float* [nx1] - x1l;
  p[x1l]=new float [nx1*nx2] - x2l;
  for(int x1=x1l+1;x1<=x1h;++x1) p[x1]=p[x1-1]+nx2;
  return p;
}

void del_f2dim(float **p,int x1l, int x1h, int x2l, int x2h)
{
  delete[] (p[x1l]+x2l);
  delete[] (p+x1l);
}

float ***f3dim(int x1l,int x1h,int x2l,int x2h,int x3l,int x3h)
{
  int nx1=x1h-x1l+1,nx2=x2h-x2l+1,nx3=x3h-x3l+1;
  float ***p;
  p=new float** [nx1] - x1l;
  p[x1l]=new float* [nx1*nx2] - x2l;
  p[x1l][x2l]=new float [nx1*nx2*nx3] - x3l;
  for(int x2=x2l+1;x2<=x2h;++x2) p[x1l][x2]=p[x1l][x2-1]+nx3;
  for(int x1=x1l+1;x1<=x1h;++x1){
    p[x1]=p[x1-1]+nx2;
    p[x1][x2l]=p[x1-1][x2l]+nx2*nx3;
    for(int x2=x2l+1;x2<=x2h;++x2) p[x1][x2]=p[x1][x2-1]+nx3;
  }
  return p;
}

void del_f3dim(float ***p,int x1l,int x1h,int x2l,int x2h,int x3l,int x3h)
{
  delete[] (p[x1l][x2l]+x3l);
  delete[] (p[x1l]+x2l);
  delete[] (p+x1l);
}

double *d1dim(int x1l,int x1h)
{
  return new double [x1h-x1l+1] - x1l;
}

void del_d1dim(double *p,int x1l,int x1h)
{
  delete[] (p+x1l);
}

double ***d3dim(int x1l,int x1h,int x2l,int x2h,int x3l,int x3h)
{
  int nx1=x1h-x1l+1,nx2=x2h-x2l+1,nx3=x3h-x3l+1;
  double ***p;
  p=new double** [nx1] - x1l;
  p[x1l]=new double* [nx1*nx2] - x2l;
  p[x1l][x2l]=new double [nx1*nx2*nx3] - x3l;
  for(int x2=x2l+1;x2<=x2h;++x2) p[x1l][x2]=p[x1l][x2-1]+nx3;
  for(int x1=x1l+1;x1<=x1h;++x1){
    p[x1]=p[x1-1]+nx2;
    p[x1][x2l]=p[x1-1][x2l]+nx2*nx3;
    for(int x2=x2l+1;x2<=x2h;++x2) p[x1][x2]=p[x1][x2-1]+nx3;
  }
  return p;
}

void del_d3dim(double ***p,int x1l,int x1h,int x2l,int x2h,int x3l,int x3h)
{
  delete[] (p[x1l][x2l]+x3l);
  delete[] (p[x1l]+x2l);
  delete[] (p+x1l);
}

int ***i3dim(int x1l,int x1h,int x2l,int x2h,int x3l,int x3h)
{
  int nx1=x1h-x1l+1,nx2=x2h-x2l+1,nx3=x3h-x3l+1;
  int ***p;
  p=new int** [nx1] - x1l;
  p[x1l]=new int* [nx1*nx2] - x2l;
  p[x1l][x2l]=new int [nx1*nx2*nx3] - x3l;
  for(int x2=x2l+1;x2<=x2h;++x2) p[x1l][x2]=p[x1l][x2-1]+nx3;
  for(int x1=x1l+1;x1<=x1h;++x1){
    p[x1]=p[x1-1]+nx2;
    p[x1][x2l]=p[x1-1][x2l]+nx2*nx3;
    for(int x2=x2l+1;x2<=x2h;++x2) p[x1][x2]=p[x1][x2-1]+nx3;
  }
  return p;
}

void del_i3dim(int ***p,int x1l,int x1h,int x2l,int x2h,int x3l,int x3h)
{
  delete[] (p[x1l][x2l]+x3l);
  delete[] (p[x1l]+x2l);
  delete[] (p+x1l);
}

int ***** i5dim(int x1l,int x1h,int x2l,int x2h,int x3l,int x3h,int x4l,int x4h,int x5l, int x5h)
{
  int nx1=x1h-x1l+1,nx2=x2h-x2l+1,nx3=x3h-x3l+1,nx4=x4h-x4l+1,nx5=x5h-x5l+1;
  int *****p;
  p=new int**** [nx1] - x1l;
  p[x1l]=new int*** [nx1*nx2] - x2l;
  p[x1l][x2l]=new int** [nx1*nx2*nx3] - x3l;
  p[x1l][x2l][x3l]=new int* [nx1*nx2*nx3*nx4] - x4l;
  p[x1l][x2l][x3l][x4l]=new int [nx1*nx2*nx3*nx4*nx5] - x5l;
  
  for(int x4=x4l+1;x4<=x4h;++x4) p[x1l][x2l][x3l][x4]=p[x1l][x2l][x3l][x4-1]+nx5;
  for(int x3=x3l+1;x3<=x3h;++x3){
    p[x1l][x2l][x3]=p[x1l][x2l][x3-1]+nx4;    
    p[x1l][x2l][x3][x4l]=p[x1l][x2l][x3-1][x4l]+nx4*nx5;
    for(int x4=x4l+1;x4<=x4h;++x4) p[x1l][x2l][x3][x4]=p[x1l][x2l][x3][x4-1]+nx5;
  }
  for(int x2=x2l+1;x2<=x2h;++x2){
    p[x1l][x2]=p[x1l][x2-1]+nx3;
    p[x1l][x2][x3l]=p[x1l][x2-1][x3l]+nx3*nx4;
    p[x1l][x2][x3l][x4l]=p[x1l][x2-1][x3l][x4l]+nx3*nx4*nx5;
    for(int x4=x4l+1;x4<=x4h;++x4) p[x1l][x2][x3l][x4]=p[x1l][x2][x3l][x4-1]+nx5;
    for(int x3=x3l+1;x3<=x3h;++x3){
      p[x1l][x2][x3]=p[x1l][x2][x3-1]+nx4;
      p[x1l][x2][x3][x4l]=p[x1l][x2][x3-1][x4l]+nx4*nx5;
      for(int x4=x4l+1;x4<=x4h;++x4) p[x1l][x2][x3][x4]=p[x1l][x2][x3][x4-1]+nx5;
    }
  }	
  for(int x1=x1l+1;x1<=x1h;++x1) {
    p[x1]=p[x1-1]+nx2;
    p[x1][x2l]=p[x1-1][x2l]+nx2*nx3;
    p[x1][x2l][x3l]=p[x1-1][x2l][x3l]+nx2*nx3*nx4;
    p[x1][x2l][x3l][x4l]=p[x1-1][x2l][x3l][x4l]+nx2*nx3*nx4*nx5;
    for(int x4=x4l+1;x4<=x4h;++x4) p[x1][x2l][x3l][x4]=p[x1][x2l][x3l][x4-1]+nx5;
    for(int x3=x3l+1;x3<=x3h;++x3){
      p[x1][x2l][x3]=p[x1][x2l][x3-1]+nx4;
      p[x1][x2l][x3][x4l]=p[x1][x2l][x3-1][x4l]+nx4*nx5;
      for(int x4=x4l+1;x4<=x4h;++x4) p[x1][x2l][x3][x4]=p[x1][x2l][x3][x4-1]+nx5;
    }
    for(int x2=x2l+1;x2<=x2h;++x2){
      p[x1][x2]=p[x1][x2-1]+nx3;
      p[x1][x2][x3l]=p[x1][x2-1][x3l]+nx3*nx4;
      p[x1][x2][x3l][x4l]=p[x1][x2-1][x3l][x4l]+nx3*nx4*nx5;
      for(int x4=x4l+1;x4<=x4h;++x4) p[x1][x2][x3l][x4]=p[x1][x2][x3l][x4-1]+nx5;
      for(int x3=x3l+1;x3<=x3h;++x3){
        p[x1][x2][x3]=p[x1][x2][x3-1]+nx4;
        p[x1][x2][x3][x4l]=p[x1][x2][x3-1][x4l]+nx4*nx5;
        for(int x4=x4l+1;x4<=x4h;++x4) p[x1][x2][x3][x4]=p[x1][x2][x3][x4-1]+nx5;
      }
    }
  }
  return p;
}

void del_i5dim(int *****p,int x1l,int x1h,int x2l,int x2h,int x3l,int x3h,int x4l,int x4h,int x5l, int x5h)
{
  delete[] (p[x1l][x2l][x3l][x4l]+x5l);
  delete[] (p[x1l][x2l][x3l]+x4l);
  delete[] (p[x1l][x2l]+x3l);
  delete[] (p[x1l]+x2l);
  delete[] (p+x1l);
}

