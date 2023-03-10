#include <bits/stdc++.h>
using namespace std;

#ifndef __linux__
    #define RESET   "\033[0m"
    #define BLACK   "\033[30m"      /* Black */
    #define RED     "\033[31m"      /* Red */
    #define GREEN   "\033[32m"      /* Green */
    #define YELLOW  "\033[33m"      /* Yellow */
    #define BLUE    "\033[34m"      /* Blue */
    #define MAGENTA "\033[35m"      /* Magenta */
    #define CYAN    "\033[36m"      /* Cyan */
    #define WHITE   "\033[37m"      /* White */
    #define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
    #define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
    #define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
    #define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
    #define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
    #define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
    #define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
    #define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#else
    #define RESET   ""
    #define BLACK   ""      /* Black */
    #define RED     ""      /* Red */
    #define GREEN   ""      /* Green */
    #define YELLOW  ""      /* Yellow */
    #define BLUE    ""      /* Blue */
    #define MAGENTA ""      /* Magenta */
    #define CYAN    ""      /* Cyan */
    #define WHITE   ""      /* White */
    #define BOLDBLACK   ""      /* Bold Black */
    #define BOLDRED     ""      /* Bold Red */
    #define BOLDGREEN   ""      /* Bold Green */
    #define BOLDYELLOW  ""      /* Bold Yellow */
    #define BOLDBLUE    ""      /* Bold Blue */
    #define BOLDMAGENTA ""      /* Bold Magenta */
    #define BOLDCYAN    ""      /* Bold Cyan */
    #define BOLDWHITE   ""      /* Bold White */
#endif

int main(int argc, char* argv[])
{
    // assume input file is problem.out
    // assume this file resides in the top most dir of the contest dir

    ifstream infile;
    infile.open("main.out");
    std::vector<std::string> program_outputs;
    while(infile.is_open())
    {
        std::string line;
        while(std::getline(infile, line))
        {
            program_outputs.push_back(line);
        }
        infile.close();
    }

    std::vector<std::string> sample_outputs;
    infile.open("samples/data.out");
    while(infile.is_open())
    {
        std::string line;
        while(getline(infile, line))
        {
            sample_outputs.push_back(line);
        }
        infile.close();
    }
    std::cout << GREEN;
    std::cout << "For the D2A problem" << ": \n";
    int cases = program_outputs.size();
    int correct_cases = 0;
    for(int i = 0; i < cases; i++)
    {
        std::cout << WHITE;
        std::cout << "Case " << i + 1 << ": " << program_outputs[i] << "   |   " << sample_outputs[i] << '\n';
        if(program_outputs[i] == sample_outputs[i])
        {
            correct_cases++;
        }
    }
    std::cout << BOLDRED;
    std::cout << correct_cases << "/" << cases << " test cases passed.\n";
    std::cout << RESET;
    return(0);
}
