#include<iostream.h>
#include<string.h> 
#include<template.h> 

class Graph {
private:
    std::map<int, std::map<int, int> > graph;
public:
    void addEdge(int u, int v, int weight = 1, int isDirected = true) {
        std::map<int, std::map<int, int> >::iterator it;
        it = graph.find(u);
        if (it == graph.end()) {
            std::map<int, int> edge_map;
            edge_map[v] = weight;
            graph[u] = edge_map;

        } else {
            graph[u][v] = weight;
        }

        if (!isDirected) {
            it = graph.find(v);
            if (it == graph.end()) {
                std::map<int, int> edge_map;
                edge_map[u] = weight;
                graph[v] = edge_map;

            } else {
                graph[v][u] = weight;
            }
        }
    }

    void printGraph() {
        std::map<int, std::map<int, int> >::iterator it;
        std::map<int, int>::iterator it2;
        for (it = graph.begin(); it != graph.end(); ++it) {
            std::cout<first<<": ";
            for (it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                std::cout<<"("<first<<","<second<<")";
                std::cout<<"   ";
            }
            std::cout<<std::endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge(1, 2, 7, false);
    g.addEdge(1, 3, 2, false);
    g.addEdge(2, 3, 1, false);
    g.addEdge(2, 4, 5, false);
    g.addEdge(2, 5, 3, false);
    g.addEdge(3, 5, 11, false);
    g.addEdge(4, 5, 10, false);
    g.addEdge(4, 6, 7, false);
    g.addEdge(5, 6, 4, false);
    g.printGraph();
    return 0;
}
