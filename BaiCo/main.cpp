#include <iostream>
#include <queue>
#include <vector>
#include <conio.h>
#include <stdio.h>
#define maxN 101

using namespace std;

char a[maxN][maxN];
int main()
{
   int r, c;
   freopen("E://input.txt", "r", stdin);
   int dx[] = {0, 0, 1, -1};
   int dy[] = {1, -1, 0, 0};

   cin >> r >> c;
   for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
        cin >> a[i][j];

    }
   }
   vector<int> v;
   queue<pair<int, int> > q;
   pair<int, int> p;
   int kq = 0;
   int maxNumberOfVertexs = 0;
   int x, y;
   for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
        if(a[i][j] == '#'){
            maxNumberOfVertexs = 1;
            a[i][j] = '.';
            kq++;
            q.push(make_pair(i, j));
            while(!q.empty()){
                p = q.front();
                q.pop();
                for(int k=0; k<4; k++){
                    x = p.first + dx[k];
                    y = p.second + dy[k];
                    if(a[x][y] == '#'){
                        maxNumberOfVertexs++;
                        a[x][y] = '.';
                        q.push(make_pair(x, y));
                    }
                }

            }
            v.push_back(maxNumberOfVertexs);
        }
    }
   }
   cout << kq << endl;
   int index = 0;
   int Max = 0;
    for(unsigned int i = 0; i <  v.size(); i++){
        if(v[i] > Max){
            Max = v[i];
            index = i;
        }
    }
    cout << v[index];
    getch();
    return 0;
}
