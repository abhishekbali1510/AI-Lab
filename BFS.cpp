#include <bits/stdc++.h>
using namespace std;

queue<int> que;

void BFS(int **adjMatrix, int *isVisited, map<char, int> allNodesMap, int numOfNodes)
{
    while (!que.empty())
    {
        int curNode = que.front();
        que.pop();
        for (auto it : allNodesMap)
            if (curNode == it.second)
                cout << it.first << " ";
        isVisited[curNode] = 1;
        for (int i = 0; i < numOfNodes; i++)
        {
            if (adjMatrix[curNode][i] == 1 && isVisited[i] == 0)
            {
                que.push(i);
            }
        }
    }
}
int main()
{

    // Input Block Start
    int numOfNodes = 0, numOfEdges = 0;

    while (true)
    {
        cout << "Enter Number of Nodes : ";
        cin >> numOfNodes;
        if (!cin)
        {
            cout << "Wrong Input. Enter an Integer \n";
            cin.clear();                                         // Removes error flag form cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards previous values
            continue;
        }
        else
            break;
    }

    while (true)
    {
        cout << "Enter Number of Edges : ";
        cin >> numOfEdges;
        if (!cin)
        {
            cout << "Wrong Input, Enter an Integer \n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else
            break;
    }

    map<char, int> allNodesMap;

    for (int node = 0; node < numOfNodes; node++)
    {
        cout << "Enter value of node number " << node + 1 << " : ";
        char value;
        cin >> value;
        allNodesMap[value] = node;
    }

    // creating a dynamic 2d matrix
    int **adjMatrix = new int *[numOfNodes];
    for (int i = 0; i < numOfNodes; i++)
        adjMatrix[i] = new int[numOfNodes];

    for (int edge = 0; edge < numOfEdges; edge++)
    {
        char vertex1, vertex2;
        cout << "Enter Edge " << edge + 1 << " \n";
        cout << "Vertex 1 : ";
        cin >> vertex1;
        cout << "Vertex 2 : ";
        cin >> vertex2;
        adjMatrix[allNodesMap[vertex1]][allNodesMap[vertex2]] = 1;
        adjMatrix[allNodesMap[vertex2]][allNodesMap[vertex1]] = 1;
    }
    // Input Block End

    int isVisited[numOfNodes] = {0};
    for (int node = 0; node < numOfNodes; node++)
    {
        if (isVisited[node] == 0)
        {
            que.push(node);
            BFS(adjMatrix, isVisited, allNodesMap, numOfNodes);
        }
        cout << "    ";
    }
    cout << endl;
}