#include <iostream>

void toUpperFullString(std::string &text) {
    for(int i = 0; i<text.length(); i++) {
        text[i] = toupper(text[i]);
    }
}

void formatFirstName(std::string &firstName) {
    firstName[0] = toupper(firstName[0]);
    for(int i = 1; i<firstName.length(); i++) {
        firstName[i] = tolower(firstName[i]);
    }
}

int main() {
    std::cout << "Entre ton prénom et ton nom de famille : ";
    std::string firstName;
    std::string lastName;
    std::cin >> firstName >> lastName;

    formatFirstName(firstName);
    toUpperFullString(lastName);

    std::cout << "Bonjour " << firstName << " " << lastName << std::endl;
    

    return 0;
}