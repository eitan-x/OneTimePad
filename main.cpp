#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to read a message from a file, generate an XOR key, and write output files
void processMessage(const string& inputFilename) {
    // Create output files
    ofstream outputFile("Output.txt");
    ofstream keyFile("Key.txt");
    ofstream cipherFile("ciper.txt");

    // Random number generator initialization
    srand(time(0));

    // Open input file for reading
    ifstream inputFile(inputFilename);
    if (!inputFile) {
        cout << "Cannot open the input file!" << endl;
        return;
    }

    string message, binaryOutput, keyXOR, cipher;
    
    // Read the message from the file and convert each character to binary
    while (getline(inputFile, message)) {
        for (char ch : message) {
            // Convert each character to its binary representation (8 bits)
            bitset<8> binaryChar(ch);
            binaryOutput += binaryChar.to_string();
        }
    }
    inputFile.close();  // Close the input file

    // Generate random XOR key of the same length as the binary message
    for (size_t i = 0; i < binaryOutput.length(); ++i) {
        keyXOR += to_string(rand() % 2);  // Randomly generate 0 or 1
    }

    // Write the binary message and the generated XOR key to their respective files
    if (outputFile.is_open() && keyFile.is_open()) {
        outputFile << binaryOutput << endl;
        keyFile << keyXOR << endl;
        outputFile.close();
        keyFile.close();
    } else {
        cout << "Error opening output files!" << endl;
        return;
    }

    // Perform XOR on binary message and XOR key, and store the result
    for (size_t i = 0; i < binaryOutput.length(); ++i) {
        // Perform XOR between corresponding bits of the binary message and key
        char result = (binaryOutput[i] == '1' ? 1 : 0) ^ (keyXOR[i] == '1' ? 1 : 0);
        
        // Append the result to the cipher string
        cipher += (result == 1 ? '1' : '0');
    }

    // Write the cipher (XORed message) to the output file
    if (cipherFile.is_open()) {
        cipherFile << cipher << endl;
        cipherFile.close();
    } else {
        cout << "Error opening cipher file!" << endl;
    }
}

int main() {
    string inputFilename = "message.txt";  // Change this to the path of your file if necessary
    processMessage(inputFilename);  // Process the message and generate output files
    return 0;
}

