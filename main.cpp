#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
using namespace std;

class Person {
protected:
    string id; // like "D001"
    string name;
    string gender;
    int age;

public:

    virtual void showInfo() = 0;

    string getId() {
        return id;
    }
};

class Doctor : public Person {
    string specialty;
    bool isAvailable;

public:
    Doctor(string docId, string docName, string docGender, int docAge, string docSpecialty, bool docIsAvailable) {
        id = docId;
        name = docName;
        gender = docGender;
        age = docAge;
        specialty = docSpecialty;
        isAvailable = docIsAvailable;
    }

    void showInfo() override {
        cout << "| " << setw(6)  << id
         << " | " << setw(20) << name
         << " | " << setw(6)  << gender
         << " | " << setw(3)  << age
         << " | " << setw(18) << specialty
         << " | " << setw(9)  << (isAvailable ? "Yes" : "No")
         << " |\n";
    }

    bool getAvailablitiy() {
        return isAvailable;
    }
};

class Patient : public Person {
    string phoneNumber;
    string illness;
    bool discharged;

    public:
    Patient(string pId, string pName, string pGender, int pAge ,string pIllness, string pPhoneNumber , bool pDischarged) {
        id = pId;
        name = pName;
        gender = pGender;
        age = pAge;
        illness = pIllness;
        phoneNumber = pPhoneNumber;
        discharged = pDischarged;
    }

    void showInfo() override {
        cout << "| " << setw(6)  << id
         << " | " << setw(20) << name
         << " | " << setw(6)  << gender
         << " | " << setw(3)  << age
         << " | " << setw(14) << illness
         << " | " << setw(17) << phoneNumber
         << " | " << setw(10)  << (discharged ? "Yes" : "No")
         << " |\n";
    }

};

class Appointment {
    string appointmentId;
    string doctorId;
    string patientId;
    string date;
    string time;

    public:
    Appointment(string Aid, string dId, string ptId, string Adate, string Atime) {
        appointmentId = Aid;
        doctorId = dId;
        patientId = ptId;
        date = Adate;
        time = Atime;
    }

    void showAppointment() {
        cout << "| " << setw(13) << appointmentId
         << " | " << setw(10)  << doctorId
         << " | " << setw(10) << patientId
         << " | " << setw(13) << date
         << " | " << setw(11)  << time
         << " |\n";
    }

    string getAppoinmentId() {
        return appointmentId;
    }
};

class Hospital {
    vector<Doctor* > doctors;
    vector<Patient* > patients;
    vector<Appointment* > appointments;

public:

    void setDoctor(Doctor* d) { doctors.push_back(d); }
    void setPatient(Patient* d) { patients.push_back(d); }
    void setAppointment(Appointment* d) { appointments.push_back(d); }



    void addDoctor();
    void addPatient();
    void addAppointment();


    void displayDoctors() {
        for (int i = 0; i < doctors.size(); i++) {
            doctors[i]->showInfo();
        }
    }
    void displayPatients() {
        for (int i = 0; i < patients.size(); i++) {
            patients[i]->showInfo();
        }
    }
    void displayAppointments() {
        for (int i = 0; i < appointments.size(); i++) {
            appointments[i]->showAppointment();
        }
    }


    void showAvailableDoctors() {

        if (doctors.empty()) {
            cout << "\nThere are no doctors in the system.\n";
            return;
        }


        bool found = false;
        for (int i = 0; i < doctors.size(); i++) {
            if (doctors[i]->getAvailablitiy()) {
                doctors[i]->showInfo();
                found = true;
            }
        }

        if (!found) {
            cout << "No doctors are currently available.\n";
        }
    }


    void searchOnDoctor(string id);
    void searchOnPatient(string id);
    void searchOnAppoinment(string id);


    void deleteDoctor(string id);
    void deletePatient(string id);
    void cancelAppoinment(string id);
};


void printDoctorHeader() {
    cout << "+--------+----------------------+--------+-----+--------------------+-----------+\n";
    cout << "| ID     | Name                 | Gender | Age | Specialty          | Available |\n";
    cout << "+--------+----------------------+--------+-----+--------------------+-----------+\n";
}
void printPatientHeader() {
    cout << "+--------+----------------------+--------+-----+----------------+-------------------+------------+\n";
    cout << "| ID     | Name                 | Gender | Age | Illness        | Phone Number      | Discharged |\n";
    cout << "+--------+----------------------+--------+-----+----------------+-----------+-------+------------+\n";
}
void printAppointmentHeader() {
    cout << "+---------------+------------+------------+---------------+-------------+\n";
    cout << "| Appoinment ID | Doctor ID  | Patient ID | Date          | Time         \n";
    cout << "+---------------+------------+------------+---------------+-------------+\n";
}


void Hospital::addDoctor() {
    cout << "\n=========================================\n";
    cout << "        Add New Doctor to System\n";
    cout << "=========================================\n";

    string docId, docName, docGender, docSpecialty;
    int docAge;
    bool docIsAvailable;

    cout << "\nPlease enter the doctor ID: ";
    cin >> docId;


    cout << "Please enter the doctor name: ";
    cin.ignore(); // Clear leftover newline from previous input
    getline(cin, docName); // to allow spaces in the name like: Anas Khaled.

    cout << "Please enter the doctor gender: ";
    getline(cin, docGender);

    // Validation of the Age not negative and not more than 100 years.
    do {
        cout << "Please enter the doctor age: ";
        cin >> docAge;
        if (docAge <= 0 || docAge > 100) {
            cout << "Please enter a valid age.\n";
        }
    } while (docAge <= 0 || docAge > 100);

    cout << "Please enter the doctor specialty: ";
    cin.ignore(); getline(cin, docSpecialty);

    cout << "Is the doctor available? (1 for Yes, 0 for No): ";
    cin >> docIsAvailable;

    Doctor* d = new Doctor(docId, docName, docGender, docAge, docSpecialty, docIsAvailable);
    doctors.push_back(d);

    cout << "\n Doctor \"" << docName << "\" has been added successfully!\n";
    cout << "-----------------------------------------\n";
}
void Hospital::addPatient() {
    cout << "\n=========================================\n";
    cout << "        Add New Patient to System\n";
    cout << "=========================================\n";
    string phoneNumber, Id, name, gender, pllness;
    int age, discharged;

    cout << "Please enter the patient Id: ";
    cin >> Id;

    cout << "Please enter the patient name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Please enter the patient gender: ";
    getline(cin, gender);

    do {
        cout << "Please enter the patient age: ";
        cin >> age;
        if (age <= 0 || age > 100) {
            cout << "Please enter a valid age.\n";
        }
    } while (age <= 0 || age > 100);

    cout << "Please enter the patient pllness: ";
    cin.ignore(); getline(cin, pllness);

    cout << "Please enter the patient Phone Number: ";
    cin.ignore();
    getline(cin, phoneNumber);

    cout << "Is the patient discharged ? (1 for Yes, 0 for No): ";
    cin >> discharged;

    Patient* p = new Patient(Id, name, gender, age, pllness, phoneNumber, discharged);
    patients.push_back(p);

    cout << "\n patient \"" << name << "\" has been added successfully!\n";
    cout << "-----------------------------------------\n";
}
void Hospital::addAppointment() {
    cout << "\n===========================================\n";
    cout << "        Add New Appointment to System\n";
    cout << "===========================================\n";

    string AppointmentId, doctorId, patientId, date, time;

    cout << "Please enter the appointment ID: ";
    cin >> AppointmentId;

    cout << "Please enter the doctor ID: ";
    cin.ignore();
    cin >> doctorId;

    cout << "Please enter the patient ID: ";
    cin >> patientId;

    cout << "Please enter the Appointment date: ";
    cin.ignore();
    cin >> date;

    cout << "Please enter the Appointment time: ";
    cin >> time;

    Appointment* a = new Appointment(AppointmentId, doctorId, patientId, date, time);
    appointments.push_back(a);

    cout << "\n Appointment \"" << AppointmentId << "\" has been added successfully!\n";
    cout << "-----------------------------------------\n";
}


void Hospital::searchOnDoctor(string id) {
    if (doctors.empty()) {
        cout << "There is no doctors in the Hospital." << endl;
        return;
    }
    for (int i = 0; i < doctors.size(); i++) {
        if (doctors[i]->getId() == id) {
            printDoctorHeader();
            doctors[i]->showInfo();
            cout << "---------------------------------------------------------------------------------\n";
            return;
        }
    }
    cout << "\nNo doctor found with ID: " << id << endl;
}
void Hospital::searchOnPatient(string id) {
    if (patients.empty()) {
        cout << "There is no patients in the Hospital." << endl;
        return;
    }
    for (int i = 0; i < patients.size(); i++) {
        if (patients[i]->getId() == id) {
            printPatientHeader();
            patients[i]->showInfo();
            cout << "--------------------------------------------------------------------------------------------------\n";
            return;
        }
    }
    cout << "\nNo patient found with ID: " << id << endl;
}
void Hospital::searchOnAppoinment(string id) {
    if (appointments.empty()) {
        cout << "There is no appointments in the Hospital." << endl;
        return;
    }
    for (int i = 0; i < appointments.size(); i++) {
        if (appointments[i]->getAppoinmentId() == id) {
            printAppointmentHeader();
            appointments[i]->showAppointment();
            cout << "-------------------------------------------------------------------------\n";
            return;
        }
    }
    cout << "\nNo Appoinment found with ID: " << id << endl;
}


void Hospital::deleteDoctor(string id) {
    if (doctors.empty()) {
        cout << "There is no doctors in the Hospital." << endl;
        return;
    }

    for (int i = 0; i < doctors.size(); i++) {
        if (doctors[i]->getId() == id) {
            delete doctors[i];
            doctors.erase(doctors.begin() + i);
            cout << "Doctor deleted successfully.";
            return;
        }
    }

    cout << "\nNo doctor found with ID: " << id << endl;
}
void Hospital::deletePatient(string id) {
    if (patients.empty()) {
        cout << "There is no Patients in the Hospital." << endl;
        return;
    }

    for (int i = 0; i < patients.size(); i++) {
        if (patients[i]->getId() == id) {
            delete patients[i];
            patients.erase(patients.begin() + i);
            cout << "Patient deleted successfully.";
            return;
        }
    }

    cout << "\nNo Patient found with ID: " << id << endl;
}
void Hospital::cancelAppoinment(string id) {
    if (appointments.empty()) {
        cout << "There is no Appointments in the Hospital." << endl;
        return;
    }

    for (int i = 0; i < appointments.size(); i++) {
        if (appointments[i]->getAppoinmentId() == id) {
            delete appointments[i];
            appointments.erase(appointments.begin() + i);
            cout << "Appointment canceled successfully.";
            return;
        }
    }

    cout << "\nNo Appointments found with ID: " << id << endl;
}


//  Login System for Admin and Doctor.
class User {
protected:
    string username;
    string password;

    public:
    User(string user, string pass) {
        username = user;
        password = pass;
    }

    bool loginChecking(string un, string pw) {
        return (username == un && password == pw);
    }
};
class Admin : public User {
    public:
    Admin(string user, string pass) : User(user, pass) {}
};
class Doc : public User {
    public:
    Doc(string user, string pass) : User(user, pass) {}
};

void showAdminMenu(Hospital& hospital) {
    int choice;
    bool running = true;
    while (running) {
        cout << "\n";
        cout << "+-----------------------------------------+\n";
        cout << "|         HOSPITAL MANAGEMENT SYSTEM      |\n";
        cout << "+-----------------------------------------+\n";

        cout << "| [Doctor Operations]                     |\n";
        cout << "|   1. Add Doctor                         |\n";
        cout << "|   2. List Doctors                       |\n";
        cout << "|   3. Search for Doctor                  |\n";
        cout << "|   4. Show Available Doctors             |\n";
        cout << "|   5. Delete Doctor                      |\n";

        cout << "| [Patient Operations]                    |\n";
        cout << "|   6. Add Patient                        |\n";
        cout << "|   7. List Patients                      |\n";
        cout << "|   8. Search for Patient                 |\n";
        cout << "|   9. Delete Patient                     |\n";

        cout << "| [Appointment Operations]                |\n";
        cout << "|  10. Schedule Appointment               |\n";
        cout << "|  11. List Appointments                  |\n";
        cout << "|  12. Search for Appointment             |\n";
        cout << "|  13. Cancel Appointment                 |\n";

        cout << "|                                         |\n";
        cout << "|  0. Exit                                |\n";
        cout << "+-----------------------------------------+\n";
        cout << "Choose an option: ";


        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 13) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number(0 - 13).\n";
            continue;
        }

        string id;
        switch (choice) {
            case 1:
                hospital.addDoctor();
                break;

            case 2:
                printDoctorHeader();
                hospital.displayDoctors();
                break;

            case 3:
                cout << "Please enter the Doctor ID to search: \n";
                cin.ignore();
                getline(cin, id);
                hospital.searchOnDoctor(id);
                break;

            case 4:
                cout << "\nList of Available Doctors:\n";
                printDoctorHeader();
                hospital.showAvailableDoctors();
                break;

            case 5:
                cout << "Please enter the Doctor ID to delete: ";
                cin.ignore();
                getline(cin, id);
                hospital.deleteDoctor(id);
                break;


            case 6:
                hospital.addPatient();
                break;

            case 7:
                printPatientHeader();
                hospital.displayPatients();
                break;

            case 8:
                cout << "Please enter the Patient ID to search: \n";
                cin.ignore();
                getline(cin, id);
                hospital.searchOnPatient(id);
                break;

            case 9:
                cout << "Please enter the Patient ID to delete: ";
                cin.ignore();
                getline(cin, id);
                hospital.deletePatient(id);
                break;


            case 10:
                hospital.addAppointment();
                break;

            case 11:
                printAppointmentHeader();
                hospital.displayAppointments();
                break;

            case 12:
                cout << "Please enter the Appoinment ID to search: \n";
                cin.ignore();
                getline(cin, id);
                hospital.searchOnAppoinment(id);
                break;


            case 13:
                cout << "Please enter the Appoinment ID to Cancel: ";
                cin.ignore();
                getline(cin, id);
                hospital.cancelAppoinment(id);
            break;


            case 0:
                char confirm;
                while (true) {
                    cout << "Are you sure you want to exit? (y / n): ";
                    cin >> confirm;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer to remove any leftover newline character.
                    if (confirm == 'y' || confirm == 'Y') {
                        cout << "Thank you for visiting the Hospital. Goodbye!\n";
                        cout << "Exiting...\n";
                        running = false;
                        break;
                    } else if (confirm == 'n' || confirm == 'N') {
                        cout << "\nReturning to main menu.\n";
                        break;
                    } else {
                        cout << "Please enter only 'y' or 'n'. Try again.\n";
                    }
                }
                break;

            default:
                cout << "Invalid input! Please enter a number.\n";
        }

    }
}
void showDoctorMenu(Hospital& hospital) {

    int choice;
    bool running = true;
    while (running) {
        cout << "\n";
        cout << "+-----------------------------------------+\n";
        cout << "|      HOSPITAL SYSTEM - DOCTOR MODE      |\n";
        cout << "+-----------------------------------------+\n";

        cout << "| [Doctor Access]                         |\n";
        cout << "|   1. List Doctors                       |\n";
        cout << "|   2. Show Available Doctors             |\n";

        cout << "| [Patient Access]                        |\n";
        cout << "|   3. List Patients                      |\n";
        cout << "|   4. Search for Patient                 |\n";

        cout << "| [Appointments]                          |\n";
        cout << "|   5. List Appointments                  |\n";
        cout << "|   6. Search for Appointment             |\n";

        cout << "|                                         |\n";
        cout << "|   0. Exit                               |\n";
        cout << "+-----------------------------------------+\n";
        cout << "Choose an option: ";


        cin >> choice;
        if (cin.fail() || choice < 0 || choice > 13) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number(0 - 13).\n";
            continue;
        }

        string id;
        switch (choice) {
            case 1:
                printDoctorHeader();
                hospital.displayDoctors();
                break;

            case 2:
                cout << "\nList of Available Doctors:\n";
                printDoctorHeader();
                hospital.showAvailableDoctors();
                break;

            case 3:
                printPatientHeader();
                hospital.displayPatients();
                break;

            case 4:
                cout << "Please enter the Patient ID to search: \n";
                cin.ignore();
                getline(cin, id);
                hospital.searchOnPatient(id);
                break;

            case 5:
                printAppointmentHeader();
                hospital.displayAppointments();
                break;


            case 6:
                cout << "Please enter the Appoinment ID to search: \n";
                cin.ignore();
                getline(cin, id);
                hospital.searchOnAppoinment(id);
                break;


            case 0:
                char confirm;
                while (true) {
                    cout << "Are you sure you want to exit? (y / n): ";
                    cin >> confirm;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer to remove any leftover newline character.
                    if (confirm == 'y' || confirm == 'Y') {
                        cout << "Thank you for visiting the Hospital. Goodbye!\n";
                        cout << "Exiting...\n";
                        running = false;
                        break;
                    } else if (confirm == 'n' || confirm == 'N') {
                        cout << "Returning to main menu.\n";
                        break;
                    } else {
                        cout << "Please enter only 'y' or 'n'. Try again.\n";
                    }
                }
                break;

            default:
                cout << "Invalid input! Please enter a number.\n";
        }

    }
}

bool tryLogin(User& account ,int maxLoginTimes) {
    string username, password;
    int tries = maxLoginTimes;

    while (tries > 0) {
        cout << "\nPlease enter username: ";
        cin >> username;
        cout << "Please enter password: ";
        cin >> password;

        if (account.loginChecking(username, password)) {
            cout << "Logged in successfully!\n";
            return true;
        }
        --tries;
        if (tries > 0) {
            cout << "Login failed. Tries left: " << tries << '\n';
        }
    }

    cout << "Too many failed attempts.\n";
    return false;
}




int main() {

    Doctor* d1 = new Doctor("D001", "Dr. Ahmed Mostafa",  "Male",   45, "Cardiology",        true);
    Doctor* d2 = new Doctor("D002", "Dr. Sara El-Sayed",  "Female", 38, "Pediatrics",        false);
    Doctor* d3 = new Doctor("D003", "Dr. Youssef Kamal",  "Male",   50, "Orthopedic Surgery", true);


    Patient* p1 = new Patient("P001", "Omar Yasser",    "Male",   30, "Flu",              "01012345678", false);
    Patient* p2 = new Patient("P002", "Nourhan Adel",   "Female", 25, "Stomach Pain",     "01122334455", true);
    Patient* p3 = new Patient("P003", "Mahmoud Fathy",  "Male",   45, "Diabetes",         "01233445566", false);

    Appointment* a1 = new Appointment("A001", "D001", "P001", "2025-07-01", "10:00 AM");
    Appointment* a2 = new Appointment("A002", "D002", "P002", "2025-07-02", "12:30 PM");
    Appointment* a3 = new Appointment("A003", "D003", "P003", "2025-07-03", "09:00 AM");


    Hospital hospital;
    hospital.setDoctor(d1);
    hospital.setDoctor(d2);
    hospital.setDoctor(d3);

    hospital.setPatient(p1);
    hospital.setPatient(p2);
    hospital.setPatient(p3);

    hospital.setAppointment(a1);
    hospital.setAppointment(a2);
    hospital.setAppointment(a3);


    //  Login System for Admin and Doctor.
    Admin admin("Anas", "1234");
    Doc doc("Khaled", "0123");

    const int maxTries = 3;
    while (true) {
        cout << "+====================================+\n";
        cout << "|              LOGIN PAGE            |\n";
        cout << "+====================================+\n";

        cout << "\n";
        cout << "  [1] Admin Login\n";
        cout << "  [2] Doctor Login\n";

        cout << "\n======================================\n";
        cout << "Enter your choice (1 or 2): ";

        int userInput;
        cin >> userInput;
        if (userInput != 1 && userInput != 2) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number(1 or 2).\n";
            continue;
        }

        if (userInput == 1) {
            if (tryLogin(admin, maxTries)) {
                showAdminMenu(hospital);
                break;
            }
        } else {
            if (tryLogin(doc, maxTries)) {
                showDoctorMenu(hospital);
                break;
            }
        }

    }


return 0;
}