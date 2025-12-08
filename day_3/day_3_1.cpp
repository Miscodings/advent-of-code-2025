#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ifstream input("D:\\Downloads\\advent_of_code_2025\\day_3\\input.txt");

    if (!input.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    long long ans = 0;

    string line;
    while (getline(input, line)) {
        vector<int> numbers;

        for (char c : line) {
            numbers.push_back(stoi(string(1, c)));
        }
        
        long long maxSum = 0;
        int n = numbers.size();

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                long long currentSum = numbers[i] * 10 + numbers[j];
                if (currentSum > maxSum) {
                    maxSum = currentSum;
                }
            }
        }

        ans += maxSum;
    }

    cout << "Total Sum: " << ans << endl;
    
}