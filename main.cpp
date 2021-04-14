#include <bits/stdc++.h>

#define V 11
#define MAX 10
#define MAXI 100

using namespace std;

struct adj_mat                          //structure for input matrices
{
  int adj[MAXI][MAXI];
  int traf[MAXI][MAXI];

}a;

struct name_dest                        //structure for place names
{
  char name[V][MAXI];
}m;

int minDistance(int dist[], bool sptSet[])      //function to calculate min distance
{

	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

int vis[V] = {0};
int y = 1;

void printPath(int parent[], int j, name_dest m)        //print shortest path
{
	// Base Case : If j is source
	if (parent[j] == - 1)
	{
	    vis[0] = j;
		return;
	}

	printPath(parent, parent[j], m);

	cout<<"->"<<m.name[j];
	vis[y] = j;
	y++;
}

int dist_ret(int adj[MAXI][MAXI],int dest)          //returning total length of path
{
    int i,k=0;
    int dist_tot = 0;
    for(i=0;i<V;i++)
    {
        if(vis[k]!=dest-1)
        {
            dist_tot+=adj[vis[k]][vis[k+1]];
            k++;
        }
    }
    return dist_tot;
}

int dijkstra(int graph[V][V], int src, int dest, name_dest m)   //finding shortest path
{

	int dist[V],i;

	bool sptSet[V];

	int parent[V];

	for (i = 0; i < V; i++)
	{
		parent[src] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++)
	{

		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	printPath(parent, dest, m);
	int speed;
	for (i = 0; i < V; i++)
    {
        if (i != src && i == dest)
        {
            speed = dist[i];
        }
    }
    return speed;
}

void display_head()         //display main heading
{
    cout <<"\t\t\t\t   #############################################\n";
    cout <<"\t\t\t\t   ---------------------------------------------\n";
    cout <<"\t\t\t\t   *********************************************\n";
    cout << "\n\t\t\t\t\t\t     ROUTER MAPS"<<endl<<endl;
    cout <<"\t\t\t\t   *********************************************\n";
    cout <<"\t\t\t\t   ---------------------------------------------\n";
    cout <<"\t\t\t\t   #############################################\n";

}

int main()                          //driver code
{
    int graph[V][V], i, j;

	fstream fin;

    fin.open("adj.dat",ios::in);        //open file with matrix in read mode

    if (!fin.is_open())
    {
        return -1;
    }

    for (i=0; i<V; i++)
    {
        for (j=0; j<V; j++)
        {
            fin.read((char*)&a,sizeof(a));      //reading contents from file
        }
    }

    fin.close();

    fin.open("Name.dat",ios::in);           //open file with location names in read mode
    fin.read((char*)&m,sizeof(m));          //reading contents of file

    for (i=0; i<V; i++)
    {
        for (j=0; j<V; j++)
        {
            if(a.adj[i][j]!=0)
            {
                graph[i][j] = a.adj[i][j]/(a.traf[i][j]);
            }
            else
            {
                graph[i][j] = 0;
            }

        }
    }

    int ch1;
    char ch2;
    int source,destination;
    int speed,dist_tot;
    while(1)
    {
        system("cls");
        display_head();
        cout<<"\n\nWelcome "<<endl;
        cout<<"\n\n1. Enter source and destination"<<endl;
        cout<<"2. Exit"<<endl;
        cout<<"\nEnter choice: ";
        cin>>ch1;
        if(ch1==1)
        {
            system("cls");
            display_head();
            for(i = 0; i < V; i++)
            {
              cout << i+1 <<". " << m.name[i] << "\n";
            }
            while(1)
            {
                cout<<"\n\nEnter source: ";
                cin>>source;
                cout<<"Enter destination: ";
                cin>>destination;
                if(source == destination)
                {
                    cout<<"Source and Destination are same!!!"<<endl;
                    cout<<"Please choose different Destination!!!"<<endl;
                }
                else if(source>11 || destination>11)
                {
                    cout<<"Please enter valid choice!!!"<<endl;
                }
                else
                {
                    break;
                }
            }
            cout<<"\n\nPath to be taken: "<<m.name[source-1];
            speed = dijkstra(graph, source-1, destination-1, m);
            dist_tot = dist_ret(a.adj,destination);
            cout<<"\nDistance: "<<(float)dist_tot/1000<<" km/"<<dist_tot<<" m";
            cout<<"\nTime: "<<dist_tot/speed<<" minutes"<<endl;

        }
        else if(ch1==2)
        {
            break;
        }
        else
        {
            cout<<"Enter valid input!!!!"<<endl;
        }
        cout<<"\n\nDo you want to continue(y/n)??\n";
        cin>>ch2;
        if(ch2=='n' || ch2=='N')
        {
            break;
        }
        for(i=0;i<V;i++)
        {
            vis[i] = 0;
        }
        y=1;
    }
	return 0;
}
