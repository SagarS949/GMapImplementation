#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#define maxi 100
using namespace std;

struct adjMat{

    int adj[maxi][maxi];
    int traf[maxi][maxi];

};


void addEdge(int adj[11][11],int u,int v,int weight)
{
    adj[u-1][v-1] = weight;
    adj[v-1][u-1] = weight;
}

int main()
{
     //int n=5;
    int adj[11][11],i,j;
    for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
        {
            adj[i][j] = 0;
        }
    }

    /*addEdge(adj,1,2,10);
    addEdge(adj,1,3,20);
    addEdge(adj,2,4,30);
    addEdge(adj,2,5,40);
    addEdge(adj,2,6,50);
    addEdge(adj,3,4,60);
    addEdge(adj,3,6,70);
    addEdge(adj,4,5,80);*/

    srand(time(0));
    /*addEdge(adj,1,2,rand() % 60000 + 1000);
    addEdge(adj,1,3,rand() % 60000 + 1000);
    addEdge(adj,2,4,rand() % 60000 + 1000);
    addEdge(adj,2,5,rand() % 60000 + 1000);
    addEdge(adj,2,6,rand() % 60000 + 1000);
    addEdge(adj,3,4,rand() % 60000 + 1000);
    addEdge(adj,3,6,rand() % 60000 + 1000);
    addEdge(adj,4,5,rand() % 60000 + 1000);*/

    addEdge(adj,1,2,rand() % 60000 + 1000);
    addEdge(adj,1,3,rand() % 60000 + 1000);
    addEdge(adj,1,5,rand() % 60000 + 1000);
    addEdge(adj,2,3,rand() % 60000 + 1000);
    addEdge(adj,3,4,rand() % 60000 + 1000);
    addEdge(adj,3,6,rand() % 60000 + 1000);
    addEdge(adj,4,5,rand() % 60000 + 1000);
    addEdge(adj,4,10,rand() % 60000 + 1000);
    addEdge(adj,5,7,rand() % 60000 + 1000);
    addEdge(adj,5,10,rand() % 60000 + 1000);
    addEdge(adj,6,8,rand() % 60000 + 1000);
    addEdge(adj,6,9,rand() % 60000 + 1000);
    addEdge(adj,7,8,rand() % 60000 + 1000);
    addEdge(adj,8,11,rand() % 60000 + 1000);
    addEdge(adj,9,10,rand() % 60000 + 1000);
    addEdge(adj,9,11,rand() % 60000 + 1000);


    adjMat a;

    for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
        {
            a.adj[i][j] = adj[i][j];
        }
    }

     /*for(i=0;i<6;i++)
     {
         cout<<"\n";
         for(j=0;j<6;j++)
         {
             cout<<a.adj[i][j]<<"\t";
         }
     }*/
    int speed = 833;
    int tr = 0;
    for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
        {
            if(a.adj[i][j]!=0 && i > j)
            {
                tr = rand() % 666 + 1;
                speed = speed-tr;
                a.traf[i][j] = adj[i][j]/speed;
                a.traf[j][i] = a.traf[i][j];
                speed = 833;
            }
        }
    }

    fstream f;
    f.open("adj.dat",ios::out);
    for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
        {
            f.write((char*)&a,sizeof(a));
        }
    }
    f.close();

    adjMat b;
    f.open("adj.dat",ios::in);
    for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
        {
            f.read((char*)&b,sizeof(b));
        }
    }

    f.close();

    for(i=0;i<11;i++)
    {
        cout<<"\n";
        for(j=0;j<11;j++)
        {
            cout << b.adj[i][j] << "\t";
        }
    }
    cout<<"\n"<<endl;
    for(i=0;i<11;i++)
    {
        cout<<"\n";
        for(j=0;j<11;j++)
        {
            cout << b.traf[i][j] << "\t";
        }
    }

    return 0;
}
