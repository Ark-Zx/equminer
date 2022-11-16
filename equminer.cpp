#include "equminer.h"
Stdin::Stdin(int t, int l, int r) : type(t), min(l), max(r) {}
int Stdin::getType() { return type; }
int Stdin::getMin() { return min; }
int Stdin::getMax() { return max; }
Equminer::Equminer(Input *i1, Input *i2, vector<Stdin *> &st) : f1(i1), f2(i2), s(st) {}
bool Equminer::IsEqual() { return equal; }
void Equminer::randCase()
{
    int a, b;
    int randnum;
    char letter;
    string res;
    ofstream out(f1->getpdir() + "/inputcase.txt");
    for (int i = 0; i < s.size(); ++i)
    {
        a = s[i]->getMin();
        b = s[i]->getMax();
        randnum = (rand() % (b - a + 1)) + a;
        switch (s[i]->getType())
        {
        case 1:
            res = to_string(randnum);
            break;
        case 2:
            res = "";
            for (int j = 0; j < randnum; ++j)
            {
                letter = rand() % 26 + 65;
                if (rand() % 2)
                {
                    letter += 32;
                }
                res += letter;
            }
            break;
        default:
            res = "";
            cout << "error" << endl;
            break;
        }
        out << res << " ";
    }
    out << endl;
    out.close();
}
void Equminer::testEqual()
{
    char cp1[1000] = "g++ -w -o a.out ";
    strcat(cp1, f1->path().c_str());
    char cp2[1000] = "g++ -w -o b.out ";
    strcat(cp2, f2->path().c_str());
    system(cp1);
    system(cp2);

    string inputfile_path = f1->getpdir() + "/inputcase.txt";
    string outputfile_path1 = f1->getpdir() + "/out1.txt";
    string outputfile_path2 = f2->getpdir() + "/out2.txt";

    char runner1[1001] = "./a.out <";
    strcat(runner1, inputfile_path.c_str());
    strcat(runner1, "> ");
    strcat(runner1, outputfile_path1.c_str());
    int r1 = system(runner1);

    char runner2[1001] = "./b.out <";
    strcat(runner2, inputfile_path.c_str());
    strcat(runner2, "> ");
    strcat(runner2, outputfile_path2.c_str());
    int r2 = system(runner2);
    if (r1 != 0 || r2 != 0)
    {
        equal = 0;
        return;
    }
    else
    {
        vector<string> res1, res2;
        string r;
        ifstream in1(f1->getpdir() + "/out1.txt");
        if (!in1)
        {
            cout << "Fail to open out1.txt!" << endl;
        }
        else
        {
            while (in1 >> r)
            {
                res1.push_back(r);
            }
        }
        in1.close();
        ifstream in2(f2->getpdir() + "/out2.txt");
        if (!in2)
        {
            cout << "Fail to open out2.txt!" << endl;
        }
        else
        {
            while (in2 >> r)
            {
                res2.push_back(r);
            }
        }
        in2.close();
        if (res1 == res2)
            equal = 1;
        else
            equal = 0;
    }
}

