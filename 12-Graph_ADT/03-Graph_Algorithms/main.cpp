#include <iostream>
#include <vector>
#include <climits>
#include "heap.h"
using namespace std;

class Graph{
    private:
        vector <vector <int>> matrix;
        int n;                          //vertices
    public:
        Graph(int vertices){
            n=vertices;
            matrix.resize(n, vector<int>(n, 0));
        }
        void delete1(int u,int v){
            if (n>u && n>v){
                matrix[u][v]=0;
                matrix[v][u]=0;
            }
        }
        void insert(int u,int v,int weight){
            if (n>u && n>v){
                matrix[u][v]=weight;
                matrix[v][u]=weight;
            }
        }
        void display(){
            cout<<"\n\nAdjacency Matrix: \n";
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
        }

        void prims(){
            cout<<"\n";
            heap h1(n*n);
            vector <int> visited(n,0);
            node newnode;
            newnode.weight=0;
            newnode.vertex=0;
            newnode.parent=-1;
            h1.insert(newnode);
            int ttlweight=0;
            while(h1.getCurr()!=0){
                node rootNode=h1.delete1();
                int rNvert=rootNode.vertex;     //vertex of the root node which is deleted

                if (visited[rNvert]==1){
                    continue;
                }
                visited[rNvert]=1;

                if (rootNode.parent!=-1){
                    cout<<"Edge: "<<rootNode.parent<<" - "<<rNvert<<" | "<<"Weight: "<<rootNode.weight<<endl;
                    ttlweight+=rootNode.weight;
                } 

                for (int i=0;i<n;i++){
                    if (matrix[rNvert][i]!=0 && visited[i]==0){
                        node newnode;
                        newnode.weight=matrix[rNvert][i];
                        newnode.vertex=i;
                        newnode.parent=rNvert;
                        h1.insert(newnode);
                    }
                }
            }
            cout<<"Total weight: "<<ttlweight;
        }

        void kruskals(){
            cout<<"\n";
            int visited[n];
            int ttlweight=0;
            for (int i=0;i<n;i++){
                visited[i]=0;
            }
            heap h3(n*n);
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    if(matrix[i][j]!=0 ){
                        node newnode;
                        newnode.weight=matrix[i][j];
                        newnode.parent=i;
                        newnode.vertex=j;
                        h3.insert(newnode);
                    }
                }
            }

            while(h3.getCurr()!=0){
                node rootNode=h3.delete1();
                if (!(visited[rootNode.parent]==1 && visited[rootNode.vertex]==1)){
                    cout<<"Edge: "<<rootNode.parent<<" - "<<rootNode.vertex<<" | "<<"Weight: "<<rootNode.weight<<endl;
                    visited[rootNode.parent]=1;
                    visited[rootNode.vertex]=1;
                    ttlweight+=rootNode.weight;
                }
            }
            cout<<"Total weight: "<<ttlweight;
        }

        void dijikstra(int src,int dest){
            vector <int> dist(n,INT_MAX);
            heap h2(n*n);
            node newnode;
            newnode.vertex=src;
            newnode.weight=0;
            dist[0]=0;

            h2.insert(newnode);

            while(h2.getCurr()!=0){
                node rootNode=h2.delete1();
                int rNvert=rootNode.vertex;

                for (int i=0;i<n;i++){
                    if (matrix[rNvert][i]!=0 && dist[rNvert]+matrix[rNvert][i]<dist[i]){
                        node newnode;
                        newnode.vertex=i;
                        newnode.weight=matrix[rNvert][i]+dist[rNvert];
                        h2.insert(newnode);
                        dist[i]=dist[rNvert]+matrix[rNvert][i];
                    }
                }
            }
            cout<<"\nDistance between all nodes from "<<src<<":"<<endl;
            cout<<"src - dest"<<endl;
            for (int i=0;i<n;i++){
                if (i==src){
                    continue;
                }
                cout<<"\n"<<src<<" - "<<dist[i]<<endl;
            }
            cout<<"\nDistance between "<<src<<" and "<<dest<<" is "<<dist[dest]<<endl;
            
        }

};

int main() {
    int choice, u, v, vertices, weight;
    int exitFlag = 0;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g1(vertices);

    while (!exitFlag) {
        cout << "\n==== Graph Menu ====\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Prim's Algorithm (MST)\n";
        cout << "4. Kruskal's Algorithm (MST)\n";
        cout << "5. Dijkstra's Algorithm (Shortest Path)\n";
        cout << "6. Display Adjacency Matrix\n";
        cout << "7. Exit\n";
        cout << "=====================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter (u v weight): ";
                cin >> u >> v >> weight;
                g1.insert(u, v, weight);
                break;

            case 2:
                cout << "Enter (u v): ";
                cin >> u >> v;
                g1.delete1(u, v);
                break;

            case 3:
                cout << "\nPrim's Algorithm Output:\n";
                g1.prims();
                break;

            case 4:
                cout << "\nKruskal's Algorithm Output:\n";
                g1.kruskals();
                break;

            case 5: {
                int src, dest;
                cout << "Enter source vertex: ";
                cin >> src;
                cout << "Enter destination vertex: ";
                cin >> dest;
                g1.dijikstra(src, dest);
                break;
            }

            case 6:
                g1.display();
                break;

            case 7:
                exitFlag = 1;
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
