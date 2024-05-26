#include "Graph.hpp"
#include <iostream>
using namespace ariel;
using namespace std;
#include <unordered_set>

void Graph :: loadGraph(std::vector<std::vector<int>> v){

    if (v.empty()){
        std :: __throw_invalid_argument("matrx is enpty ");
    }
    if ( v.size() != v[0].size()){
        std :: __throw_invalid_argument("matrix is not a square");
    }
    this->ourGraph=v;
    this->mekuvan=(bool) isConnected();

}
string Graph :: printGraph(){
    string h;
    for(size_t i=0;i<this->ourGraph.size();i++){
        for (size_t j=0;j<this->ourGraph[0].size();j++){
            if(j==0){
                h+="["+ to_string( this->ourGraph[i][j]);
                
            }
            
            else {
             h+=", "+ to_string( this->ourGraph[i][j]);}
            if (j==this->ourGraph[0].size()-1){
                h+="]";
            }
        }
        if(i!=this->ourGraph.size()-1){
        h+=",";}
    }
    return h ;
    
}

bool Graph :: isConnected (){
    for(size_t i=0;i<this->ourGraph.size();i++){
        for (size_t j=0;j<this->ourGraph[0].size();j++){
            if(this->ourGraph[i][j] != this->ourGraph[j][i]){
                return false;
            }
        }
    }
    return true;
}
std::vector<std::vector<int>> Graph :: getMatrix(){
    return this->ourGraph;
}
std::vector<std::pair<size_t, size_t>> Graph :: getEdges()  {
            std::vector<std::pair<size_t, size_t>> edges;
            size_t numVertices = this->ourGraph.size();
            for (size_t i = 0; i < numVertices; ++i) {
                for (size_t j = 0; j < numVertices; ++j) {
                    if (this->ourGraph[i][j] != 0) {
                        edges.push_back({i, j});
                    }
                }
            }
            return edges;
        }
    Graph Graph::operator+(Graph& g1 ){// adding two matrices
     if(this->ourGraph.size() != g1.getMatrix().size() || this->ourGraph[0].size() != g1.getMatrix()[0].size()){
        std :: __throw_invalid_argument("matrices are not the same size");}
    size_t v =g1.getMatrix().size();
    std::vector<std::vector<int>> ourGraph;
    for(size_t b=0 ; b<v ; b++){
        vector<int> temp;
        for (size_t k=0 ;k<v; k++){
            temp.push_back(g1.getMatrix()[b][k]+ this->ourGraph[b][k]);
        }

        ourGraph.push_back(temp);
    }
    ariel::Graph g4;
    g4.loadGraph(ourGraph);
    return g4;
    }


void Graph :: setMatrix(std::vector<std::vector<int>> o){
    this->ourGraph=o;
}
Graph Graph::operator*( Graph& g1 ) {// multiplying two matrices
    if(this->ourGraph.size() != g1.getMatrix().size() || this->ourGraph[0].size() != g1.getMatrix()[0].size()){
        std :: __throw_invalid_argument("matrices are not the same size");}
    
    size_t v =g1.getMatrix().size();
    std::vector<std::vector<int>> ourGraph;
    for(size_t b=0 ; b<v ; b++){
        vector<int> temp;
        for (size_t k=0 ;k<v; k++){
            temp.push_back(this->ourGraph[b][k]*g1.getMatrix()[b][k]);
        }

        ourGraph.push_back(temp);
    }
    ariel::Graph g4;
    g4.loadGraph(ourGraph);
    return g4;
}
Graph Graph::operator/(Graph& g1 ){// dividing two matrices
    if(this->ourGraph.size() != g1.getMatrix().size() || this->ourGraph[0].size() != g1.getMatrix()[0].size()){
        std :: __throw_invalid_argument("matrices are not the same size");}
    size_t v =g1.getMatrix().size();
    std::vector<std::vector<int>> ourGraph;
    for(size_t b=0 ; b<v ; b++){
        vector<int> temp;
        for (size_t k=0 ;k<v; k++){
            temp.push_back(this->ourGraph[b][k]/g1.getMatrix()[b][k]);
        }

        ourGraph.push_back(temp);
    }
    ariel::Graph g4;
    g4.loadGraph(ourGraph);
    return g4;
}
Graph Graph::operator-(Graph& g1 ){// subtracting two matrices
    if(this->ourGraph.size() != g1.getMatrix().size() || this->ourGraph[0].size() != g1.getMatrix()[0].size()){
        std :: __throw_invalid_argument("matrices are not the same size");}
    size_t v =g1.getMatrix().size();
    std::vector<std::vector<int>> ourGraph;
    for(size_t b=0 ; b<v ; b++){
        vector<int> temp;
        for (size_t k=0 ;k<v; k++){
            temp.push_back(this->ourGraph[b][k]-g1.getMatrix()[b][k]);
        }

        ourGraph.push_back(temp);
    }
    ariel::Graph g4;
    g4.loadGraph(ourGraph);
    return g4;
}
Graph Graph ::operator+(){//onori
    return *this;
}
Graph& Graph ::operator++(){
    for(size_t i=0;i<this->ourGraph.size();i++){
        for (size_t j=0;j<this->ourGraph[0].size();j++){
            this->ourGraph[i][j]++;
        }
    }
    return *this;
}
Graph& Graph ::operator--(){
    for(size_t i=0;i<this->ourGraph.size();i++){
        for (size_t j=0;j<this->ourGraph[0].size();j++){
            this->ourGraph[i][j]--;
        }
    }
    return *this;
}
Graph& Graph ::operator*(int n){
    for(size_t i=0;i<this->ourGraph.size();i++){
        for (size_t j=0;j<this->ourGraph[0].size();j++){
            this->ourGraph[i][j]*=n;
        }
    }
    return *this;
}
Graph& Graph ::operator/(int n){
    for(size_t i=0;i<this->ourGraph.size();i++){
        for (size_t j=0;j<this->ourGraph[0].size();j++){
            this->ourGraph[i][j]/=n;
        }
    }
    return *this;
}
Graph& Graph ::operator+=(Graph& g1){
    if(this->ourGraph.size() != g1.getMatrix().size() || this->ourGraph[0].size() != g1.getMatrix()[0].size()){
        std :: __throw_invalid_argument("matrices are not the same size");}
    size_t v =g1.getMatrix().size();
    std::vector<std::vector<int>> ourGraph;
    for(size_t b=0 ; b<v ; b++){
        vector<int> temp;
        for (size_t k=0 ;k<v; k++){
            temp.push_back(g1.getMatrix()[b][k]+this->ourGraph[b][k]);
        }

        ourGraph.push_back(temp);
    }
    this->loadGraph(ourGraph);
    return *this;
}
Graph& Graph ::operator-=(Graph& g1){
    if(this->ourGraph.size() != g1.getMatrix().size() || this->ourGraph[0].size() != g1.getMatrix()[0].size()){
        std :: __throw_invalid_argument("matrices are not the same size");}
    size_t v =g1.getMatrix().size();
    std::vector<std::vector<int>> ourGraph;
    for(size_t b=0 ; b<v ; b++){
        vector<int> temp;
        for (size_t k=0 ;k<v; k++){
            temp.push_back(this->ourGraph[b][k]-g1.getMatrix()[b][k]);
        }

        ourGraph.push_back(temp);
    }
    this->loadGraph(ourGraph);
    return *this;
}
bool Graph ::operator==(Graph& g1){// checking if two matrices are the same
    if(this->ourGraph.size() != g1.getMatrix().size() || this->ourGraph[0].size() != g1.getMatrix()[0].size()){
        return false;}
    size_t v =g1.getMatrix().size();
    for(size_t b=0 ; b<v ; b++){
        for (size_t k=0 ;k<v; k++){
            if(g1.getMatrix()[b][k]!=this->ourGraph[b][k]){
                return false;
            }
        }
    }
    return true;
}
bool Graph ::operator!=(Graph& g1){
    if(this->ourGraph.size() != g1.getMatrix().size() || this->ourGraph[0].size() != g1.getMatrix()[0].size()){
        return true;}
    size_t v =g1.getMatrix().size();
    for(size_t b=0 ; b<v ; b++){
        for (size_t k=0 ;k<v; k++){
            if(g1.getMatrix()[b][k]!=this->ourGraph[b][k]){
                return true;
            }
        }
    }
    return false;
}
bool Graph :: isSubMatrix(Graph g1 , Graph g2){// checking if g1 is a submatrix of g2 or the ooposite
    size_t v =g1.getMatrix().size();
    size_t v2 =g2.getMatrix().size();
    size_t min1=0;
    size_t max1=0;
    bool answer=false;
    if(v2>v){
         min1=v;
         max1=v2;
    }
    else{
        min1=v2;
        max1=v;
    }
    size_t until = max1-min1 ;
    for(size_t o=0;o<until+1;o++){// runnning on the matrix and checking if the submatrix is the same using 2 loops
        for(size_t x =0; x< until+1 ;x++){
            answer=true;
            for(size_t b=0 ; b<min1 ; b++){// here is the comparation
                for (size_t k=0 ;k<min1; k++){
                    if(v2<v){
                    if(g1.getMatrix()[b+o][k+x]!=g2.getMatrix()[b][k]){
                        answer = false;
                        k=min1;
                    }
                    }
                    else{
                        
                        if(g2.getMatrix()[b+o][k+x] !=g1.getMatrix()[b][k]){
                        answer = false;
                        k=min1;
                    }
                    }
                    
                }
            }
            if(answer){
            return true;
        }
        }
        
    }
    return answer;
}
bool Graph ::operator>(Graph& g1){//cheking which matrix is bigger based on your rules
    bool answer=true;
    Graph g0=*this;
    int sum1=0;
    int sum0=0;
    if(isSubMatrix(g0,g1)){
        if(g1.getMatrix().size()>g0.getMatrix().size()){
            return false;
        }
        return true;
    }
    if(g1.getMatrix().size() != g0.getMatrix().size() || g1.getMatrix()[0].size() != g0.getMatrix()[0].size()){// checking if the matrices are the same size
        answer = false;}
    if(answer){   
    for (size_t i=0;i<g1.getMatrix().size();i++){
        for(size_t j=0;j<g1.getMatrix()[0].size();j++){
            sum1+=g1.getMatrix()[i][j];
            sum0+=g0.getMatrix()[i][j];
            if(g1.getMatrix()[i][j]!=g0.getMatrix()[i][j]){
                answer = false;
            }
            
        }
    }
    if(answer){// it means that they are the same matrix
        return false;
    }
    if(sum1>sum0){
        return false;
    }
    else{
        return true;
    }
    }
    //if im here it means that the matrices are not the same size
    for (size_t i=0;i<g1.getMatrix().size();i++){
        for(size_t j=0;j<g1.getMatrix()[0].size();j++){
            sum1+=g1.getMatrix()[i][j];
        }
    }
    for (size_t i=0;i<g0.getMatrix().size();i++){
        for(size_t j=0;j<g0.getMatrix()[0].size();j++){
            sum0+=g0.getMatrix()[i][j];
        }
    }
    if(sum1>sum0){// checking the sum of the elements in the matrix again
        return false;
    }
    else{
        return true;
    }
    if(g1.getMatrix().size()>g0.getMatrix().size()){// the last term 
        return false;
    }
    return true;
}
bool Graph::operator<(Graph& g1){
    bool ans = g1>*this;
    return ans;
}
bool Graph::operator>=(Graph& g1){// combiiing the two functions above
    bool ans = g1<*this;
    bool ans2 = g1==*this;
    return ans || ans2;
}
bool Graph::operator<=(Graph& g1){
    bool ans = g1>*this;
    bool ans2 = g1==*this;
    return ans || ans2;
}
Graph Graph::operator-( ){// minus onori
    Graph g0=*this;
    return g0*(-1);
}




