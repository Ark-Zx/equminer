#include "equminer.h"
class Output
{
    vector<Equminer *> eqvec;

public:
Output(vector<Equminer*>&e):eqvec(e){}
void OutFile();
};