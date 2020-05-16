#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

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