#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Course {
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;

    Course() = default;

    Course(string number, string title) {
        courseNumber = number;
        courseTitle = title;
    }
};

struct Node {
    Course course;
    Node* left;
    Node* right;

    Node(Course aCourse) : course(aCourse), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    void addNode(Node* node, Course course) {
        if (course.courseNumber < node->course.courseNumber) {
            if (node->left == nullptr) {
                node->left = new Node(course);
            }
            else {
                addNode(node->left, course);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new Node(course);
            }
            else {
                addNode(node->right, course);
            }
        }
    }

    void inOrder(Node* node) {
        if (node == nullptr) {
            return;
        }
        inOrder(node->left);
        cout << node->course.courseNumber << ": " << node->course.courseTitle << endl;
        inOrder(node->right);
    }

    Node* search(Node* node, string courseNumber) {
        if (node == nullptr || node->course.courseNumber == courseNumber) {
            return node;
        }
        if (courseNumber < node->course.courseNumber) {
            return search(node->left, courseNumber);
        }
        else {
            return search(node->right, courseNumber);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(Course course) {
        if (root == nullptr) {
            root = new Node(course);
        }
        else {
            addNode(root, course);
        }
    }

    void printInOrder() {
        inOrder(root);
    }

    Course searchCourse(string courseNumber) {
        Node* node = search(root, courseNumber);
        if (node == nullptr) {
            return Course();
        }
        else {
            return node->course;
        }
    }
};

vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void loadCourses(string fileName, BinarySearchTree& bst) {
    ifstream file(fileName);
    string line;

    if (!file.is_open()) {
        cout << "Error: Unable to open file " << fileName << endl;
        return;
    }

    while (getline(file, line)) {
        vector<string> tokens = splitString(line, ',');

        if (tokens.size() < 2) {
            cout << "Error: Invalid course data format." << endl;
            continue;
        }

        Course course(tokens[0], tokens[1]);

        for (size_t i = 2; i < tokens.size(); ++i) {
            course.prerequisites.push_back(tokens[i]);
        }

        bst.insert(course);
    }

    file.close();
}

void printCourseInformation(Course course) {
    if (course.courseNumber.empty()) {
        cout << "Course not found." << endl;
        return;
    }

    cout << "Course Number: " << course.courseNumber << endl;
    cout << "Course Title: " << course.courseTitle << endl;

    if (!course.prerequisites.empty()) {
        cout << "Prerequisites: ";
        for (const auto& prereq : course.prerequisites) {
            cout << prereq << " ";
        }
        cout << endl;
    }
    else {
        cout << "Prerequisites: None" << endl;
    }
}

int main() {
    BinarySearchTree bst;
    int choice = 0;

    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Courses" << endl;
        cout << "  2. Print All Courses (Alphanumeric Order)" << endl;
        cout << "  3. Print Course Information" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string fileName;
            cout << "Enter file name: ";
            cin >> fileName;
            loadCourses(fileName, bst);
            break;
        }
        case 2:
            bst.printInOrder();
            break;
        case 3: {
            string courseNumber;
            cout << "Enter course number: ";
            cin >> courseNumber;
            Course course = bst.searchCourse(courseNumber);
            printCourseInformation(course);
            break;
        }
        case 9:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}