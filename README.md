# student-management-system
C++ Student Management System with CRUD operations and file I/O
# Student Management System

A C++ console application for managing student records with full CRUD operations and persistent file storage.

## Features

- ✅ Add new student records
- ✅ View all students in formatted table
- ✅ Search students by ID
- ✅ Update student information
- ✅ Delete student records
- ✅ View statistics (total, average GPA, highest/lowest)
- ✅ Data persistence with file I/O
- ✅ Input validation

## Technologies Used

- C++
- STL (Standard Template Library)
- File I/O
- Object-Oriented Programming

## Student Information Stored

- Name
- Student ID (9 characters)
- Major
- Class
- GPA (0.0 - 5.0 scale)

## How to Run

1. Compile the program:
```bash
g++ main.cpp -o student_system
```

2. Run the executable:
```bash
./student_system
```

## Project Structure

- `main.cpp` - Main application code
- `Students.txt` - Data storage file (auto-generated)

## Learning Outcomes

This project demonstrates:
- Class design and encapsulation
- Vector usage for dynamic data storage
- File handling for data persistence
- Menu-driven console application
- Input validation and error handling

## Future Improvements

- GUI interface
- Database integration
- Sort/filter functionality
- Export to CSV
- Multi-user support

---

**Built as a learning project during C++ fundamentals study.**
