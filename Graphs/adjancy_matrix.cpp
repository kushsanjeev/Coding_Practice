#include 
#include 
#include 

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

    void print_graph(){
         std::map<int, std::map<int, int> >::iterator i1;
        std::map<int, int>::iterator i2;
        for (i1 = graph.begin(); i1 != graph.end(); ++i1) {
            std::cout<first<<": ";
            for (i2 = i1->second.begin(); i2 != i1->second.end(); ++i12) {
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
