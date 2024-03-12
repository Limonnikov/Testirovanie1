#include "lr1.h"


vector <pair<pair<int, float>, int> > func(vector<float>& arr) {
    vector <pair<pair<int, float>, int> >  answ;

    unordered_map<float, int> freqMap;
    int mostFrequent = arr[0];


    for(int i = 0; i < arr.size(); ++i)
    {
        freqMap[arr[i]]++;
        if(freqMap[arr[i]] > freqMap[mostFrequent])
            mostFrequent = arr[i];

    }

    for(int i = 0; i < arr.size(); ++i)
    {
        if(freqMap[arr[i]] == freqMap[mostFrequent])
        {
            answ.push_back(make_pair(make_pair(i, arr[i]),freqMap[mostFrequent]));
        }
    }

    sort(answ.begin(), answ.end());
    return answ;
}