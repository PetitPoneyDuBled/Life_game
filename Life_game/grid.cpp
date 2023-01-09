#include "grid.hpp"

grid::grid(coordinate length,coordinate width){

    for(coordinate i=0;i<width;i++){
        vector<cellstate> v;
        for(coordinate j=0;j<length;j++){
            v.push_back(cellstate::dead);
        }
        _cellstate.push_back(v);
    }
}

void grid::empty(){

    for(coordinate i=0;i<_cellstate.size();i++){
        for(cellstate e: _cellstate.at(i)){
            if (e==cellstate::life){
                e=cellstate::dead;
            }
        }
    }
}

bool grid::life(coordinate l, coordinate h) const
{
    return _cellstate.at(h).at(l)==cellstate::life;
}

void grid::generate(coordinate l, coordinate h)
{
    _cellstate.at(h).at(l)=cellstate::life;
}

void grid::kill(coordinate l, coordinate h)
{
    _cellstate.at(h).at(l)=cellstate::dead;
}

void grid::show() const{
    for(coordinate i=0;i<_cellstate.size();i++){
        for(coordinate j=0;j<_cellstate.at(1).size();j++){
            if(life(j,i)) cout<<"*";
            else cout<<" ";
        }
        cout<< endl;
    }
}

void grid::addstructure(structure s, coordinate x,coordinate y){
    switch (s) {
        case structure::oscillatorline :
            generate(x,y);generate(x+1,y);generate(x+2,y);
            break;

        case structure::flower :
            addstructure(structure::oscillatorline,x+1,y);
            generate(x,y+1);generate(x+2,y+1);generate(x+4,y+1);
            addstructure(structure::oscillatorline,x+1,y+2);
            break;

        case structure::planes :
            addstructure(structure::oscillatorline,x,y);
            generate(x+2,y+1);
            generate(x+1,y+2);
            break;


        case structure::oscillatorcross :
            generate(x+1,y);
            addstructure(structure::oscillatorline,x,y+1);
            generate(x+1,y+2);
            break;
    }
}

unsigned int grid::inlife(coordinate x, coordinate y) const{
    unsigned int r(0);
    signed int sx(x),sy(y);

    for(signed int dx=-1;dx<=1;dx++){
        for(signed int dy=-1;dy<=1;dy++){
            if((dx==0)&&(dy==0)) continue;
            if(sx+dx<0) continue;
            if(sy+dy<0) continue;
            if(sx+dx>=length()) continue;
            if(sy+dy>=height()) continue;
            if(life(sx+dx,sy+dy)) r++;
        }
    }
    return r;
}

void grid::evolution(grid &result) const{
    for(coordinate y(0);y<height();y++){
        for(coordinate x(0);x<length();x++){
            auto nbviv=inlife(x,y);
            if(nbviv==3) result.generate(x,y);
            else if ((nbviv<=1) || (nbviv>=4)) result.kill(x,y);
            else if (life(x,y)) result.generate(x,y);
            else result.kill(x,y);
        }
    }
}


