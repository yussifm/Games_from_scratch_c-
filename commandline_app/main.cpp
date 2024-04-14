#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <command>" << std::endl;
        return 1;
    }

    std::string command = argv[1];

    if (command == "hello")
    {
        std::cout << "Hello, world!" << std::endl;
    }
    else if (command == "add")
    {
        if (argc < 4)
        {
            std::cout << "Usage: " << argv[0] << " add <num1> <num2>" << std::endl;
            return 1;
        }

        int num1 = std::stoi(argv[2]);
        int num2 = std::stoi(argv[3]);
        int result = num1 + num2;

        std::cout << num1 << " + " << num2 << " = " << result << std::endl;
    }
    else
    {
        std::cout << "Unknown command: " << command << std::endl;
    }

    return 0;
}