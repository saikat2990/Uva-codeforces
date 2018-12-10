#define _CRT_SECURE_NO_WARNINGS
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <time.h>
#include <sstream>
#include <cstdlib>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <algorithm>
#include <functional>
//#include <bits/stdc++.h>
using namespace std;

#define M 1010
#define N 1e9
#define Fn "i.txt"
#define mp make_pair
#define si(a) scanf("%d",&a)
#define sc(a) scanf("%c",&a)
#define sst(s) scanf("%s",s)
#define fo(a) freopen(a,"r",stdin)
#define si2(a,b) scanf("%d%d",&a,&b)
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rep_(i,a,b) for(int i=a;i>=b;--i)
#define Set(a,b) memset(a,b,sizeof a)
#define si3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define All(s) s.begin(),s.end()
#define Sz(a) a.size()

#define lli long long int
#define llu unsigned long long
#define Mit map<int ,int>::iterator
#define Sit set<int>::iterator
#define Vi vector<int>
#define Si set<lli>

#define Vname(A) #A

#define Bug puts("bug")


int gcd(int a, int b){ return (a == 0) ? b : (b == 0) ? a : (a%b == 0) ? b : gcd(b, a%b); }

int div_str(char s[], int a){
 int y = 0, ln = strlen(s);
 rep(i, 0, ln) y = ((y * 10) + (s[i] - '0')) % a;
 return y;
}

int dx[] = { -1, -1, 1, 1, -2, -2, 2, 2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

char init[6][6], fin[6][6] =
{
 { "11111" },
 { "01111" },
 { "00 11" },
 { "00001" },
 { "00000" }
};

int mx;
int valid(int x, int y){ return (x >= 0 && y >= 0 && x < 5 && y<5); }
int test(){
 int ok = 1;
 rep(i, 0, 5)ok &= !(strcmp(init[i], fin[i]));
 return ok;
}
void bktk(int x, int y, int c, int p1, int p2)
{

 if (c > 10)return;
 if (x == 2 && y == 2 && test()){ if (mx>c)mx = c; }
 int ok;
 rep(i, 0, 8)
 {
  int nx = x + dx[i];
  int ny = y + dy[i];
  if (valid(nx, ny) && (nx != p1 || ny != p2))
  {
   swap(init[nx][ny], init[x][y]);
   bktk(nx, ny, c + 1, x, y);
   swap(init[nx][ny], init[x][y]);
  }
 }
}
int main()
{
 //fo(Fn);
 int t, x, y;
 si(t);
 getchar();
 while (t--)
 {
  mx = 11;
  rep(i, 0, 5){
   //scanf(" %[^\n]s", init[i]);
   rep(j, 0, 5) { init[i][j] = getchar(); if (init[i][j] == ' '){ x = i; y = j; } }
   getchar();
  }
  bktk(x, y, 0, -1, -1);
        (mx == 11) ? puts("Unsolvable in less than 11 move(s).") : printf("Solvable in %d move(s).\n", mx);
 }
 return 0;
}
