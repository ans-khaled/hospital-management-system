# 🏥 Hospital Management System
A complete C++ console-based application to manage doctors, patients, and appointments using strong Object-Oriented Programming (OOP) principles. 
Designed for learning and demonstrating clean code structure, terminal UI, and real-world logic simulation.

## 🔍 Project Overview

This project simulates a basic hospital system where:
• Admins can manage doctors, patients, and appointments.
• Doctors can log in and view their appointments.
• The system supports add/search/list/delete operations with validations and a clean terminal-based UI.

It's built with modern C++ and is perfect to demonstrate your understanding of:
• OOP concepts (Encapsulation, Inheritance, Polymorphism)
• Data structures (vectors, strings, objects)
• Input/output handling and terminal design

## ✨ Key Features
👨‍⚕️ Doctor Management
• Add new doctors with details (ID, Name, Gender, Age, Specialty, Availability)
• List all doctors in a formatted table
• Search for doctors by ID
• Delete doctors by ID
• Show only available doctors

👤 Patient Management
• Add patients with details (ID, Name, Gender, Age, Illness, Phone Number, Discharged status)
• List all patients
• Search and delete patients

📅 Appointment Management
• Schedule appointments (Doctor ID + Patient ID + Date + Time)
• View all appointments in a formatted table
• Search for appointments by ID
• Cancel appointments

🔐 Login System
• Separate login for Admin and Doctor
• Secure input with 3 login attempts
• Personalized menus based on user type

💻 Terminal UI:
• Clear and structured CLI interface
• Option-driven main menu with category separation
• Visual formatting with lines and boxes
• Feedback messages and user prompts

## 🛠 Tech Stack
Language: C++ (C++11/C++17)
Paradigm: Object-Oriented Programming
Concepts Used: Classes, Objects, Encapsulation, Inheritance, Vectors, Input/Output streams
Environment: CMD / Terminal
Build System: g++ / Visual Studio

## 🚀 How to Run
1- Clone the repository:
git clone https://github.com/ans-khaled/hospital-management-system.git
2- Open it in your favorite IDE or compile via terminal:
g++ main.cpp Doctor.cpp Patient.cpp Appointment.cpp Hospital.cpp -o hospital
./hospital

## 🔄 Future Improvements
Persistent data storage (file or database)
Graphical User Interface (GUI) with Qt or SFML
Real-time doctor availability updates
More secure login with encryption
Unit testing support
