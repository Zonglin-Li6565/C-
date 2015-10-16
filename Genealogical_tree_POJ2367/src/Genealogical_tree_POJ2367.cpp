//============================================================================
// Name        : Genealogical_tree_POJ2367.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct Node
{
	vector<int> greaterthan;
};

int totalnumber, temp;
int* status;
vector<int> order;
Node* nodes;

void toposort(int next);

int main() {
	scanf("%d", &totalnumber);
	nodes = new Node[totalnumber];
	/*********Reading inputs*********/
	for(int i = 0; i < totalnumber; i++)
	{
		while(true)
		{
			scanf("%d", &temp);
			if(temp == 0) break;
			nodes[i].greaterthan.push_back(temp - 1);
		}
	}
	/*********Topological sort*********/
	status = new int[totalnumber];
	for(int i = 0; i < totalnumber; i++)
	{
		status[i] = 0;
	}
	for(int i = 0; i < totalnumber; i++)
	{
		if(status[i] == 0){
			toposort(i);
		}
	}
	for(int i = order.size() - 1; i > 0; i--)
	{
		cout << order[i] + 1 << " ";
	}
	cout << order[0] + 1;
	return 0;
}

/**
 * performs topological sort
 */
void toposort(int next)
{
	status[next] = -1;
	//printf("start visiting %d\n", next + 1);
	vector<int> nexts = nodes[next].greaterthan;
	int size = nexts.size();
	for(int i = 0; i < size; i++)
	{
		if(status[nexts[i]] < 0) return;
		if(status[nexts[i]] == 0) toposort(nexts[i]);
	}
	status[next] = 1;
	//printf("pushed %d\n", next + 1);
	order.push_back(next);
}
