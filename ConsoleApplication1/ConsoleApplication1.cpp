// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <queue>

using namespace std;

queue <int> Q;

int** createG(int n)
{
	int** G = NULL;
	G = new int* [n];
	for (int i = 0; i < n; i++)
	{
		G[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
			if (i == j) G[i][j] = 0;
		}
	}
	return G;
}

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
}

void bfsd(int** G, int size, int s, int* dist)
{
	Q.push(s);
	dist[s] = 0;
	//cout << s << " ";
	while (!Q.empty())
	{
		s = Q.front();
		Q.pop();
		for (int i = 0; i < size; i++)
		{
			if (G[s][i] == 1 && dist[s] + 1 < dist[i])
			{
				Q.push(i);
				dist[i] = dist[s] + 1;
				//cout << i << " ";
				//dist[i] = dist[s] + 1;
			}
		}
	}

}
int main()
{
	setlocale(LC_ALL, "");
	int nG1 = 5;

	int s = 0;
	int* dist = (int*)malloc(nG1 * sizeof(int));
	for (int i = 0; i < nG1; i++)
	{
		dist[i] = INT_MAX;
	}
	cin >> s;
	int** G1 = createG(nG1);
	printG(G1, nG1);
	bfsd(G1, nG1, s, dist);

	for (int i = 0; i < nG1; i++)
	{
		cout << "Расстояние от " << s << " вершины до " << i << " вершины = " << dist[i] << endl;
	}
}

