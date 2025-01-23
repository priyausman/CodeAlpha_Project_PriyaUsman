#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Predefined questions and responses
    string questions[] = {
        "hello",
        "how are you",
        "what is your name",
        "what is programming",
        "can you explain git",
        "what is your purpose",
        "give me a motivation",
        "tell me a joke",
        "bye"
    };

    string responses[] = {
        "Hello! It's great to meet you. How can I assist you today?",
        "I'm just a program, but I'm here to help! How about you?",
        "I am your friendly C++ chatbot, designed to assist and guide you.",
        "Programming is the process of creating a set of instructions for a computer to follow. It's like teaching a machine to solve problems!",
        "Git is a version control system that helps developers track changes in their code and collaborate effectively. Would you like me to explain more?",
        "My purpose is to assist you, answer your queries, and make your learning journey enjoyable.",
        "Success doesn't come from what you do occasionally. It comes from what you do consistently. Keep pushing forward!",
        "Why do programmers prefer dark mode? Because light attracts bugs! ??",
        "Goodbye! Keep learning and have a fantastic day!"
    };

    string userInput;
    bool exitChat = false;

    // Welcome message
    cout << "========================================\n";
    cout << "           Welcome to ChatBot           \n";
    cout << "========================================\n";
    cout << "Type 'bye' to exit the chat.\n";
    cout << "Let's have a great conversation!\n";
    cout << "========================================\n\n";

    while (!exitChat) {
        cout << "You: ";
        getline(cin, userInput);

        bool found = false;

        // Check if the input matches any predefined question
        for (int i = 0; i < 9; i++) {
            if (userInput == questions[i]) {
                // Match found, print corresponding response
                cout << setw(10) << left << "Chatbot: " << responses[i] << endl;
                found = true;
                if (userInput == "bye") {
                    exitChat = true;
                }
                break;
            }
        }

        // If no match, provide a default response
        if (!found) {
            cout << setw(10) << left << "Chatbot: " 
                 << "Hmm, I am not sure about that. Can you ask something else?\n";
        }
    }

    // Goodbye message
    cout << "\n========================================\n";
    cout << "       Thank you for chatting!       \n";
    cout << "========================================\n";

    return 0;
}


