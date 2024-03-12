#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <lib/lr1.h>
using namespace std;

int main() {

    vector <pair <int, string> > catchErrors;

    ifstream file("input.txt");
    if (!file) {

        catchErrors.push_back(make_pair(1, "Can not open file"));
        for(int i = 0; i < catchErrors.size(); ++i)
        {
            cerr << endl << catchErrors[i].first << " " << catchErrors[i].second;
        }
        return 0;
    }

    vector<float> arr;
    float number;

    while (file >> number || !file.eof()) {
        if (file.fail()) {
            file.clear();
            file.ignore();

            catchErrors.push_back(make_pair(2, "Wrong data"));
        }
        else {
            arr.push_back(number);
        }
    }

    file.close();

    if(arr.size() < 1 || arr.size() > 1024)
    {
        catchErrors.push_back(make_pair(3, "Array size is incorrect"));
        for(int i = 0; i < catchErrors.size(); ++i)
        {
            cerr << endl << catchErrors[i].first << " " << catchErrors[i].second;
        }
        return 0;
    }

    vector <pair<pair<int, float>, int> >   answer = func(arr);
    cout << answer[0].first.first << "      " << answer[0].first.second << "     " << answer[0].second <<  endl;
    for(int i = 1; i < answer.size(); i++)
    {
        if(answer[i-1].first.second != answer[i].first.second)
            cout << answer[i].first.first << "      " << answer[i].first.second << "     " << answer[i].second <<  endl;
    }

    for(int i = 0; i < catchErrors.size(); ++i)
    {
        cerr << endl << catchErrors[i].first << " " << catchErrors[i].second;
    }
    return 0;
}