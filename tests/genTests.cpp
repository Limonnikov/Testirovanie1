#include "genTests.h"

nlohmann::json creatTest1()
{
    nlohmann::json jsonObj;
    for(int i = 0; i < 10; ++i) {
        jsonObj.push_back((float)i);
    }
    jsonObj.push_back(5.f);
    jsonObj.push_back(5.f);
    return jsonObj;
}