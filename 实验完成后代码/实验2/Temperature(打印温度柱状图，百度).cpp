#include<iostream>
#include<math.h>
using namespace std;

void inputTemps(int temp[], int n)                    //�����¶�
{
	cout<<"Please input the tempratures:"<<endl;

	for (int i = 0; i < n; i++)
	{
		cin>>temp[i];
	}

	cout<<endl;

}


int minTemp(int temp[], int n)           //Ѱ���¶��е���С��ֵ��Ϊ���������ֵ�����Ƹ�ʽ��׼��
{
	int min = temp[0];

	for (int i = 1; i < n; i++)
	{
		if (min > temp[i])
			min = temp[i];
	}

	return min;
}


void displayTemps(int temp[], int n)        //�����״ͼ
{
	int min = abs(minTemp(temp, n)) + 3;       //min�洢��ֵ��ռ������

	cout<<"��ʾ��״ͼ����:"<<endl;

	for (int i = 0; i < n; i++)
	{
		cout.width (3);        //�����¶���ռ���

		cout<<temp[i];

		if (temp[i] < 0)       //���������
			for (int j = 0; j < min - abs(temp[i]); j++)
			{
				cout<<" ";
			}
		else                   //����Ǹ������
		{
			for (int j = 0; j < min; j++)
			{
				cout<<" ";
			}

			cout<<"|";
		}

		for (int k = 0; k < abs(temp[i]); k++)
		{
			cout<<"*";
		}
		if (temp[i] < 0)     //����ֵʱ���������״ͼ�󣬵��������|��
			cout<<"|";

		cout<<endl;
	}
	cout<<endl;
}

void displayPeaks(int temp[], int n)
{
	int flag = 1;                //���ڱ���Ƿ���ַ�ֵ

	cout<<"��ʾ��ֵ����:"<<endl;

	for (int i = 1; i < n - 1; i++)
	{
		if ((temp[i] > temp[i-1])&&(temp[i] > temp[i+1]))
		{
			flag = 0;

			cout<<"Max at day "<<i + 1<<" is "<<temp[i]<<endl;
		}
	}

	if (flag)
		cout<<"û�з�ֵ."<<endl;

	cout<<endl;
}

void displayFlat(int temp[], int n)
{
	int num = 1;     //���ڼ�¼ÿ���ĵĳ���
	int Max = 0;     //���ڼ�¼�����

	for (int i = 1; i < n; i++)
	{
		if (temp[i] == temp[i-1])
			num++;
		else
			num = 1;          //���¼�¼�ĵĳ���

		if (num > Max)
			Max = num;
	}

        if (Max != 1)                    //�����Ƿ����ĵ����
        {
		cout<<"��ʾ�ĵĳ�������:"<<endl;
		cout<<"The length of longest flat is "<<Max<<endl;
	}
    	else
		cout<<"û����"<<endl;

	cout<<endl;
}

int maxNum(int num[], int n)                //Ѱ�����ֵ����ĳ�����ִ�������¶ȵĴ���
{
	int max = num[0];

	for (int i = 1; i < n; i++)
	{
		if (max < num[i])
			max = num[i];
	}

	return max;
}

void mostNum(int temp[], int n)
{
	int *point = new int [n] ();   //���ٶ�̬���飬���ÿ���¶ȳ��ִ�����������ֵ0

    for (int i = 0; i < n; i++)        //��¼n���¶�ÿһ�����ֵĴ���
	{ 
		int m = 1;

        for (int j = 0; j < n; j++)
		{
			if (i != j)     //�����ж��±꣬Ҳ�����ж��¶�
			{
		     	if (temp[i] == temp[j])
		      {
			  		m++;
			  }
			}
        }
        point[i] = m;
	}

	int b = maxNum(point ,n);     //��¼�������Ĵ���

	delete [] point;              //�ͷ�point��ָ��Ŀռ�
	point = NULL;

	for (int p = 0; p < n; p++)   //������ִ��������¶�
    {
        int q = 1;

        for (int r = 0; r < n; r++)
		{
                if (temp[p] == temp[r])
				{
					if (r > p)
						q++;
                }
			
		}
        if (q == b)
        {
			cout<<"���ִ���������Ϊ"<<temp[p]<<",������"<<b<<"��."<<endl;
		}
	}
}


int main()
{
	int temps[15];

	inputTemps(temps, 15);
	displayTemps(temps, 15);
	displayPeaks(temps, 15);
	displayFlat(temps, 15);
	mostNum(temps, 15);

	return 0;
}
	
	
	
	
	
	
	
	
	
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


