/*
    Program to check if graph is connected using depth search
    Functions:
        print_graph(bool **graph, int N) - receive connectivity matrix with size N and display it
        print_result(bool *visited, int N) - receive array of visited vertices and shows if graph is connected
        filling_graph(bool **graph, int N) - gives opportunity to fill connectivity matrix(to create graph)
        is_connected(bool **graph, int N) - check if graph is connected
        find_connected(bool **graph, int N, int depth, bool *visited) - recursively fills the visited array with connected vertices
*/

#include <iostream>

using namespace std;

//Declaration
void print_graph(bool **graph, int N);
void print_result(bool *visited, int N);
void filling_graph(bool **graph, int N);
bool is_connected(bool **graph, int N);
void find_connected(bool **graph, int N, int depth, bool *visited);

int main()
{
    int N;
    cout << "Input amount of peeks:\n";
    cin >> N;

    //Creating matrix for graph
    bool **graph = new bool* [N];
    for (int i = 0; i < N; i++) {
        graph[i] = new bool[N];
    }

    filling_graph(graph, N);
    is_connected(graph,N);
}


//Implementation
bool is_connected(bool **graph, int N) {
    bool *visited = new bool[N];

    visited[0] = true;
    for (int i = 1; i < N; i++) {
        visited[i] = false;
    }

    find_connected(graph, N, 0, visited);
    print_result(visited, N);
}
void find_connected(bool **graph, int N, int depth, bool *visited) {
    for (int i = 0; i < N ; i++) {
        //If the vertex wasn't visited
        if (graph[depth][i] && !visited[i]) {
            visited[i] = true;
            //because graph two vertices connected by one line
            graph[depth][i] = false;
            graph[i][depth] = false;
            connection_successeful(graph, N, i, visited);
        }
    }
}
void filling_graph(bool **graph, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
                graph[i][j] = false;
        }
    }

    while (true) {
        string enough;
        cout << "Stop? y/n  \n";
        cin >> enough;
        if (enough == "y") {
            break;
        }

        int a, b;
        cout << "\nInput 2 vertices(numbers from 0 to " << (N - 1) << "):" << endl;
        cin >> a >> b;
        if (a != b) {
            graph[a][b] = true;
            graph[b][a] = true;
        }
        cout << endl;
        print_graph(graph, N);
    }
}
void print_graph(bool **graph, int N) {
    cout << "Your graph:\n    ";

    for (int i = 0; i < N; i++) {
        cout << i << " ";
    }
    cout << "\n    ";

    for (int i = 0; i < N; i++) {
        cout << "_" << " ";
    }

    cout << endl;

    for (int i = 0; i < N; i++) {
        cout << i << "  |";
        for (int j = 0; j < N; j++) {
            if (graph[i][j]) {
                    cout << "1";
            } else {
                cout << "0";
            }
            cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void print_result(bool *visited, int N) {
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cout << "Graph is not connected!\n";
        }
    }

    cout << "Graph is connected!\n";
}
