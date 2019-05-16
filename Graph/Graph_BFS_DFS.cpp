#include <iostream>
#include <list>
#include <queue>
#include <stack>

using namespace std;

class Graph
{
    private:
        int V;
        list<int> *E;

    public:
        Graph(int V)
        {
            this -> V = V;
            E = new list<int>[V];
        }
        void addEdge(int src, int dest);
        void BFS(int s);
        void DFS(int s);
};

void Graph::addEdge(int src, int dest)
{
    E[src].push_back(dest);
    E[dest].push_back(src);
    
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    
    for(int i=0; i < V; i++)
    {
        visited[i] = false;
    }
    
    queue<int> q;
    
    visited[s] = true;
    q.push(s);
    while(q.empty() == false)
    {
        int temp = q.front();
        cout << temp << " ";
        q.pop();
        
        for(auto &i:E[temp])
        {
            if(visited[i] == false)
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void Graph::DFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    
    stack<int> st;
    visited[s] = true;
    st.push(s);
    
    while(st.empty() == false)
    {
        int temp = st.top();
        cout << temp << " ";
        st.pop();
        
        for(auto &i:E[temp])
        {
            if(visited[i] == false)
            {
                visited[i] = true;
                st.push(i);
            }
        }
    } 
}

int main()
{
    int n = 5;
    Graph *node = new Graph(n);
    node->addEdge(0, 1);
    node->addEdge(0, 3);
    node->addEdge(0, 4);
    node->addEdge(1, 2);
    node->addEdge(2, 3);
    node->addEdge(3, 4);
    cout << "BFS    : ";
    node->BFS(0);
    cout << "\nDFS    : ";
    node->DFS(0);
        
    return 0;
}
