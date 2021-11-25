#include <iostream>
#include <vector>

#include <getopt.h>

using namespace std;
vector<string>* handled_options = new vector<string>();

void Help()
{
    cout << "Option --help (-h) was used." << endl;
}

void Input(char* arg)
{
    cout << "Option --input (-i) with value " << arg << " was used." << endl;
}

void Output(char* arg)
{
    std::cout << "Option --output (-o) with value " << arg << " was used." << std::endl;
}

void Version()
{
    cout << "Option --version (-v) was used." << endl;
}

bool isAlreadyHandled(const std::string& option_name)
{
    for (auto& argument : *handled_options)
    {
        if (option_name == argument)
        {
            return true;
        }
    }
    return false;
}

int lab3(int argc, char** argv)
{
    int current_option;

    const char* short_options = "hvi::";

    struct option long_options[] = {
            {"help",    no_argument, nullptr, 'h'},
            {"input",  required_argument, nullptr, 'i'},
            {"output",  required_argument, nullptr, 'i'},
            {"version", no_argument, nullptr, 'v'},
            {nullptr, 0, nullptr, 0}
    };

    int option_index = 0;

    while ((current_option = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1)
    {
        string option_name;

        for (struct option& element : long_options)
        {
            if (element.val == current_option)
            {
                option_name = element.name;
                break;
            }
        }

        if (!(option_name.empty()) && isAlreadyHandled(option_name))
        {
            continue;
        }
        handled_options->push_back(option_name);

        switch (current_option)
        {
        case 'h':
            Help();
            break;

        case 'i':
            Input(optarg);
            break;

        case 'o':
            Input(optarg);
            break;

        case 'v':
            Version();
            break;

        case '?':
            break;

        default:
            abort();
        }
    }

    return 0;
}