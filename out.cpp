#include "out.h"
void Output::OutFile()
{
    ofstream out1("equal.csv", ios::app);
    ofstream out2("inequal/csv", ios::app);
    for (int i = 0; i < eqvec.size(); ++i)
    {
        if (eqvec[i]->IsEqual())

            out1 << eqvec[i]->file1() << "," << eqvec[i]->file2() << endl;
        else

            out2 << eqvec[i]->file1() << "," << eqvec[i]->file2() << endl;
    }
    out1.close();
    out2.close();
}