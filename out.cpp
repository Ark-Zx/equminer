#include "out.h"
void Output::OutFile()
{
    ofstream out1("equal.csv", ios::app);
    ofstream out2("inequal.csv", ios::app);
    for (int i = 0; i < eqvec.size(); ++i)
    {
        if (eqvec[i]->IsEqual())

            out1 << eqvec[i]->file1().erase(0,len) << "," << eqvec[i]->file2().erase(0,len) << endl;
        else

            out2 << eqvec[i]->file1().erase(0,len) << "," << eqvec[i]->file2().erase(0,len) << endl;
    }
    out1.close();
    out2.close();
}