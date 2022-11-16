#include"out.h"
#include<cstring>
#include<vector>
using namespace std;
string input_path;
vector<Input *> cppvec;
vector<Stdin *> stdvec;
vector<Equminer*>eqvec;
string folder;
string pdir;
void stdin_format()
{
    int t = 0, l = 1, r = 1;
    ifstream in(pdir + "/stdin_format.txt");
    if (!in)
    {
        cout << "Fail to open stdin_format.txt!" << endl;
    }
    else
    {
        char buffer[50];
        while (in >> buffer)
        {
            switch (buffer[0])
            {
            case 'i':
                t = 1;
                if (buffer[3] == '(')
                {
                    string min, max;
                    int i = 4;
                    for (; i < sizeof(buffer); ++i)
                    {
                        if (buffer[i] == ',')
                            break;
                        else
                            min += buffer[i];
                    }
                    i = i + 1;
                    for (; i < sizeof(buffer); ++i)
                    {
                        if (buffer[i] == ')')
                            break;
                        else
                            max += buffer[i];
                    }
                    l = stoi(min);
                    r = stoi(max);
                }
                else
                    cout << "Error in stdin_format.txt!" << endl;
                break;
            case 'c':
                t = 2;
                break;
            case 's':
                t = 2;
                if (buffer[6] == '(')
                {
                    string min, max;
                    int i = 7;
                    for (; i < sizeof(buffer); ++i)
                    {
                        if (buffer[i] == ',')
                            break;
                        else
                            min += buffer[i];
                    }
                    i = i + 1;
                    for (; i < sizeof(buffer); ++i)
                    {
                        if (buffer[i] == ')')
                            break;
                        else
                            max += buffer[i];
                    }
                    l = stoi(min);
                    r = stoi(max);
                }
                else
                    cout << "Error in stdin_format.txt!" << endl;
                break;
            default:
                cout << "Error in stdin_format.txt!" << endl;
                break;
            }
            if (l <= r)
            {
                Stdin *st = new Stdin(t, l, r);
                stdvec.push_back(st);
            }
            else
            {
                cout << "Error in stdin_format.txt!" << endl;
            }
        }
    }
    in.close();
}
void input()
{
    string name;
    DIR *curdir = opendir(pdir.c_str());
    if (curdir == NULL)
    {
        cout << "Fail to open current file directory!" << endl;
    }
    else
    {
        struct dirent *cpp;
        while ((cpp = readdir(curdir)) != NULL)
        {
            name = cpp->d_name;
            if (name.find(".cpp")!=string::npos)
            {
                Input *f = new Input(pdir, name);
                cppvec.push_back(f);
            }
        }
        closedir(curdir);
    }
}
int main()
{
    ofstream out_file_equal("equal.csv", ios::out);
    out_file_equal << "file1" << ',' << "file2" << endl;
    out_file_equal.close();
    ofstream out_file_inequal("inequal.csv", ios::out);
    out_file_inequal << "file1" << ',' << "file2" << endl;
    out_file_inequal.close();
    
    input_path = "/home/njucs/Desktop/input";
    DIR *input_Dir;
    if (!(input_Dir = opendir(input_path.c_str())))
        cout << "Folder doesn't Exist!" << endl;
    else
    {
        struct dirent *ptr;
        while ((ptr = readdir(input_Dir)) != NULL)
        {
            folder = ptr->d_name;
            if (folder != ".vscode" && folder != "." && folder != "..")
            {
                pdir = input_path + "/" + folder;
                stdin_format();
                input();
                for (int i = 0; i < cppvec.size() - 1; ++i)
                cout<<cppvec[i]->path()<<endl;
                for (int i = 0; i < cppvec.size() - 1; ++i)
                {
                    for (int j = i + 1; j < cppvec.size(); ++j)
                    {
                        Equminer *eq=new Equminer(cppvec[i],cppvec[j],stdvec);
                        for(int i=0;i<10;++i)
                        {
                            eq->randCase();
                            eq->testEqual();
                        }
                        eqvec.push_back(eq);
                    }
                }

                cppvec.clear();
                stdvec.clear();
            }
        }
        closedir(input_Dir);
    }
    Output*out=new Output(eqvec);
    out->OutFile();
    return 0;
}