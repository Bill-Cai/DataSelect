// 穷举电路值.cpp : Defines the entry point for the console application.
//
/******************************Copyright(c)********************************* 
**
**                  ShenZhen Decard SmartCard Tech co.,LTD                                       
**                        http://www.decard.com
**
**------------------------------File Info----------------------------------
** File Name:             
** Latest modified Date:     
** Latest Version:            V1.00
** Description:             
**              
**-------------------------------------------------------------------------
** Created  by:               Bill            
** Created  Date:            
** Version:                   V1.00
** Descriptions:              
** 
**-------------------------------------------------------------------------
** Modified by:               Bill
** Modified Date:           
** Version:                   V1.00
** Description:     
**
***************************************************************************/ 
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

FILE *fp;
FILE *f;
double value[64] = {0};

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0,j = 0;
	double k = 0;
	double t1 = 0;
	double t2 = 0;
	bool Flag = TRUE;
	double total = 0 ; 
	int index1 = 0, index2 = 0;



	if((f=fopen("data.txt","a+"))==NULL) //打开指定文件，判断是否存在
	{
		printf("指定文件不存在!\n");
		return  -1;
	}


	while(!feof(f))
	{
		fscanf(f, "%lf", &value[i]);
		i++;
	}            

	fclose(f); //关闭句柄                              

	for(i = 0; i < 64; i++)
		cout<<value[i]<<endl;


	fp = fopen("数据.txt", "w+");
	for(i = 0; i < 64; i++)
		for(j = 0; j < 64; j++)
		{

			Flag = true;
			k = 0.3;
			{

				t1 =  (value[i] /(value[i] + value[j]))* 1.1;
				if( t1 >=  k  )
				{

					Flag = false; 

				}
			}

			k=1;
			{
				t2 =  (value[i] / (value[i] + value[j])) * 4.5;
				if(t2 <=  k)
				{
					Flag = false; 

				}

			}

			if(  (value[i] + value [j])*0.004 >= 1 )
			{
				Flag = false; 

			}


			if(Flag)
			{
				cout<< (value[i])<<"  "<<(value[j])<<endl;
				if(value[i]+ value[j] > total)
				{
					total = value[i] + value[j];
					index1 = i;
					index2 = j;
				}

			}

	}


		cout<<1<<endl;
		cout<<2<<endl;
		cout<<3<<endl;

		double R1 = value[index1];
		double R2 = value[index2];
		cout<<"R1="<<R1<<" "<<"R2="<<R2<<"   total="<<total<<endl;
		fprintf(fp, "R1=%lf, R2=%lf, total=%3lf\n",R1,R2,total);
		fclose(fp);
		return 0;
}

