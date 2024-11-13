#include <iostream>
#include <bitset>
#include <string>
using namespace std;
const int N = 32; // Bitset size, ensure it’s large enough for dividend + remainder

void CRC(const string& dataword, const string& generator) {
    // Convert dataword and generator to bitsets
    bitset<N> dword(bitset<N>(dataword).to_ulong()); // Dataword as a bitset
    bitset<N> gen(bitset<N>(generator).to_ulong()); // Generator as a bitset

    // Prepare the dividend by shifting dword to leave space for remainder bits
    bitset<N> dividend = dword << (generator.size() - 1);
    int shift = dividend.size() - generator.size(); // Initial alignment shift

    // Perform XOR division
    while (shift >= 0) {
        if (dividend[shift + generator.size() - 1]) { // Check MSB in current segment
            dividend ^= (gen << shift); // XOR generator aligned to current MSB
        }
        shift--; // Move shift position leftward
    }

    // Combine dataword with remainder to get codeword
    bitset<N> codeword = (dword << (generator.size() - 1)) | dividend;
    
    // Output the remainder and codeword
    string remainder_str = dividend.to_string().substr(N - generator.size() + 1);
    string codeword_str = codeword.to_string().substr(N - dataword.size() - generator.size() + 1);

    cout << "Remainder: " << remainder_str << endl;
    cout << "Codeword : " << codeword_str << endl;
}

int main() {
    string dataword = "110";  // Example dataword
    string generator = "10001000000100001";  // Example generator polynomial
    //for 8 bit 100000111

    try {
        CRC(dataword, generator);  // Call the CRC function
    } catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}


//https://www.youtube.com/watch?v=IYBIIUgyjX4