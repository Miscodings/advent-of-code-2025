#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("D:\\Downloads\\advent_of_code_2025\\day_3\\input.txt");

    if (!input.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    long long ans = 0;
    string line;
    
    const int K = 12; 

    while (getline(input, line)) {

        vector<int> stack;
        int n = line.length();
        int digitsToRemove = n - K;

        for (char c : line) {
            int digit = c - '0';

            while (digitsToRemove > 0 && !stack.empty() && stack.back() < digit) {
                stack.pop_back();
                digitsToRemove--;
            }
            stack.push_back(digit);
        }

        stack.resize(K);

        long long currentJoltage = 0;
        for (int digit : stack) {
            currentJoltage = currentJoltage * 10 + digit;
        }

        ans += currentJoltage;
    }

    cout << "Total Output Joltage: " << ans << endl;
    return 0;
}