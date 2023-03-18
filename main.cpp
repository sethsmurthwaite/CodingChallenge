#include <iostream>

int valueOf(char c);
bool isValid(std::string inp);
bool nextIsGreater(char c1, char c2);

int main(int argc, char* argv[]) {

    // Variables
    std::string input = argv[1];
    int value = 0;
    char currC;
    char nextC;

    // Input
    std::cout << "You input: " << input << "." << std::endl;

    // Logic
    if (isValid(input)) {
        for (int i = 0; i < input.size(); i++) {
            currC = input.substr(i, 1)[0];
            if (i < input.size() - 1) {
                nextC = input.substr(i + 1, 1)[0];
                if (nextIsGreater(currC, nextC)) {
                    value += (valueOf(nextC) - valueOf(currC));
                    i++;
                } else {
                    value += valueOf(currC);
                }
            } else {
                value += valueOf(currC);
            }
        }
    } else { std::cout << "You did not enter a valid Roman numeral. Roman Numerals can only be "
                          "preceeded by a value representing more than 1/10 of it's value. "
                          "(I can not precede C, L can't precede M, etc.)." << std::endl;
    }

    //Output
    std::cout << "Value: " << value << "." << std::endl;
    return 0;
}
int valueOf(char c) {
    if (c == 'I' || c == 'i') {
        return 1;
    }
    if (c == 'V' || c == 'v') {
        return 5;
    }
    if (c == 'X' || c == 'x') {
        return 10;
    }
    if (c == 'L' || c == 'l') {
        return 50;
    }
    if (c == 'C' || c == 'c') {
        return 100;
    }
    if (c == 'D' || c == 'd') {
        return 500;
    }
    if (c == 'M' || c == 'm') {
        return 1000;
    }
    return 0;
}
bool isValid(std::string inp) {
    for (int i = 0; i < inp.size() - 1; i++) {
        if (nextIsGreater(inp.at(i), inp.at(i+1))) {
            if (valueOf(inp.at(i + 1)) > valueOf(inp.at(i)) * 10) {
                return false;
            } else { continue; }
        }
    }
    return true;
}
bool nextIsGreater(char c1, char c2) {
    if (valueOf(c2) > valueOf(c1)) {
        return true;
    } else { return false; }
}
