#include <iostream>
#include <string>

using namespace std;

// Structure for Student Data
struct Student {
    string name;
    int regNo;
    int roomAllocated; 
};

// Global Storage
Student hostel[100];      
int rooms[5][10] = {0}; // 2D Array: 5 Floors, 10 Rooms each = 50 Rooms
int studentCount = 0;

// Function Prototypes
void adminMenu();
void studentLogin();
void addStudent();
void allotRoom();
void vacateRoom();
void searchStudent();
void viewAllStudents();
void showEmptyRooms();

int main() {
    int mainChoice;

    while (true) {
        cout << "\n=====================================";
        cout << "\n    HOSTEL MANAGEMENT MAIN MENU";
        cout << "\n=====================================";
        cout << "\n1. Admin Login";
        cout << "\n2. Student Login";
        cout << "\n3. Exit";
        cout << "\n-------------------------------------";
        cout << "\nEnter Choice: ";
        
        if (!(cin >> mainChoice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (mainChoice == 1) {
            string pass;
            cout << "\n[ADMIN ACCESS REQUIRED]";
            cout << "\nEnter Admin Password: ";
            cin >> pass;
            if (pass == "admin123") {
                adminMenu(); 
            } else {
                cout << "Invalid Password! Returning to main menu...\n";
            }
        } 
        else if (mainChoice == 2) {
            studentLogin();
        } 
        else if (mainChoice == 3) {
            cout << "Exiting system. Have a nice day!\n";
            return 0;
        } 
        else {
            cout << "Invalid Option! Please try again.\n";
        }
    }
    return 0;
}

// --- ADMIN MENU ---
void adminMenu() {
    int choice;
    while (true) {
        cout << "\n-------------------------------";
        cout << "\n       ADMIN CONTROL PANEL";
        cout << "\n-------------------------------";
        cout << "\n1. Add New Student";
        cout << "\n2. Allot Room to Student";
        cout << "\n3. Deallot Room (Vacate)";
        cout << "\n4. Search Student Details";
        cout << "\n5. View All Registered Students";
        cout << "\n6. Show All Empty Rooms";
        cout << "\n7. Logout to Main Menu";
        cout << "\n-------------------------------";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) allotRoom();
        else if (choice == 3) vacateRoom();
        else if (choice == 4) searchStudent();
        else if (choice == 5) viewAllStudents();
        else if (choice == 6) showEmptyRooms();
        else if (choice == 7) break; 
        else cout << "Invalid choice!\n";
    }
}

// --- STUDENT LOGIN ---
void studentLogin() {
    int rNo;
    cout << "\n--- STUDENT PORTAL ---";
    cout << "\n1. View My Details (via Reg No)";
    cout << "\n2. Back to Main Menu";
    cout << "\n----------------------";
    cout << "\nEnter Choice: ";
    int sChoice;
    cin >> sChoice;

    if (sChoice == 1) {
        cout << "Enter your Registration Number: ";
        cin >> rNo;

        Student* ptr = hostel; 
        bool found = false;

        for (int i = 0; i < studentCount; i++) {
            if ((ptr + i)->regNo == rNo) {
                cout << "\n--- YOUR STUDENT PROFILE ---";
                cout << "\nName: " << (ptr + i)->name;
                cout << "\nReg No: " << (ptr + i)->regNo;
                cout << "\nRoom Status: ";
                if ((ptr + i)->roomAllocated == -1) cout << "Not Allotted";
                else cout << "Room #" << (ptr + i)->roomAllocated;
                cout << "\n----------------------------\n";
                found = true;
                break;
            }
        }
        if (!found) cout << "No student found with that Registration Number.\n";
    }
}

// --- ADMIN FUNCTIONS ---

void addStudent() {
    if (studentCount < 100) {
        cout << "Enter Full Name: ";
        cin.ignore();
        getline(cin, hostel[studentCount].name);
        cout << "Enter Registration Number: ";
        cin >> hostel[studentCount].regNo;
        hostel[studentCount].roomAllocated = -1;
        studentCount++;
        cout << "Student Registered Successfully.\n";
    } else {
        cout << "Database Full!\n";
    }
}

void allotRoom() {
    int rNo, roomNum;
    cout << "Enter Student Reg No: ";
    cin >> rNo;
    for (int i = 0; i < studentCount; i++) {
        if (hostel[i].regNo == rNo) {
            if (hostel[i].roomAllocated != -1) {
                cout << "Student already has Room " << hostel[i].roomAllocated << endl;
                return;
            }
            cout << "Enter Room Number (1-50): ";
            cin >> roomNum;
            if (roomNum < 1 || roomNum > 50) {
                cout << "Invalid Room Number!\n";
                return;
            }

            int r = (roomNum - 1) / 10;
            int c = (roomNum - 1) % 10;

            if (rooms[r][c] == 1) {
                cout << "Room " << roomNum << " is already occupied!\n";
            } else {
                rooms[r][c] = 1;
                hostel[i].roomAllocated = roomNum;
                cout << "Room Allotted Successfully!\n";
            }
            return;
        }
    }
    cout << "Student not found!\n";
}

void vacateRoom() {
    int rNo;
    cout << "Enter Reg No to Vacate: ";
    cin >> rNo;
    for (int i = 0; i < studentCount; i++) {
        if (hostel[i].regNo == rNo) {
            if (hostel[i].roomAllocated == -1) {
                cout << "Student has no room allotted.\n";
                return;
            }
            int r = (hostel[i].roomAllocated - 1) / 10;
            int c = (hostel[i].roomAllocated - 1) % 10;
            rooms[r][c] = 0;
            hostel[i].roomAllocated = -1;
            cout << "Room successfully vacated.\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

void searchStudent() {
    int rNo;
    cout << "Enter Reg No: ";
    cin >> rNo;
    for (int i = 0; i < studentCount; i++) {
        if (hostel[i].regNo == rNo) {
            cout << "Found -> Name: " << hostel[i].name << " | Room: ";
            if (hostel[i].roomAllocated == -1) cout << "None";
            else cout << hostel[i].roomAllocated;
            cout << endl;
            return;
        }
    }
    cout << "Student record not found.\n";
}

void viewAllStudents() {
    if (studentCount == 0) {
        cout << "No students registered yet.\n";
        return;
    }
    cout << "\n--- LIST OF ALL STUDENTS ---\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << hostel[i].regNo << " | Name: " << hostel[i].name << " | Room: ";
        if (hostel[i].roomAllocated == -1) cout << "N/A";
        else cout << hostel[i].roomAllocated;
        cout << endl;
    }
}

void showEmptyRooms() {
    cout << "\n--- AVAILABLE ROOMS ---\n";
    bool anyEmpty = false;
    for (int i = 0; i < 5; i++) {
        cout << "Floor " << i + 1 << ": ";
        for (int j = 0; j < 10; j++) {
            if (rooms[i][j] == 0) {
                cout << (i * 10 + j + 1) << " ";
                anyEmpty = true;
            }
        }
        cout << endl;
    }
    if (!anyEmpty) cout << "No rooms available.\n";
}
