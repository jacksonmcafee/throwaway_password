
# throwaway_password

This program is a basic command-line tool for generating random passwords of specified lengths, with options to include lowercase letters, uppercase letters, digits, and special characters.
## Installation and Usage

Clone this repository and make the executable:

```bash
https://github.com/jacksonmcafee/throwaway_password.git
make
```

Run `pass_gen`!

`./pass_gen [length] [optional flags]`

`./pass_gen 10 -uld` 
## Documentation


This documentation provides an overview of the functionality and usage of the program. The program generates random passwords of specified lengths, with customizable character sets, and provides options to include lowercase letters, uppercase letters, digits, and special characters.

1. **`void append(std::string& str1, std::string str2)`**  
   This function appends the contents of `str2` to the end of `str1`, allowing the building of a combined character set for password generation.

2. **`void generate_password(std::string& password, int password_length, std::string char_array)`**  
   This function generates a random password by utilizing the provided character set `char_array`. It creates a password of the specified `password_length` by randomly selecting characters from the character set.

3. **`int main(int argc, char **argv)`**  
   The main function orchestrates the password generation process. It parses command-line arguments to determine the password length and character set options. Based on the specified options, the program generates a random password and displays it to the user.

**Conclusion:**  
The Password Generator program is a simple tool for creating strong and randomized passwords. It's important to follow best practices for password management and to ensure that generated passwords are stored securely. 

*NOTE: Obviously, this is an extremely basic example and passwords generated with this tool likely should not actually be implemented anywhere mission-critical.*
## Authors

- [@jacksonmcafee](https://www.github.com/jacksonmcafee)

