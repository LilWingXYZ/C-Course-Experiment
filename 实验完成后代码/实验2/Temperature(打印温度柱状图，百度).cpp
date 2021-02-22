#include<iostream>
#include<math.h>
using namespace std;

void inputTemps(int temp[], int n)                    //输入温度
{
	cout<<"Please input the tempratures:"<<endl;

	for (int i = 0; i < n; i++)
	{
		cin>>temp[i];
	}

	cout<<endl;

}


int minTemp(int temp[], int n)           //寻找温度中的最小负值，为后面输出负值、控制格式做准备
{
	int min = temp[0];

	for (int i = 1; i < n; i++)
	{
		if (min > temp[i])
			min = temp[i];
	}

	return min;
}


void displayTemps(int temp[], int n)        //输出柱状图
{
	int min = abs(minTemp(temp, n)) + 3;       //min存储负值所占最大域宽

	cout<<"显示柱状图如下:"<<endl;

	for (int i = 0; i < n; i++)
	{
		cout.width (3);        //设置温度所占域宽

		cout<<temp[i];

		if (temp[i] < 0)       //处理负数情况
			for (int j = 0; j < min - abs(temp[i]); j++)
			{
				cout<<" ";
			}
		else                   //处理非负数情况
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
		if (temp[i] < 0)     //处理负值时，在输出柱状图后，单独输出“|”
			cout<<"|";

		cout<<endl;
	}
	cout<<endl;
}

void displayPeaks(int temp[], int n)
{
	int flag = 1;                //用于标记是否出现峰值

	cout<<"显示峰值如下:"<<endl;

	for (int i = 1; i < n - 1; i++)
	{
		if ((temp[i] > temp[i-1])&&(temp[i] > temp[i+1]))
		{
			flag = 0;

			cout<<"Max at day "<<i + 1<<" is "<<temp[i]<<endl;
		}
	}

	if (flag)
		cout<<"没有峰值."<<endl;

	cout<<endl;
}

void displayFlat(int temp[], int n)
{
	int num = 1;     //用于记录每个崮的长度
	int Max = 0;     //用于记录最长的崮

	for (int i = 1; i < n; i++)
	{
		if (temp[i] == temp[i-1])
			num++;
		else
			num = 1;          //重新记录崮的长度

		if (num > Max)
			Max = num;
	}

        if (Max != 1)                    //处理是否有崮的情况
        {
		cout<<"显示崮的长度如下:"<<endl;
		cout<<"The length of longest flat is "<<Max<<endl;
	}
    	else
		cout<<"没有崮"<<endl;

	cout<<endl;
}

int maxNum(int num[], int n)                //寻找最大值，即某个出现次数最多温度的次数
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
	int *point = new int [n] ();   //开辟动态数组，存放每个温度出现次数，并赋初值0

    for (int i = 0; i < n; i++)        //记录n个温度每一个出现的次数
	{ 
		int m = 1;

        for (int j = 0; j < n; j++)
		{
			if (i != j)     //可先判断下标，也可先判断温度
			{
		     	if (temp[i] == temp[j])
		      {
			  		m++;
			  }
			}
        }
        point[i] = m;
	}

	int b = maxNum(point ,n);     //记录出现最多的次数

	delete [] point;              //释放point所指向的空间
	point = NULL;

	for (int p = 0; p < n; p++)   //输出出现次数最多的温度
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
			cout<<"出现次数最多的数为"<<temp[p]<<",出现了"<<b<<"次."<<endl;
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
	
	
	
	
	
	
	
	
	
	 
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


