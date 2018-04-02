#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    const int ALPHA_LENGTH = 26;
    string inputFileName;
    string outputFileName;
    fstream in;
    fstream out;
    int offset;
    char c;

    if(argc < 4){
        cerr << "Arguments are in format: 'inputfile outputfile ceasaroffset'" << endl;
        return 1;
    }

    inputFileName = argv[1];
    outputFileName = argv[2];
    offset = atoi(argv[3]);

    if(offset < -25 || offset > 25){
        cerr << "Offset must be between -25 and 25 inclusive." << endl;
        return 1;
    }

    // Convert negative offets to their equivalent positive offsets
    if(offset < 0)
        offset = ALPHA_LENGTH + offset;

    in = fstream(inputFileName, fstream::in);

    if(in.fail()){
        cerr << "Input file does not exist." << endl;
        return 1;
    }
    
    out = fstream(outputFileName, fstream::out);

    if(out.fail()){
        cerr << "Output file cannot be created." << endl;
        return 1;
    }

    while (in.get(c)){
        if(isalpha(c) && isupper(c))
            c = (char)('A' + (((c - 'A') + offset) % ALPHA_LENGTH));
        else if(isalpha(c) && islower(c))
            c = (char)('a' + (((c-'a') + offset) % ALPHA_LENGTH));
        out << c;
    }

    in.close();
    out.close();

    return 0;
}
