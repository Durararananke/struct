#include <iostream>
#include <string>
std::string atbashCiper(std::string &input)
{
    std::string output = input;
    for (char &c: output)
    {
        if (isalpha(c))
        {
            if (isupper(c))
            {
                c = 'Z' - (c - 'A');
            }
            else
            {
                c = 'z' - (c - 'a');
            }
        }
    }
    return output;
}
int main()
{
    std::string input;
    std::cout<<"Enter the string to be encrypted: ";
    std::getline(std::cin, input);
    std::cout<<"Encrypted string: "<<atbashCiper(input)<<std::endl;
    return 0;
}