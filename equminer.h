#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sys/types.h>
#include <dirent.h>
using namespace std;
class Stdin
{
    int type;
    int min;
    int max;

public:
    Stdin(int t, int l, int r);
    int getType();
    int getMin();
    int getMax();
};
class Input
{
    string pdir;
    string name;

public:
    Input(string p, string n) : pdir(p), name(n) {}
    string getpdir() { return pdir; }
    string getName() { return name; }
    string path() { return pdir + "/" + name; }
};
class Equminer
{
    Input *f1;
    Input *f2;
    bool equal;
    vector<Stdin *> s;

public:
    Equminer(Input *i1, Input *i2, vector<Stdin*> &st);
    bool IsEqual();
    void randCase();
    void testEqual();
    string file1(){return f1->path();}
    string file2(){return f2->path();}
};

