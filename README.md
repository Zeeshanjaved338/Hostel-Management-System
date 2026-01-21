# Hostel Management System

## Overview
This is a **console-based C++ Hostel Management System** that allows administrators to manage student registrations and room allocations in a hostel. Students can also view their personal details and room status through a simple login portal.

The system supports multiple functionalities, including adding new students, allotting rooms, vacating rooms, searching student records, and viewing all registered students and empty rooms.

---

## Features

### Admin Panel
- Add new students to the hostel database.
- Allot rooms to registered students.
- Vacate allocated rooms.
- Search for student details by registration number.
- View a list of all registered students.
- Display all empty rooms in the hostel.

### Student Portal
- View individual student details using their registration number.
- Check room allocation status.

---

## Technical Details
- **Language:** C++
- **Data Structures:** 
  - `struct Student` for storing student information.
  - `2D array` for tracking room occupancy (5 floors × 10 rooms each = 50 rooms).
- **Global Storage:** Arrays store student and room data in memory.
- **Validation:** Ensures valid input for registration numbers and room allocation.
- **Access Control:** Admin login requires a password (`admin123`).

---

## Usage
1. Compile the program using a C++ compiler:
   ```bash
   g++ hostel_management.cpp -o hostel_management
Run the executable:
./hostel_management   # Linux/macOS
hostel_management.exe # Windows

Choose from the Main Menu:
> Admin Login
> Student Login
> Exit
Admin can perform management tasks after entering the correct password.
Students can view their profile and room allocation details using their registration number.
