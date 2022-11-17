#include "equminer.h"
class Output
{
    vector<Equminer *> eqvec;
    int len;

public:
    Output(vector<Equminer *> &e, int l) : eqvec(e), len(l) {}
    void OutFile();
};
