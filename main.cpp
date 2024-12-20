#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h> 
#include <iostream>

using namespace std;

int** createG(int size)
{
	int** G;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		G[i] = (int*)malloc(size * sizeof(int));
	}
	for (int i = 0; i < size; i++)
	{
		G[i][i] = 0;
		for (int j = i + 1; j < size; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}
	return G;
};

void printG(int** G, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
};
void DFS(int** G, int size, int start, int* vis)
{
	vis[start] = 1;
	cout << start << " -> ";
	for (int i = 0; i < size; i++)
	{
		if (G[start][i] == 1 && vis[i] == 0) DFS(G, start, i, vis);
	}
};
//#PotatoFreeGureev
int main()
{
	int** G = NULL;
	int nG = 0, s;
	cout << "Vvedite razmer grafa: ";
	cin >> nG;
	cout << endl;

	G = createG(nG);
	printG(G, nG);

	cout << "\nVvedite startovuy vershinu: ";
	cin >> s;

	int* vis = (int*)malloc(nG * sizeof(int));
	for (int i = 0; i < nG; i++)
	{
		vis[i] = 0;
	}

	DFS(G, nG, s, vis);
	return 0;
}