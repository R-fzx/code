#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int hh[4] = {0,1,0,-1};
const int ll[4] = {1,0,-1,0};
class state_type
{
public:
	int x,y;
};

int x1,y1,x2,y2,x3,y3;
int n = 1234,m = 4321;

int color[1300][4400],dist[1300][4400];
bool check[1300][4400];

void read_data()
{
	memset(color,-1,sizeof(color));
	memset(check,false,sizeof(check));
	memset(dist,-1,sizeof(dist));
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
}

state_type Q[1234 * 4321 + 10];

int bfs()
{
	int op = 0,cl = 0;
	state_type tempstate,tostate;
	tempstate.x = x1;  tempstate.y = y1;
	Q[++op] = tempstate;
	color[x1][y1] = 1;

	tempstate.x = x2;  tempstate.y = y2;
	Q[++op] = tempstate;
	color[x2][y2] = 2;

	tempstate.x = x3;  tempstate.y = y3;
	Q[++op] = tempstate;
	color[x3][y3] = 3;

	dist[x1][y1] = dist[x2][y2] = dist[x3][y3] = 0;

	int i,tempdist,tempcolor;
	while (cl < op)
	{
		tempstate = Q[++cl];
		tempdist = dist[tempstate.x][tempstate.y];
		tempcolor = color[tempstate.x][tempstate.y];

		if (check[tempstate.x][tempstate.y]) continue;
		for (i=0;i<4;i++)
		{
			tostate.x = tempstate.x + hh[i];
			tostate.y = tempstate.y + ll[i];
			if (tostate.x < 1 || tostate.x > 1234 || tostate.y < 1 || tostate.y > 4321) continue;
			if (dist[tostate.x][tostate.y] == -1)
			{
				color[tostate.x][tostate.y] = tempcolor;
				dist[tostate.x][tostate.y] = tempdist + 1;
				Q[++op] = tostate;
			}
			else
			{
				if (dist[tostate.x][tostate.y] == tempdist + 1 && color[tostate.x][tostate.y] != tempcolor)
					check[tostate.x][tostate.y] = true;
			}
		}
	}

	int cnt = 0,j;
	for (i=1;i<=1234;i++)
		for (j=1;j<=4321;j++) if (check[i][j]) cnt++;
	return cnt;
}


int main()
{
	freopen("matrix.in", "r", stdin);
freopen("matrix.out", "w", stdout);
	read_data();
	int ans = bfs();
	cout << ans << endl;
	return 0;
}

