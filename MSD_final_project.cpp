#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Set a default file name
    std::string defaultFileName = "default_trace_file";
    std::string fileName;

    // Ask the user for a file name
    std::cout << "Enter the file name (press enter for default): ";
    std::getline(std::cin, fileName);

    // If no file name is entered, use the default file name
    if (fileName.empty()) {
        fileName = defaultFileName;
    }

    // Open the file for reading
    std::ifstream inputFile(fileName);

    // Check if the file was opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file: " << fileName << std::endl;
        return 1; // Return with an error code
    }

    // Read and parse the file line by line
    std::string line;
    int lineNumber = 0;
    while (std::getline(inputFile, line)) {
        lineNumber++;
        std::cout << line << std::endl;
    }
    // Close the file
    inputFile.close();

    // added a new code for debug 
    #ifdef DEBUG
        std::cout << "DEBUG: Line " << lineNumber << ": " << line << std::endl;
    #endif

    // Actual parsing/processing of the line
    // (In this case, we're just printing the line)
    std::cout << "Parsed Line " << lineNumber << ": " << line << std::endl;
    // debug code ends here

    
    return 0;
}

