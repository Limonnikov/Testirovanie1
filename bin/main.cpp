#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
#include <unordered_map>
#include <lib/lr1.h>
using namespace std;

int main() {

    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "input.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);

    if (close) {
        for(int i = 0; i < catchErrors.size(); ++i)
        {
            cout << endl << "[ERROR " << i+1 << "] " << " " << catchErrors[i];
        }
        return 0;
    }

    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);

    for(int i = answer.size()-1; i >= 0; --i)
    {
        cout << answer[i].first.first << "      " << setprecision(6) << fixed << answer[i].first.second << "     " << answer[i].second <<  endl;
    }

    for(int i = 0; i < catchErrors.size(); ++i)
    {
        cout << endl << "[ERROR " << i+1 << "] " << " " << catchErrors[i];
    }
    return 0;
}