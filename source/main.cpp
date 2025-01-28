#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

struct Command
{
    int argc;
    std::vector<std::string> argv;
    Command(const std::string str)
    {
        std::istringstream ss(str);
        std::string arg;
        while (std::getline(ss, arg, ' '))
        {
            argv.push_back(arg);
        }
        argc = argv.size();
    }
};

std::string wait_for_input()
{
    std::string r;
    std::getline(std::cin, r);
    return r;
}

void print_help(Command)
{
    std::cout <<
R"(help        this
load-func   load a function from a script
func        create and load a new, one-lined function
quit, exit, 
q,          exit)"
    << '\n';
}

void load_function_script(Command cmd)
{
    std::cerr << "null command" << '\n';
}

void prompt_create_function(Command cmd)
{
    std::cerr << "null command" << '\n';
}

void process(std::string str)
{
    Command cmd = Command(str);

    if (cmd.argv[0] == "help")
        print_help(cmd);
    else if (cmd.argv[0] == "load-func")
        load_function_script(cmd);
    else if (cmd.argv[0] == "func")
        prompt_create_function(cmd);        
    else if (cmd.argv[0] == "quit" || cmd.argv[0] == "q" || cmd.argv[0] == "exit")
        std::exit(EXIT_SUCCESS);
    else
        std::cerr << "this: " + cmd.argv[0] + ": command not found\n";
}

int main()
{
    while (bool running = true)
    {
        std::cout << ">> ";
        process(wait_for_input());
    }

    return EXIT_SUCCESS;
}