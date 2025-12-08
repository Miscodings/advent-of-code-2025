#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool isInvalidProduct(long long id) {
    string s = to_string(id);
    int totalLen = s.length();
    
    for (int patternLen = 1; patternLen <= totalLen / 2; ++patternLen) {
        
        if (totalLen % patternLen == 0) {
            string pattern = s.substr(0, patternLen);
            string builtString = "";
            
            int repeats = totalLen / patternLen;

            for (int k = 0; k < repeats; ++k) {
                builtString += pattern;
            }

            if (builtString == s) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ifstream input("D:\\Downloads\\advent_of_code_2025\\day_2\\day2.txt");

    if (!input.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    long long ans = 0; 
    
    string fileContent;
    getline(input, fileContent); 
    stringstream ss(fileContent);
    string segment;

    while (getline(ss, segment, ',')) {
        size_t dashPos = segment.find('-');
        
        long long start = stoll(segment.substr(0, dashPos));
        long long end = stoll(segment.substr(dashPos + 1));

        for (long long currentId = start; currentId <= end; ++currentId) {
            if (isInvalidProduct(currentId)) {
                ans += currentId;
            }
        }
    }

    cout << "Total Sum: " << ans << endl;

    return 0;
}