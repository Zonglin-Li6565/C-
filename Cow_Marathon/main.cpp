#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int largestdistance = 0, n, m, length, from, to, bdistance, Maxindex;
char direction[2];
int* table;
int* indegrees;

struct farm
{
    vector<farm*> to;
    vector<int> length;
    int self;
};

int BFS(farm* start, int n, int m);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    farm* f = new farm[n];
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%s", &from, &to, &bdistance, direction);
        from --;
        to --;
        f[from].to.push_back(&f[to]);
        f[from].length.push_back(bdistance);
        f[from].self = from;
        f[to].to.push_back(&f[from]);
        f[to].length.push_back(bdistance);
        f[to].self = to;
    }
    BFS(&f[0], n, m);
    int Max = BFS(&f[Maxindex], n, m);
    cout << Max;
    delete[] f;
    return 0;
}

int BFS(farm* start, int n, int m)
{
    int* visited = new int[n];
    int* distance = new int[n];
    int Max = 0;
    queue<farm*> farms;
    for(int i = 0; i < n; i++){
        visited[i] = distance[i] = 0;
    }
    farms.push(start);
    while(farms.size() > 0)
    {
        farm* current = farms.front();
        farms.pop();
        visited[current->self] = 1;
        for(int i = 0; i < current->to.size(); i++)
        {
            int visitingindex = current->to[i]->self;
            if(!visited[visitingindex])
            {
                if(distance[current->self] + current->length[i] > distance[visitingindex])
                {
                    distance[visitingindex] = distance[current->self] + current->length[i];
                    if(Max < distance[visitingindex])
                    {
                        Max = distance[current->to[i]->self];
                        Maxindex = visitingindex;
                    }
                }
                farms.push(current->to[i]);
            }
        }
    }
    delete[] visited;
    delete[] distance;
    return Max;
}
