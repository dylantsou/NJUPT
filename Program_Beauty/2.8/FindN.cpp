/************************************************************************
	题目：返回能够被N整除，且由1,0组成的最小整数	
	思路：
		1、由0,1组成的整数，可以由一个数字的二进制转换得到。
		2、对于1110 % N的情况，实际可以用1000 % N + 110 % N 来表示
		3、对于小于1000的数字的 mod N 情况，不用每一次都计算。100 % N 与
	1 % N的结果是一样的，都是1，所以我们其实并不需要遍历所有小于1000的“01”
	数，然后每次都取余判断，只需要用数组记录下已经出现的余数结果就可以。然后
	遍历数组中存在的余数，与1000 % N的结果相加，判断是否等于N，若是则找到；
	若不是，则继续判断10000，同时更新数组中的余数
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int GetN(int N)
{
	int k = 0;	//每次的0，1值
	int m = 0;	//每次的余数
	int* MD = (int*)malloc( sizeof(int) * N);	//余数数组，MD[i]记录余数为i的最小0,1数
	memset(	MD,	0,	N * sizeof(int)	);	//置零

	for( int i = 0; ; i++)
	{
		k = pow(double(10),int(i));
		m = k % N; 
		if( m == 0)	return k;	

		if( !MD[m] )	MD[m] = k;		//余数m不存在，则更新之

		for( int j = 1 ; j < N ; j++)
		{
			if( MD[j] && MD[j] < k)
			{
				int t = (m + j) % N;
				if( t == 0 )
					return k + MD[j];
				else
					if( !MD[t] )
						MD[t] = k + MD[j];
			}					
		}
	}
}

int main()
{
	int m = GetN(99);
	printf("%d\n",m);
}