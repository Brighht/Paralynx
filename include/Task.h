#pragma once
#include <functional>
#include <string>

using namespace std;

struct Task {
    string id;
    function<void()> work;
};