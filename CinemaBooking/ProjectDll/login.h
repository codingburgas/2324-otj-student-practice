#pragma once
#include <iostream>
#include <map>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class User {
public:
    string username;
    string password;

    User() {}
    User(string& uname, string& pass) : username(uname), password(pass) {}
};

class UserManager {
public:
    UserManager() {
        loadUsers();
    }

    bool registerUser(string& uname, string& pass) {
        if (users.find(uname) != users.end()) {
            return false;
        }
        User newUser(uname, pass);
        users[uname] = newUser;
        saveUser(newUser);
        return true;
    }

    bool loginUser(string& uname, string& pass) {
        if (users.find(uname) == users.end()) {
            return false;
        }
        return users[uname].password == pass;
    }

private:
    map<string, User> users;
    string filename = "../../users.txt";

    void loadUsers() {
        ifstream infile(filename);
        if (!infile) return;
        string uname, pass;
        while (infile >> uname >> pass) {
            users[uname] = User(uname, pass);
        }
        infile.close();
    }

    void saveUser(User& user) {
        ofstream outfile(filename, ios::app);
        outfile << user.username << " " << user.password << endl;
        outfile.close();
    }
};