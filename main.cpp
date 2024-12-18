#include <iostream>
#include <fstream>
#include <string>
#include<bitset>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

// Function to read a message from a file and print the ASCII values of each character
void readMessageAndPrintASCII(const string& filename)
{
    ofstream file1 ("Output.txt");
    ofstream file2("Key.txt");
    ofstream file3("ciper.txt");
    srand(time(0));
    string keyXOR= "";
    ifstream f("Message.txt");  // Opens the file for reading
    if (!f)
    {  // Checks if the file could not be opened
        cout << "Cannot open the file!" << endl;
        return;
    }

    string message;  // A string variable to store the message
    string BynaryOutput;
    while (getline(f, message))
    {  // Reads each line of the file
        // Prints the ASCII value of each character in the message
        for (size_t i = 0; i < message.length(); i++)
        {
           int aciival = int(message[i]);
           bitset<8> binary(aciival);
           BynaryOutput += binary.to_string();



        }

    }

    f.close();  // Closes the file after reading

    int length = BynaryOutput.length();
    for (int j = 0; j<length; j++) {
        int bit = rand() % 2; // Generate 0 or 1 randomly
        keyXOR += to_string(bit);
    }

    if (file1.is_open()&&file2.is_open()) {
        file1<<BynaryOutput<<endl;
        file1.close();

        file2<<keyXOR<<endl;
    }
    else {
        system("exit");
    }


    string ciper = "";
    string finelciper = "";
    for (size_t i = 0; i < length; ++i) {
        // XOR בין שני המערכים
        char result = BynaryOutput[i] ^ keyXOR[i];

        // המרת התוצאה למיתר בינארי והוספתו ל-ciper
        ciper += to_string(result);  // להניח שמדובר בתו אחד (במקרה של ביטים יש להמיר ל-'0' או '1')

        // אם תרצה להוסיף תו בינארי ב-4 ביטים
        finelciper += bitset<1>(result).to_string(); // לדוגמה, תוכל להמיר ביט לתו בינארי בגודל של 4 ביטים

    }
    if (file3.is_open()) {
        file3<<ciper<<endl;
    }


}

int main() {

    string filename = "message.txt";  // Change this to the path of your file if necessary
    readMessageAndPrintASCII(filename);  // Calls the function to print the ASCII values




    return 0;
}
