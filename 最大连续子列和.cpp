/* 求序列的最大连续子列和，复杂度 O(N)，N为序列长度 */

#include <iostream>
#include <cstring>
using namespace std;

const int INF = 128;

int maxSubSequence(int * a, int len)	// a的有效元素从a[1]开始
{
	int ms = -INF;
	int es = 0;
	for ( int i = 1; i <= len; ++i )
	{
		if ( es > 0 )
			es = es + a[i];
		else
			es = a[i];
		if ( ms < es )
			ms = es;
	}
	return ms;
}

int main()
{
    // 测试
    int a1[] = {0, -1, -2, -5, -1, -9};
    cout << maxSubSequence(a1, 5) << endl;
    int a2[] = {0, 1, 3, -2, 5, -7, 2, 100, -90};
    cout << maxSubSequence(a2, 8) << endl;
    int a3[] = {0, -1, 0};
    cout << maxSubSequence(a3, 1) << endl;
    return 0;
}
