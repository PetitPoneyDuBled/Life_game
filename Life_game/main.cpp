#include "grid.hpp"
#include "iostream"
#include "vector"

int main(){

std::vector<grid> grids(2,grid(20,20));


grids[0].addstructure(structure::planes,2,5);
grids[0].show();

unsigned int now=0;

while(true){
    std::string s;
    std::getline(std::cin,s);
    grids[now].evolution(grids[1-now]);
    now=1-now;
    grids[now].show();
}

return 0;

}
