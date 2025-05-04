#include<iostream>
#include<vector>
using namespace std;

class graph
{
private:
    int numVertices;
    vector<vector<int>> adjMatrix;
public:
    graph(int vertices ){
        numVertices = vertices;
        adjMatrix.resize(vertices,vector<int>(vertices,0));
    };
    bool isValid(int);
    void insertEdge(int,int);
    void deleteEdge(int,int);
    void searchEdge(int,int);
    void display();
};



int main(){
    int num;
    cout<<"Enter The Number of Vetices : ";
    cin>>num;
    graph g(num);
    int u, v;
    int choice;

    while (true) {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.insertEdge(u, v);
                break;
            case 2:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.deleteEdge(u, v);
                break;
            case 3:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.searchEdge(u, v);
                break;
            case 4:
                g.display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again!\n";
        }
    }
    return 0;
}

bool graph::isValid(int v){
    return (v>=0 && v<numVertices);
}
void graph::insertEdge(int u,int v){
    if(isValid(u) && isValid(v)){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        cout<<"Edge Inserted between("<<u<<","<<v<<") and ("<<v<<","<<u<<")"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }
}
void graph::deleteEdge(int u,int v){
    if(isValid(u) && isValid(v)){
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
        cout<<"Edge Deleted between("<<u<<","<<v<<") and ("<<v<<","<<u<<")"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }
}
void graph::searchEdge(int u,int v){
    if (isValid(u) && isValid(v))
    {
        if(adjMatrix[u][v] == 1){
            cout<<"Vertex is present at position ("<<u<<","<<v<<")"<<endl;
        }
        else{
            cout<<"Vertex is NOT present at position ("<<u<<","<<v<<")"<<endl;
        }
    }
    else{
        cout<<"Invalid Index"<<endl;
    }
}

void graph::display(){
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}