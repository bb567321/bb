#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

ofstream fout;  //输出到文件

//运算符
char sign1[2]={'+', '-'};
char sign2[2]={'*','/'};
char sign3[4]={'+', '-','*','/'};

char sign(int x)   //生成运算符
{
	char ch;
	switch(x)
	{
		case 1:
			{
				ch=sign1[rand()%2];
				break;
			}
			case 2:
			{
				ch=sign2[rand()%2];
				break;
			}
			case 3:
			{
				ch=sign3[rand()%4];
				break;
			}
	}
	return ch;
}

double randnum(int m,int f)   //生成运算数
{
	if(f==0)
	{
		int n;
		n=rand()%m+1;
		return n;
	}
	else
	{
		float n;
		n=rand()%m+rand()%10*0.1;
		return n;
	}
}

int main()
{
	int num;   //题目数量
	int sch;   //运算形式
	int max;   //最大值
	int flag1,flag2;  //选择标志
	int out;   //输出方式

	while(1)
	{
		cout<<"请输入题目数量"<<endl;
		cin>>num;
		cout<<"请选择运算符：1.加减运算  2.乘除运算  3.四则运算"<<endl;
		cin>>sch;
		cout<<"请设定运算数最大值(十以内、百以内等）"<<endl;
		cin>>max;
		cout<<"运算过程是否出现括号：0.否  1.是"<<endl;
		cin>>flag1;
		cout<<"运算过程是否出现小数：0.否  1.是"<<endl;
		cin>>flag2;
		cout<<"选择输出方式：1.输出到文件  2.输出到打印机"<<endl;
		cin>>out;
		if(out==1)
		{
			fout.open("jst.txt");
			while(num>0)
			{
				double n;   //运算数
				char ch;   //运算符
				n=randnum(max,flag2);
				fout<<n;
				for(int i=0;i<4;i++)
				{
					ch=sign(sch);
					fout<<ch;
					n=randnum(max,flag2);
					fout<<n;
				}
				fout<<"="<<endl;
			num--;
			}
			fout.close();
		}
		if(out==2)
		{
			while(num>0)
			{
				double n;   //运算数
				char ch;   //运算符
				n=randnum(max,flag2);
				cout<<n;
				for(int i=0;i<4;i++)
				{
					ch=sign(sch);
					cout<<ch;
					n=randnum(max,flag2);
					cout<<n;
				}
				cout<<"="<<endl;
			num--;
			}
		}
		int flag3;   //结束标志
		cout<<"是否结束：0.否  1.是"<<endl;
		cin>>flag3;
		if(flag3==1)
			break;
	}
	return 0;
}
