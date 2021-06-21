#include <iostream>
#include <string>

int shift_char (int max, int shift, char ch) {
    int min = max - 25;
    int a = ch;
    a += shift;
    if (a > max) {
        a = min + ((a - max) % 25);
    }
    else if (a < min) {
        a = max - ((min - a) % 25);
    }
    return a;
}

int char_type (char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return 'Z';
    } else if (ch >= 'a' && ch <= 'z') {
        return 'z';
    } else {
        return 0;
    }
}

std::string encrypt_caesar(std::string str, int n) {
    int l = str.length() - 1;
    for (int i = 0; i <= l; ++i) {
        if (char_type(str[i]) != 0) {
            str[i] = shift_char(char_type(str[i]), n, str[i]);
        }
    }
    return str;
}

std::string decrypt_ceasar(std::string str, int n) {
    n = -n;
    return encrypt_caesar(str, n);
}

int main() {
    std::string senOriginal;
    int shift;
    std::cout << "Input your sentence: ";
    std::getline(std::cin, senOriginal);
    std::cout << "Input the shift number: ";
    std::cin >> shift;

    senOriginal = encrypt_caesar(senOriginal, shift);
    std::cout << "Your encrypt sentence: " << senOriginal << std::endl;
    std::cout << "Your decrypt sentence: " << decrypt_ceasar(senOriginal, shift) << std::endl;
    return 0;
}
