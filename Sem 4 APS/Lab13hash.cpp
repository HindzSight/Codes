//Lab 13 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struct to hold each employee's information
struct Employee {
    string firstName;
    int ssn;
    int status; // 0=empty, 1=used, -1=deleted
};

// Hash table class
class HashTable {
private:
    vector<Employee> table; // Vector to hold the hash table

public:
    // Constructor to initialize the hash table with empty elements
    HashTable() {
        table.resize(200);
        for (int i = 0; i < 200; i++) {
            table[i].status = 0;
        }
    }

    // Hash function to get the index of the given ssn
    int hash(int ssn) {
        return ssn % 200;
    }

    // Method to add an employee to the hash table
    void add(string firstName, int ssn) {
        int index = hash(ssn);
        while (table[index].status == 1) { // Handle collisions using linear probing
            index = (index + 1) % 200;
        }
        table[index].firstName = firstName;
        table[index].ssn = ssn;
        table[index].status = 1;
    }

    // Method to remove an employee from the hash table
    void removeElement(string firstName) {
        for (int i = 0; i < 200; i++) {
            if (table[i].status == 1 && table[i].firstName == firstName) {
                table[i].status = -1;
                return;
            }
        }
        cout << "Employee not found" << endl;
    }

    // Method to get the ssn of an employee
    int getNumber(string firstName) {
        for (int i = 0; i < 200; i++) {
            if (table[i].status == 1 && table[i].firstName == firstName) {
                return table[i].ssn;
            }
        }
        cout << "Employee not found" << endl;
        return -1;
    }

    // Method to count the number of empty elements in the hash table
    int countEmpty() {
        int count = 0;
        for (int i = 0; i < 200; i++) {
            if (table[i].status == 0) {
                count++;
            }
        }
        return count;
    }

    // Method to print the contents of the non-empty elements in the hash table
    void print() {
        for (int i = 0; i < 200; i++) {
            if (table[i].status == 1) {
                cout << "Name: " << table[i].firstName << ", SSN: " << table[i].ssn << endl;
            }
        }
    }
};

// Sample usage
int main() {
    HashTable employees;
    employees.add("John", 123456789);
    employees.add("Alice", 987654321);
    employees.add("Bob", 555555555);
    employees.add("Jane", 111111111);

    cout << "Printing all employees:" << endl;
    employees.print();

    cout << "Removing Bob from the table..." << endl;
    employees.removeElement("Bob");

    cout << "Getting SSN of Alice..." << endl;
    cout << "SSN: " << employees.getNumber("Alice") << endl;

    cout << "Counting empty elements..." << endl;
    cout << "Empty elements: " << employees.countEmpty() << endl;

    return 0;
}
