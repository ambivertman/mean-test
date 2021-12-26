#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mean and variance.h"

int main()
{
    int n,choice,i,charger=1;      //定义输入均值、选择置信区间以及一个控制程序循环执行的变量
    double v,u,bias,lower,upper,a,x,*p;//定义均值、方差、偏差、置信区间取值以及动态储存样本数据的指针

    while(charger){
    printf("请输入样本个数n(n>0):");//请输入样本个数
    scanf("%d",&n);    //读取输入的样本个数，保存于n变量
    printf("请输入想检验的均值:");  //输入想检验的均值
    scanf("%lf",&x); //读取输入的均值，保存于x变量
    if((p = (double *)calloc(n,sizeof(double)))==NULL)
    {
        printf("Not able to allocate memory.");
        exit(1);
    }
    printf("请输入%d个样本:",n);   //输入样本的数值
    for(i=0; i<n; i++) //for循环语句，将样本数值保存到random数组
    {
        scanf("%lf",p+i);
    }
    u=mean(p,n);//调用mean函数，计算样本均值
    printf("u=%.2lf\n",u);
    v=var(p,u,n);//调用var函数，计算样本的方差
    printf("var=%lf\n",v);//输出样本方差
    printf("从下方列表选择置信度:\n");
    printf("    1:90%%的置信度\n");//可供选择的90%的置信度
    printf("    2:95%%的置信度\n"); //可供选择的95%的置信度
    printf("    3:95.45%%的置信度\n");//可供选择的95.45%的置信度
    printf("    4:99.73%%的置信度\n");//可供选择的99.73%的置信度
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
    default:
        printf("请1~4中选择置信度!\n");
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
    free(p);
    printf("输入“1”以继续运行，否则输入“0”以终止:");
    scanf("%d",&charger);
    }

    return 0;
}
