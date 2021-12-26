#ifndef MEAN_AND_VARIANCE_H_INCLUDED
#define MEAN_AND_VARIANCE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double mean(int a[],int n);//mean函数用于计算均值
double var(int random[],double u,int n);//var函数用于计算方差

double mean(double *p,int n)//定义mean函数
{
    int i;//定义输入
    double average,sum=0;//定义输入average存放平均数，sum存放和
    for(i=0;i<n;i++)
    {
        sum+=*(p+i);//累加
    }
    average=sum/n;//算平均数

    return average;//返回结果
}

double var(double *p,double u,int n)//定义var函数
{
    double va;
    double sum=0;//定义输入sum，初始值为0
    int k;

    for(k=0;k<n;k++){
    sum=sum+pow(*(p+k)-u,2);//计算σ^2*n
    }
    va=sum/n;//计算va

    return va;//返回va值
}


#endif // MEAN_AND_VARIANCE_H_INCLUDED
