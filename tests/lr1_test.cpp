#include <lib/lr1.h>
#include <lib/json.hpp>
#include <gtest/gtest.h>
#include <vector>
#include <utility>
#include <unordered_map>
#include <iostream>
#include "genTests.h"
using namespace std;

// Подробнее https://google.github.io/googletest/reference/testing.html

// Тестовый класс
class lr1Test : public ::testing::Test {
protected:
    // Здесь вы можете добавить дополнительные настройки для тестов
    // в функции SetUp()
    void SetUp() override {
        // Например, инициализация данных
        arr = {10.1, 14.2, 15.11, 10.1, 21, 25, 30};
    }

    // Здесь вы можете освободить ресурсы, если это необходимо
    // в функции TearDown()
    void TearDown() override {
        // Например, очистка данных
        arr.clear();
    }

    // Объявляем переменные, которые будут использоваться в тестах
    vector<float> arr;
    vector <pair<pair<int, float>, int> > result;
};

// Пример теста1
TEST_F(lr1Test, CTest1) {
// Вызываем функцию countAndSum с тестовыми данными
    //result = func(arr);

// Проверяем ожидаемые результаты
    EXPECT_EQ(result[0].first.first, 0);
    EXPECT_EQ(result[0].first.second, 10.1f);
    EXPECT_EQ(result[0].second, 2);
}

// Пример теста 2
TEST_F(lr1Test, CTest2) {
// Вызываем функцию countAndSum с тестовыми данными
    //result = func(arr);

// Проверяем ожидаемые результаты
    EXPECT_EQ(result[0].first.first, 0);
    EXPECT_EQ(result[0].first.second, 10.1f);
    EXPECT_EQ(result[0].second, 2);
}

// Пример теста3
TEST(lr1Test1, CTest3) {
    // Объявляем переменные, которые будут использоваться в тесте
    vector<float> arr;
    vector <pair<pair<int, float>, int> > result;
    // Инициализация данных
    arr = {10, 14, 15, 10, 21, 25, 30, 35, 5};
// Вызываем функцию countAndSum с тестовыми данными
    //result = func(arr);

// Проверяем ожидаемые результаты
    EXPECT_EQ(result[0].first.first, 0);
    EXPECT_EQ(result[0].first.second, 10);
    EXPECT_EQ(result[0].second, 2);
}

// ТЕСТ 4
TEST(lr1Test2, CTest4) {
    // ПОЛУЧЕНИЕ ВХОДНЫХ ДАННЫХ и ожидаемых результатов
    nlohmann::json test1 = creatTest1();
    // ОБРАБОТКА ВХОДНЫХ ДАННЫХ
    pair <unordered_map<float, pair<int,int> >, int> arr = input(test1);
    // ПОЛУЧЕНИЕ ВЫХОДНЫХ ДАННЫХ
    vector <pair<pair<int, float>, int> > result = func(arr.first, arr.second);

    // СРАВНЕНИЕ РЕЗУЛЬТАТОВ
    EXPECT_EQ(result[0].first.first, 5);
    EXPECT_EQ(result[0].first.second, 5);
    EXPECT_EQ(result[0].second, 3);

}