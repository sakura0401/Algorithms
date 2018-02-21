/* POJ 宠物小精灵之收服 4978 http://noi.openjudge.cn/ch0206/4978/ 动态规划（buttom-up）解法
   这是一个二维背包问题。
*/

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXNB = 1000;	// 最大可能的精灵球数量
const int MAXHP = 500;	// 最大可能的皮卡丘初始体力
const int MAXNP = 100;	// 最大可能的待收服宝可梦数量

int nb, hp, np;					// 精灵球数量、皮卡丘初始体力、遇到的宝可梦数量
int db[MAXNP+1], dh[MAXNP+1];	// 收服每只遇到的宝可梦需要消耗的精灵球数量和皮卡丘的体力值
int get[MAXNB+1][MAXHP+1];		// get[i][j]初始拥有i个精灵球、皮卡丘体能为j时所能收服的最多宝可梦数量
int hp1[MAXNB+1][MAXHP+1];		// hp1[i][j]初始拥有i个精灵球、皮卡丘体能为j时收服尽可能多宝可梦时所剩的最大体力

void solve();	// 动规求解该问题

int main()
{
	/* 获得输入 */
	cin >> nb >> hp >> np;
	for ( int i = 1; i <= np; ++i )
		cin >> db[i] >> dh[i];

	/* 求解 */
	solve();

	/* 打印结果 */
	cout << get[nb][hp] << " " << hp1[nb][hp] << endl;

	return 0;
}

void solve()
{
	/* 初始化数组 */
	memset(get, 0, sizeof(get));
	for ( int i = 0; i <= nb; ++i )
		for ( int j = 0; j <= hp; ++j )
			hp1[i][j] = j;

	/* 状态转移方程
	   第n轮结束后，get[i][j]的值是初始有i个精灵球、皮卡丘体力j时，从前n个宝可梦中选择收服，可能收服的最多宝可梦数量；
       hp[i][j] 为从前n只宝可梦中选择，收服尽可能多时皮卡丘剩余的最大体力 */
	for ( int i = 1; i <= np; ++i )
	{
		for ( int j = nb; j >= db[i]; --j )
		{
			for ( int k = hp; k >= dh[i]; --k )
			{
			    int t1 = j - db[i], t2 = k - dh[i];
				if ( get[j][k] == get[t1][t2] + 1 )
					hp1[j][k] = max(hp1[j][k], hp1[t1][t2]);
				else if ( get[j][k] < get[t1][t2] + 1 )
				{
					get[j][k] = get[t1][t2] + 1;
					hp1[j][k] = hp1[t1][t2];
				}
			}
		}
	}
}
