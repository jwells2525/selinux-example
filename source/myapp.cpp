#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <unistd.h>

using namespace std;

int main() {

  while (true) {
    ifstream configFile("myapp.conf");
    if (!configFile.is_open()) {
        cout << "Failed to open config file" << endl;
        return 1;
    }

    string phrase;
    getline(configFile, phrase);
    configFile.close();

    cout << "The phrase is: " << phrase << endl;

    ofstream logFile("myapp.log", ios::app);
    if (!logFile.is_open()) {
        cout << "Failed to open log file" << endl;
        return 1;
    }

    time_t now = time(nullptr);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&now));
    logFile << "[" << timestamp << "] " << phrase << endl;
    logFile.close();

    sleep(5);
  }

  return 0;
}

