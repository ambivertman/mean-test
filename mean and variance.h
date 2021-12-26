#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
double mean(int a[],int n)//定义mean函数
{
    int i;//定义输入
    double average,sum=0;//定义输入average存放平均数，sum存放和
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];//累加
    }
    average=sum/n;//算平均数
    return average;//返回结果
}

double var(int random[],double u,int n)//定义var函数
{
    double va;
    double sum=0;//定义输入sum，初始值为0
int k;
{
    for(k=0;k<n;++k)
    sum=sum+pow(random[k]-u,2);//调用幂函数计算pow（random[k]-u，2）计算random[k]-u的2次方求和
}
va=sum/(n-1);//计算va

return va;//返回va值
}
