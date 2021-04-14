#include <bits/stdc++.h>
#define INFINITE 9999
#define MAX 10
#define MAXI 100

using namespace std;

struct adj_mat
{
  int adj[MAXI][MAXI];
  int traf[MAXI][MAXI];

}a;

void Dijkstra(int Graph[MAX][MAX], int n, int start, int dest);

void Dijkstra(int Graph[MAX][MAX], int n, int start, int dest)
{
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindistance, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INFINITE;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindistance = INFINITE;

    for (i = 0; i < n; i++)
      if (distance[i] < mindistance && !visited[i]) {
        mindistance = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i]) {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != start && i == dest) {
      printf("\nDistance from source to %d: %d", i, distance[i]);
    }
}
int main()
{
  int Graph[MAX][MAX], i, j, n, u, v;
  n = 6;

  fstream fin;

  fin.open("adj.dat",ios::in);

  if (!fin.is_open())
    return -1;

  for (i=0; i<6; i++)
  {
    for (j=0; j<6; j++)
    {
        fin.read((char*)&a,sizeof(a));
    }
  }

  fin.close();

  for (i=0; i<6; i++)
  {
    //cout<<"\n";
    for (j=0; j<6; j++)
    {
        if(a.adj[i][j]!=0)
        {
            Graph[i][j] = a.adj[i][j]/(a.traf[i][j]);
            //cout << Graph[i][j] << "\t";
        }
        else
        {
            Graph[i][j] = 0;
        }

    }
  }

  //cout << "\n";

  u = 2;
  v = 4;
  Dijkstra(Graph, n, u, v);

  return 0;
}
