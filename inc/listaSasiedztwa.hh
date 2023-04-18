#ifndef LISTASASIEDZTWA_HH
#define LISTASASIEDZTWA_HH

#include <iostream>
#include <vector>

using namespace std;

// struktura reprezentująca graf jako listę sąsiedztwa
struct Graph {
    int V;  // liczba wierzchołków
    vector<vector<int> > adj;  // lista sąsiedztwa

    // konstruktor
    Graph(int V) {
        this->V = V;
        adj.resize(V);  // inicjalizacja listy sąsiedztwa dla każdego wierzchołka
    }

    // funkcja dodająca krawędź między wierzchołkami u i v
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // dodajemy krawędź także w drugą stronę dla grafów nieskierowanych
    }

    // funkcja do wypisywania grafu
    void printGraph() {
        for(int i = 0; i < V; i++) {
            cout << "Wierzcholek " << i << ": ";
            for(int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif