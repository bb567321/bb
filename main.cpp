#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

ofstream fout;  //������ļ�

//�����
char sign1[2]={'+', '-'};
char sign2[2]={'*','/'};
char sign3[4]={'+', '-','*','/'};

char sign(int x)   //���������
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

double randnum(int m,int f)   //����������
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
	int num;   //��Ŀ����
	int sch;   //������ʽ
	int max;   //���ֵ
	int flag1,flag2;  //ѡ���־
	int out;   //�����ʽ

	while(1)
	{
		cout<<"��������Ŀ����"<<endl;
		cin>>num;
		cout<<"��ѡ���������1.�Ӽ�����  2.�˳�����  3.��������"<<endl;
		cin>>sch;
		cout<<"���趨���������ֵ(ʮ���ڡ������ڵȣ�"<<endl;
		cin>>max;
		cout<<"��������Ƿ�������ţ�0.��  1.��"<<endl;
		cin>>flag1;
		cout<<"��������Ƿ����С����0.��  1.��"<<endl;
		cin>>flag2;
		cout<<"ѡ�������ʽ��1.������ļ�  2.�������ӡ��"<<endl;
		cin>>out;
		if(out==1)
		{
			fout.open("jst.txt");
			while(num>0)
			{
				double n;   //������
				char ch;   //�����
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
				double n;   //������
				char ch;   //�����
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
		int flag3;   //������־
		cout<<"�Ƿ������0.��  1.��"<<endl;
		cin>>flag3;
		if(flag3==1)
			break;
	}
	return 0;
}
