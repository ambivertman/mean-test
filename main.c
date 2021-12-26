#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>
#include"mean and variance.h"
double mean(int a[],int n);//mean函数原型说明
double var(int random[],double u,int n);//var函数原型说明
int main()
{
    int n,choice,i;      //定义输入均值、选择置信区间
    double v,u,bias,lower,upper,a,x;//定义均值、方差、偏差、置信区间取值
    printf("Enter n(n>0):\n");//请输入样本个数
    scanf("%d",&n);    //读取输入的样本个数，保存于n变量
    printf("请输入想检验的均值:\n");  //输入想检验的均值
    scanf("%lf",&x); //读取输入的均值，保存于x变量
    int random[n]; //定义范围为n的数组
    printf("请输入样本");   //输入样本的数值
    for(i=0; i<n; ++i) //for循环语句，将样本数值保存到random数组
    {
        scanf("%d",&random[i]);
        printf("\n");
    }
    u=mean(random,n);//调用mean函数，计算样本均值
    printf("u=%.2lf\n",u);
    v=var(random,u,n);//调用var函数，计算样本的方差
    printf("var=%lf\n",v);//输出样本方差
    printf("1:90%%的置信度\n");//可供选择的90%的置信度
    printf("2:95%%的置信度\n"); //可供选择的95%的置信度
    printf("3:95.45%%的置信度\n");//可供选择的95.45%的置信度
    printf("4:99.73%%的置信度\n");//可供选择的99.73%的置信度
    printf("请选择置信度：");
    scanf("%d",&choice);//输入想要检测的置信度
    switch(choice)      //switch函数选择置信度
    {
    case 1:
        a=1.645;
        break;
    case 2:
        a=1.96;
        break;
    case 3:
        a=2;
        break;
    case 4:
        a=3;
        break;
    }
    bias=a*sqrt(v)/sqrt(n);//计算可接受的偏差
    lower=u-bias;//计算置信区间的左端点
    upper=u+bias;//计算置信区间的右端点
    printf("区间为{%lf,%lf}",lower,upper);//输出置信区间
    if(lower<=x&&x<=upper)//判断输入均值是否属于置信区间范围
    {
        printf("接受原假设\n");//满足条件则接受原假设
    }
    else
    {
        printf("拒绝原假设\n");//不满足条件则拒绝原假设
    }
    return 0;
}
