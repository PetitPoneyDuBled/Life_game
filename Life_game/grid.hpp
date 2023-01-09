#ifndef EX5_HH
#define EX5_HH

#endif // EX5_HH

#include <iostream>
#include <vector>

using namespace std;

using coordinate = unsigned short;
enum class cellstate {life,dead};
enum class structure {oscillatorline,flower,planes,oscillatorcross};

class grid{
public:
    grid(coordinate length,coordinate width);
    void empty();
    bool life(coordinate l,coordinate h) const;
    void generate(coordinate l,coordinate h);
    void kill(coordinate l,coordinate h);
    void show() const;
    void addstructure(structure s, coordinate x,coordinate y);
    unsigned int inlife(coordinate x,coordinate y) const;
    void evolution(grid & result) const;
    int height() const{ return _cellstate.size();}
    int length() const{ return _cellstate.at(1).size();}

private:
    vector<vector<cellstate>> _cellstate;
};
