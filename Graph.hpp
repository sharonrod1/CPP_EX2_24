
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <vector>
#include <unordered_set>
#include <string>
#include <utility>
using namespace std;
namespace ariel{
    class Graph{
        private:
        bool mekuvan ;
        std::vector<std::vector<int>> ourGraph;
        public:
        void loadGraph(std::vector<std::vector<int>> &v);
        string printGraph();
        bool isConnected();
        std::vector<std::vector<int>> getMatrix();
        std::vector<std::pair<size_t, size_t>>  getEdges() ;
        Graph operator+(Graph& g1  );
        Graph operator*(Graph& g1  );
        Graph operator/(Graph& g1  );
        Graph operator-(Graph& g1  );
        Graph operator+(  );
        Graph operator-(  );
        Graph& operator++(  );
        Graph& operator--(  );
        Graph& operator*(int n  );
        Graph& operator/(int n  );
        Graph& operator+=(Graph& g1 );
        Graph& operator-=(Graph& g1 );
        bool operator==(Graph& g1);
        bool operator!=(Graph& g1);
        bool operator>(Graph& g1);
        bool operator<(Graph& g1);
        bool operator>=(Graph& g1);
        bool operator<=(Graph& g1);
        bool isSubMatrix(Graph g1 , Graph g2);
        void setMatrix(std::vector<std::vector<int>> o);
    };
}
#endif
