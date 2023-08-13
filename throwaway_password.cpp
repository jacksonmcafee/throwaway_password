#include <iostream>
#include <string>
#include <random>
#include <boost/lexical_cast.hpp>
#include <unistd.h>

// function declarations
void append(std::string& str1, std::string str2);
void generate_password(std::string& password, int password_length, std::string char_array);

// string constants
std::string USAGE_MSG = "\nUsage: ./pass_gen <length> <options>\n";
std::string OPTIONS = "\nOptions:\n"
                      "    -l    Include lowercase letters\n"
                      "    -u    Include uppercase letters\n"
                      "    -d    Include digits\n"
                      "    -s    Include special characters\n"
                      "    -h    Display this message\n\n"
                      "If no arguments are passed, all options are used.\n";

std::string LOWERCASE_ALPHABETICAL = "abcdefghijklmnopqrstuvwxyz";
std::string UPPERCASE_ALPHABETICAL = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
std::string DIGITS = "0123456789";
std::string SPECIAL_CHARACTERS = "!@#$%^&*()_+-=[]{};':\",./<>?\\|`~";

int main(int argc, char **argv) {
    // init flags and str array
    bool lc = false, uc = false, d = false, s = false;
    std::string char_array, password = "";
    int password_length, c;

    // check if valid argc is passed
    if (argc < 2) {
        std::cout << USAGE_MSG << OPTIONS << std::endl;
        return -1;
    }

    // parse password length from char*
    try {
        password_length = boost::lexical_cast<int>(argv[1]);
    } catch (boost::bad_lexical_cast) {
        std::cout << "Invalid length passed." << std::endl;
        return -1;
    }

    // check if no flags were passed
    if (argc == 2) {
        lc = true;
        uc = true;
        d = true;
        s = true;
    } else {
        // determine which flags were passed if needed
        while ((c = getopt (argc, argv, "ludsh")) != -1) {
            switch (c)
            {
                case 'l':
                    lc = true;
                    break;
                case 'u':
                    uc = true;
                    break;
                case 'd':
                    d = true;
                    break;
                case 's':
                    s = true;
                    break;
                case 'h':
                    std::cout << OPTIONS << std::endl;
                    return 0;
                default:
                    abort();
            }
        }
    }

    // set char_array based on flags
    if (lc) append(char_array, LOWERCASE_ALPHABETICAL); 
    if (uc) append(char_array, UPPERCASE_ALPHABETICAL);
    if (d)  append(char_array, DIGITS); 
    if (s)  append(char_array, SPECIAL_CHARACTERS);

    // generate random password
    generate_password(password, password_length, char_array);

    // print password
    std::cout << "Your password is: " << password << std::endl;

    return 0;
}


void append(std::string& str1, std::string str2) {
    str1 += str2;
}

void generate_password(std::string& password, int password_length, std::string char_array) {
    // init random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, char_array.length());

    // generate password
    for (int i = 0; i < password_length; i++) {
        password += char_array[distr(gen)];
    }
}