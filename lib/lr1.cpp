#include "lr1.h"


vector <pair<pair<int, float>, int> > func(unordered_map<float, pair<int,int>>& array, int maxNum) {
    vector <pair<pair<int, float>, int> >  answ;

    for(const auto& pair : array)
    {
        if(pair.second.first == maxNum)
        {
            answ.push_back(make_pair(make_pair(pair.second.second, pair.first),pair.second.first));
        }
    }

    return answ;
}


bool openAndReadFile(string way, unordered_map<float, pair<int,int>>& freqMap, int& maxNum, vector <string>& catchErrors)
{
    ifstream file(way);
    if (!file) {
        catchErrors.push_back("Can not open file");
        return true;
    }

    json inputFile;
    file >> inputFile;
    file.close();
    float number;
    int i = 0;
    for (auto& [key, value] : inputFile.items()) {
        if (value.is_number()) {
            float floatValue = value.get<float>();
            if (floatValue <= numeric_limits<float>::max() && floatValue >= -numeric_limits<float>::max()) {
                number = roundf(floatValue*1000000)/1000000;
                //number = floatValue;
                freqMap[number].first++;
                if(freqMap[number].first == 1)
                    freqMap[number].second = i;
                if(freqMap[number].first > maxNum)
                    maxNum = freqMap[number].first;
                i++;
            } else {
                catchErrors.push_back("Value outside float range");
            }
        }
        else {
            catchErrors.push_back("Data is not a number");
        }
    }
    if(i > 1024){
        catchErrors.push_back("Array size is incorrect");
        return true;
    }


    return false;
}
