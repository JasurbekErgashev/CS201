#include <iostream>
using namespace std;

int main() {
    char message[12] = "Hello world";
    cout << "Message: " << message << endl;
    // keys array
    int encryptionKeys[4] = { 0, 2, -3, 20 };
    cout << "Encrypted message for: \n";
    for (int i{ 0 }; i < 4; i++) {
        cout << "Key " << encryptionKeys[i] << ": ";
        // encryption
        for (int j{ 0 }; j < 12; j++) {
            message[j] += encryptionKeys[i];
        }
        cout << message << endl;
        // decryption to return to the initial value of message
        for (int j{ 0 }; j < 12; j++) {
            message[j] -= encryptionKeys[i];
        }
    }
}
