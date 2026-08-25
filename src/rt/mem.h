#ifndef __MEM_H__  // __MEM_H__
#define __MEM_H__

#include "precision.h"

float *f1dim(int,int);
void del_f1dim(float*,int,int);
float **f2dim(int,int,int,int);
void del_f2dim(float**,int,int,int,int);
float ***f3dim(int,int,int,int,int,int);
void del_f3dim(float***,int,int,int,int,int,int);

double *d1dim(int,int);
void del_d1dim(double*,int,int);
double ***d3dim(int,int,int,int,int,int);
void del_d3dim(double***,int,int,int,int,int,int);

int ***i3dim(int,int,int,int,int,int);
void del_i3dim(int***,int,int,int,int,int,int);
int ***** i5dim(int,int,int,int,int,int,int,int,int,int);
void del_i5dim(int*****,int,int,int,int,int,int,int,int,int,int);

#endif             // __MEM_H__
