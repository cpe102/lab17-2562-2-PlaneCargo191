#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

void findGrade(double x, string &y)
{
    if(x>=80) y = "A";
    else if(x>=70) y = "B";
    else if(x>=60) y = "C";
    else if(x>=50) y = "D";
    else y = "F";
}

string upper(string z)
{
    for(int i=0; i<z.size(); i++) z[i] = toupper(z[i]);
    return z;
}

int main()
{
    vector<string> name, score;
    ifstream text("name_score.txt");
    string line;
    int s1, s2, s3;
    char n[100];
    string grade;

    while(getline(text,line))
    {
        sscanf(line.c_str(), "%[^:]: %d %d %d", n, &s1, &s2, &s3);
        name.push_back(n);
        double t = s1+s2+s3;
        findGrade(t,grade);
        score.push_back(grade);
    }

    while(true)
    {
        cout << "Please input your command: ";
        getline(cin,line);
        int space = line.find_first_of(" ");
        string l1 = upper(line.substr(0,space));
        string l2 = upper(line.substr(space+1,line.size()));
        bool v;
        if(l1 == "NAME")
        {
            v=1;
            for(int i=0; i<name.size(); i++)
            {
                if(l2 == upper(name[i]))
                {
                    cout << "---------------------------------\n";
                    cout << name[i] << "'s grade = " << score[i] << endl;
                    cout << "---------------------------------\n";
                    v = 0;
                }
            }
            
            if(v != 0)
            {
                cout << "---------------------------------\n" << "Cannot found.\n" << "---------------------------------\n";
            }
        }
        else if(l1 == "GRADE")
        {
            v=1;
            cout << "---------------------------------\n";
            for(int i=0; i<score.size(); i++)
            {
                if(l2 == upper(score[i]))
                {
                    cout << name[i] << endl;
                    v=0;
                }
            }
            
             if(v != 0)
            {
                cout << "Cannot found.\n";
            }
            cout << "---------------------------------\n";
        }
        else if(l1 == "EXIT")
        {
            break;
        }
        else
        {
            cout << "Invalid command\n";
        }
        
    }
}