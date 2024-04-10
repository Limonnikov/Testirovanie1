#include <lib/lr1.h>
#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include <fstream>

// Подробнее https://google.github.io/googletest/reference/testing.html



// Тестовый класс
class myTests : public ::testing::Test {
protected:
    void SetUp() override {

    }
    void TearDown() override {

    }
};



// Тест 1: файл отсутствует
TEST(myTests, CTest1) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test1.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Can not open file");
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 2:
TEST(myTests, CTest2) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test2.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer;
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;

    vector <pair<pair<int, float>, int> >   testingAnswer;

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 3:
TEST(myTests, CTest3) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test3.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer;
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Data is not a number");
    testingCatchErrors.push_back("Data is not a number");

    vector <pair<pair<int, float>, int> >   testingAnswer;

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 4:
TEST(myTests, CTest4_1) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test4_1.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer;
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Value outside float range");
    testingCatchErrors.push_back("Value outside float range");
    testingCatchErrors.push_back("Value outside float range");

    vector <pair<pair<int, float>, int> >   testingAnswer;

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 5:
TEST(myTests, CTest4_2) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test4_2.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer;
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Value outside float range");
    testingCatchErrors.push_back("Value outside float range");
    testingCatchErrors.push_back("Value outside float range");

    testingCatchErrors.push_back("Data is not a number");
    testingCatchErrors.push_back("Data is not a number");
    vector <pair<pair<int, float>, int> >   testingAnswer;

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 6:
TEST(myTests, CTest5_1) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test5_1.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer;
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Array size is incorrect");

    vector <pair<pair<int, float>, int> >   testingAnswer;

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}
// Тест 7:
TEST(myTests, CTest5_2) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test5_2.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer;
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Data is not a number");
    testingCatchErrors.push_back("Array size is incorrect");

    vector <pair<pair<int, float>, int> >   testingAnswer;

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}
// Тест 8:
TEST(myTests, CTest6_1) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test6_1.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test6_1_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], roundf(value[1].get<float>()*1000000)/1000000), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 9:
TEST(myTests, CTest6_2) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test6_2.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Data is not a number");
    testingCatchErrors.push_back("Data is not a number");

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test6_2_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], roundf(value[1].get<float>()*1000000)/1000000), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}
// Тест 10:
TEST(myTests, CTest7) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test7.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test7_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 11:
TEST(myTests, CTest8_1) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test8_1.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Value outside float range");

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test8_1_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}
// Тест 12:
TEST(myTests, CTest8_2) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test8_2.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test8_2_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}
// Тест 13:
TEST(myTests, CTest8_3) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test8_3.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test8_3_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}
// Тест 14:
TEST(myTests, CTest8_4) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test8_4.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test8_4_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 15:
TEST(myTests, CTest8_5) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test8_5.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Value outside float range");

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test8_5_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 16:
TEST(myTests, CTest8_6) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test8_6.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Data is not a number");

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test8_6_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 17:
TEST(myTests, CTest9_1) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test9_1.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;


    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test9_1_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 18:
TEST(myTests, CTest9_2) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test9_2.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;


    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test9_2_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 19:
TEST(myTests, CTest9_3) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test9_3.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;
    testingCatchErrors.push_back("Array size is incorrect");

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test9_3_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}

// Тест 20:
TEST(myTests, CTest10) {
    vector <string> catchErrors;
    unordered_map<float, pair<int,int>> freqMap;
    int maxNum = 0;
    string way = "../../tests/Test10.json";
    bool close = openAndReadFile(way, freqMap, maxNum, catchErrors);
    vector <pair<pair<int, float>, int> >   answer = func(freqMap, maxNum);
    sort(answer.begin(), answer.end());

    vector <string> testingCatchErrors;

    vector <pair<pair<int, float>, int> >   testingAnswer;
    ifstream file("../../tests/Test10_Answer.json");
    json inputFile;
    file >> inputFile;
    for (auto& [key, value] : inputFile.items()) {
        testingAnswer.push_back(make_pair(make_pair(value[0], value[1]), value[2]));

    }
    file.close();

    EXPECT_EQ(answer, testingAnswer);
    EXPECT_EQ(catchErrors, testingCatchErrors);
}
