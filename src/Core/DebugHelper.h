#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

// Function pointers -> void(*func)(params) || std::function<void(int)>& func (to use the capture group of each lambda input [])
// auto fx = void(*func)(params) -> fx()
// typedef void(*func)(params) -> func()
// Lambdas -> function(vals, [](int num) { std::cout << num; }) -> [](int num) { std::cout << num; } 

// std::thread worker(func); -> Already kicks off the thread
// std::this_thread::sleep_for(std::literals::chrono_literals 1s) -> Sleeps to prevent overusing CPU
// std::this_thread::getId()
// worker.join(); -> Block flow until finished -> Oversimplifying it -> 'await'

class DebugHelper {
public:

    template <class T>
    void print(T s) {
        std::cout << s << std::endl;
    }

    template <class T>
    void printNoEndln(T s) {
        std::cout << s;
    }
    // template <>
    // void print<std::string>(std::string s) {
    //     std::cout << s << std::endl;
    // }

    template <class T>
    void printVector(const T& vec) {
        for (int i = 0; i < vec.size(); i++) {
            print("------------");
            print(vec[i]);
        }
    }

    template <class T, class S>
    void printVectors(const T& vec, const S& vec2) {
        for (int i = 0; i < vec.size(); i++) {
            print("------------");
            printNoEndln(vec[i]);
            printNoEndln("->");
            print(vec2[i]);
        }
    }

    std::vector<char> keys(std::map<char, int> map) {
        std::vector<char> v;
        for (std::map<char, int>::iterator it = map.begin(); it != map.end(); ++it) {
            v.push_back(it->first);
        }
        return v;
    }

    std::vector<std::string> keys(std::map<std::string, int> map) {
        std::vector<std::string> v;
        for (std::map<std::string, int>::iterator it = map.begin(); it != map.end(); ++it) {
            v.push_back(it->first);
        }
        return v;
    }

    std::vector<int> values(std::map<char, int>& map) {
        std::vector<int> v;
        for (std::map<char, int>::iterator it = map.begin(); it != map.end(); ++it) {
            v.push_back(it->second);
        }
        return v;
    }

    std::vector<int>& concatIntVec(std::vector<int>& v1, std::vector<int>& v2) {
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
    }

    std::vector<int>& splice(std::vector<int>& vec, int index) {
        vec.erase(vec.begin() + index);
        return vec;
    }

    std::vector<std::vector<int>> matrix(int nArr, int nEl, std::vector<int>& v) {
        std::vector<std::vector<int>> vec2d(nArr);
        int skip = 0;
        for (int i = 0; i < nArr; i++) {
            for (int j = 0; j < nEl; j++) {
                vec2d[i].push_back(v[j + skip]);
            }
            skip += nEl;
        }
        return vec2d;
    }
};

#endif