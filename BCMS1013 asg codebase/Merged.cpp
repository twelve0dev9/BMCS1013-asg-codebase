#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

//Structures
struct users {
    string name;
    string password;
};
struct servicesStruct {
    string serviceName;
    double price;
};
struct timeSlots {
    double start;
    double end;
    const char* label;
};
struct bookingsStruct {
    int    date;
    string time;
    string service;
    string custName;
    string expertName;
    double price;
};

// Constants
const int EXPERT_COUNT = 2;
const int SERVICE_COUNT = 4;
const int SLOT_COUNT = 6;

// Initial Function Declarations
void clearscreen();

int readIntInRange(int min, int max);

int readAnyInt();

void main_menu(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count);

void customer_menu(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count);

void customer_menu_loggedin(int custIndex,
    users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count);

void customer_view_info();

void customer_view_services_experts(users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT);

void customer_check_availability(users expert[], int EXPERT_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

void customer_view_my_bookings(const string& custName,
    bookingsStruct bookings[], int booking_count);

void customer_book_appointment(int custIndex,
    users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count);

void customer_payment(double amountDue);

void admin_login(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count);

void admin_menu(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count);

void admin_view_individual_expert_schedule(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

void admin_view_overall_schedule(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

void admin_view_customer_list(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

void admin_generate_sales_reports(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

void admin_view_expert_bonus_entitlements(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

void expert_login(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

void expert_menu(int expertIndex,
    users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

void expert_view_personal_schedule(int expertIndex,
    users expert[], int EXPERT_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

void expert_view_assigned_customers(int expertIndex,
    users expert[], int EXPERT_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

void expert_view_earnings_bonus(int expertIndex,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count);

int main() {
    int customer_count = 4;

    users customers[] = {
        {"Leong Kar Ting","123"},
        {"Lavinish","123"},
        {"Lee Yong Shen","123"},
        {"Tay Wei Jing","123"}
    };
    users experts[] = {
        {"Mr. Tan","123"},
        {"Ms. Lee","123"}
    };
    servicesStruct services[] = {
        {"Haircut and Styling",150},
        {"Beard Grooming and Shaving",120},
        {"Facial and Skin Treatment",180},
        {"Consultation",70}
    };
    timeSlots slots[] = {
        {10.00, 11.00, "10AM"},
        {11.00, 12.00, "11AM"},
        {14.00, 15.00, "2PM"},
        {16.00, 17.00, "4PM"},
        {10.00, 13.00, "10AM-1PM"},
        {14.00, 17.00, "2PM-5PM"}
    };

    bookingsStruct bookings[256];
    int booking_count = 36;
    bookings[0] = { 3,"10AM", services[3].serviceName, customers[0].name, experts[0].name, services[3].price };
    bookings[1] = { 3,"11AM", services[0].serviceName, customers[1].name, experts[0].name, services[0].price };
    bookings[2] = { 3,"2PM", services[1].serviceName, customers[2].name, experts[0].name, services[1].price };
    bookings[3] = { 3,"4PM", services[2].serviceName, customers[3].name, experts[0].name, services[2].price };
    bookings[4] = { 3,"10AM-1PM", services[0].serviceName, customers[0].name, experts[0].name, services[0].price };
    bookings[5] = { 3,"2PM-5PM", services[2].serviceName, customers[1].name, experts[0].name, services[2].price };
    bookings[6] = { 10,"10AM", services[3].serviceName, customers[1].name, experts[1].name, services[3].price };
    bookings[7] = { 10,"11AM", services[0].serviceName, customers[2].name, experts[1].name, services[0].price };
    bookings[8] = { 10,"2PM", services[1].serviceName, customers[3].name, experts[1].name, services[1].price };
    bookings[9] = { 10,"4PM", services[2].serviceName, customers[0].name, experts[1].name, services[2].price };
    bookings[10] = { 10,"10AM-1PM", services[0].serviceName, customers[1].name, experts[1].name, services[0].price };
    bookings[11] = { 10,"2PM-5PM",  services[2].serviceName, customers[2].name, experts[1].name, services[2].price };
    bookings[12] = { 1,"10AM", services[3].serviceName, customers[0].name, experts[0].name, services[3].price };
    bookings[13] = { 1,"2PM", services[0].serviceName, customers[3].name, experts[1].name, services[0].price };
    bookings[14] = { 2,"4PM", services[1].serviceName, customers[1].name, experts[0].name, services[1].price };
    bookings[15] = { 4,"11AM", services[2].serviceName, customers[2].name, experts[1].name, services[2].price };
    bookings[16] = { 5,"2PM", services[0].serviceName, customers[0].name, experts[0].name, services[0].price };
    bookings[17] = { 6,"10AM", services[3].serviceName, customers[1].name, experts[1].name, services[3].price };
    bookings[18] = { 7,"11AM", services[2].serviceName, customers[3].name, experts[0].name, services[2].price };
    bookings[19] = { 7,"2PM-5PM", services[0].serviceName, customers[1].name, experts[1].name, services[0].price };
    bookings[20] = { 8,"4PM", services[1].serviceName, customers[2].name, experts[0].name, services[1].price };
    bookings[21] = { 9,"10AM", services[3].serviceName, customers[3].name, experts[1].name, services[3].price };
    bookings[22] = { 12,"10AM-1PM",services[0].serviceName, customers[0].name, experts[0].name, services[0].price };
    bookings[23] = { 13,"2PM-5PM", services[2].serviceName, customers[2].name, experts[1].name, services[2].price };
    bookings[24] = { 14,"11AM", services[1].serviceName, customers[1].name, experts[0].name, services[1].price };
    bookings[25] = { 15,"2PM", services[3].serviceName, customers[3].name, experts[1].name, services[3].price };
    bookings[26] = { 16,"4PM", services[0].serviceName, customers[0].name, experts[0].name, services[0].price };
    bookings[27] = { 17,"10AM", services[2].serviceName, customers[2].name, experts[1].name, services[2].price };
    bookings[28] = { 18,"11AM", services[3].serviceName, customers[1].name, experts[0].name, services[3].price };
    bookings[29] = { 19,"2PM", services[1].serviceName, customers[0].name, experts[1].name, services[1].price };
    bookings[30] = { 20,"4PM", services[0].serviceName, customers[3].name, experts[0].name, services[0].price };
    bookings[31] = { 22,"10AM", services[1].serviceName, customers[2].name, experts[1].name, services[1].price };
    bookings[32] = { 23,"10AM-1PM", services[0].serviceName, customers[0].name, experts[0].name, services[0].price };
    bookings[33] = { 23,"2PM-5PM", services[2].serviceName, customers[1].name, experts[0].name, services[2].price };
    bookings[34] = { 24,"10AM-1PM", services[1].serviceName, customers[2].name, experts[0].name, services[1].price };
    bookings[35] = { 24,"10AM", services[3].serviceName, customers[3].name, experts[1].name, services[3].price };
    main_menu(customers, customer_count, experts, EXPERT_COUNT,
        services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
    return 0;
}

void clearscreen() {
    system("CLS");
}

int readAnyInt() {
    // This function reads input for any integer (used for exiting/back button)
    int x;
    while (!(cin >> x)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter integers only.\n> ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return x;
}
int readIntInRange(int min, int max) {
    // This function reads input and validates it.
    int x;
    bool valid = false;
    do {
        cout << ">";
        if (cin >> x && x >= min && x <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = true;
        }
        else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid. Enter a number in [" << min << ".." << max << "].\n";
        }
    } while (!valid);
    return x;
}

void main_menu(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count) {
    cout << "     MAIN MENU      " << endl;
    cout << "--------------------" << endl;
    cout << "Select Login: " << endl;
    cout << "1. Customer Login" << endl;
    cout << "2. Administrator Login" << endl;
    cout << "3. Expert Login" << endl;
    cout << "4. Exit Program" << endl;
    cout << "-------------------" << endl;
    cout << ">";
    int login_type = readIntInRange(1, 4);
    clearscreen();
    switch (login_type) {
    case 1:
        customer_menu(customer, customer_count, expert, EXPERT_COUNT,
            services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        break;
    case 2:
        admin_login(customer, customer_count, expert, EXPERT_COUNT,
            services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        break;
    case 3:
        expert_login(customer, customer_count, expert, EXPERT_COUNT,
            services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        break;
    case 4:
        cout << " ==== PROGRAM END === \n";
        return;
    }
}

// Logged out Customer Menu
void customer_menu(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count) {
    bool stay = true;
    while (stay) {
        cout << "             CUSTOMER MENU             " << endl;
        cout << "------------------------------------" << endl;
        cout << "1. View Beauty Centre Information\n";
        cout << "2. View Services and Experts\n";
        cout << "3. Check Appointment Availability (December Only)\n";
        cout << "4. Login\n";
        cout << "5. Back to Main Menu\n";
        int choice = readIntInRange(1, 5);
        clearscreen();
        if (choice == 1) {
            customer_view_info();
        }
        else if (choice == 2) {
            customer_view_services_experts(expert, EXPERT_COUNT, services, SERVICE_COUNT);
        }
        else if (choice == 3) {
            customer_check_availability(expert, EXPERT_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        }
        else if (choice == 4) {
            cout << "CUSTOMER LOGIN\n";
            cout << "Username: ";
            string u; getline(cin >> ws, u);
            cout << "Password: ";
            string p; getline(cin, p);
            int idx = -1;
            for (int i = 0; i < customer_count; ++i) if (customer[i].name == u && customer[i].password == p) { idx = i; break; }
            clearscreen();
            if (idx == -1) {
                cout << "Invalid username or password.\n\n";
            }
            else {
                stay = false;
                cout << "Welcome, " << customer[idx].name << "!\n\n";
                customer_menu_loggedin(idx, customer, customer_count, expert, EXPERT_COUNT,
                    services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
            }
        }
        else if (choice == 5) {
            stay = false;
            main_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        }
    }
}

// Logged in Customer Menu
void customer_menu_loggedin(int custIndex,
    users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count) {
    bool stay = true;
    while (stay) {
        stay = true;
        cout << "             CUSTOMER MENU             " << endl;
        cout << "------------------------------------" << endl;
        cout << "User: " << customer[custIndex].name << endl;
        cout << "1. View Beauty Centre Information\n";
        cout << "2. View Services and Experts\n";
        cout << "3. Check Appointment Availability (December Only)\n";
        cout << "4. Book Appointments\n";
        cout << "5. View My Bookings\n";
        cout << "6. Logout\n";
        int c = readIntInRange(1, 6);
        clearscreen();
        if (c == 1) {
            customer_view_info();
        }
        else if (c == 2) {
            customer_view_services_experts(expert, EXPERT_COUNT, services, SERVICE_COUNT);
        }
        else if (c == 3) {
            customer_check_availability(expert, EXPERT_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        }
        else if (c == 4) {
            customer_book_appointment(custIndex, customer, customer_count, expert, EXPERT_COUNT,
                services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        }
        else if (c == 5) {
            customer_view_my_bookings(customer[custIndex].name, bookings, booking_count);
        }
        else if (c == 6) {
            main_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
            stay = false;
        }
        if (stay) {
            cout << "\n(Press ENTER to continue)";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearscreen();
        }
    }
}

// View Beauty Centre Information
void customer_view_info() {
    cout << "Where Style Meets Self-Care." << endl;
    cout << "IU Men’s Beauty Centre: Styling, Haircuts, Skin Treatments." << endl;
    cout << "Operating hours: 12PM to 1AM (Mon to Sat)" << endl;
    cout << "Email: iumenbeauty@gmail.com | Phone: 012 345 6789" << endl << endl;
}

// Displas all services and experts available
void customer_view_services_experts(users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT) {
    cout << "Services Offered:\n";
    for (int i = 0; i < SERVICE_COUNT; ++i) {
        cout << "  " << (i + 1) << ". " << services[i].serviceName
            << " (RM" << fixed << setprecision(2) << services[i].price << ")\n";
    }
    cout << "\nExperts:\n";
    for (int i = 0; i < EXPERT_COUNT; ++i) {
        cout << "  - " << expert[i].name << "\n";
    }
    cout << "\n";
}

static bool slot_conflict(const bookingsStruct& b, const string& expertName, int date, const string& timelabel) {
    return (b.expertName == expertName && b.date == date && b.time == timelabel);
}

void customer_check_availability(users expert[], int EXPERT_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {
    cout << "Check Appointment Availability (December)\n\n";
    cout << "Pick Expert:\n";
    for (int i = 0; i < EXPERT_COUNT; ++i) cout << "  " << (i + 1) << ". " << expert[i].name << "\n";
    int eidx = readIntInRange(1, EXPERT_COUNT) - 1;
    clearscreen();
    int bookingsPerDay[32] = { 0 };
    int dayUsage[32] = { 0 };
    for (int d = 1; d <= 31; ++d) {
        int used = 0;
        for (int i = 0; i < booking_count; ++i)
            if (bookings[i].expertName == expert[eidx].name && bookings[i].date == d) ++used;
        bookingsPerDay[d] = used;
    }
    cout << expert[eidx].name << " availability (December):\n";
    cout << "Days with capacity remaining are shown as numbers; fully booked days are [XX].\n\n";
    int rowBreak = 0;
    for (int d = 1; d <= 31; ++d) {
        bool full = (bookingsPerDay[d] >= SLOT_COUNT);
        if (full) cout << "[ " << setw(2) << d << " ] ";
        else      cout << "  " << setw(2) << d << "   ";
        if (++rowBreak == 7) { cout << "\n"; rowBreak = 0; }
    }
    cout << "\n";
}

void customer_view_my_bookings(const string& custName,
    bookingsStruct bookings[], int booking_count) {
    cout << left;
    cout << setw(5) << "No." << setw(8) << "Date" << setw(8) << "Time"
        << setw(30) << "Service" << setw(18) << "Expert" << "\n";
    cout << "---------------------------------------------------------------\n";
    int n = 0;
    for (int i = 0; i < booking_count; ++i) {
        if (bookings[i].custName == custName) {
            cout << setw(5) << (++n)
                << setw(8) << bookings[i].date
                << setw(8) << bookings[i].time
                << setw(30) << bookings[i].service
                << setw(18) << bookings[i].expertName << "\n";
        }
    }
    if (n == 0) cout << "(no bookings)\n";
}

void customer_book_appointment(int custIndex,
    users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count) {
    cout << "Select Service:\n";
    for (int i = 0; i < SERVICE_COUNT; ++i) {
        cout << "  " << (i + 1) << ". " << services[i].serviceName << " (RM" << fixed << setprecision(2) << services[i].price << ")\n";
    }
    int sidx = readIntInRange(1, SERVICE_COUNT) - 1;
    cout << "Select Expert:\n";
    for (int i = 0; i < EXPERT_COUNT; ++i) {
        cout << "  " << (i + 1) << ". " << expert[i].name << "\n";
    }
    int eidx = readIntInRange(1, EXPERT_COUNT) - 1;
    while (true) {
        cout << "Pick date in December (1..31):\n";
        int d = readIntInRange(1, 31);
        int freeMap[64];
        int freeCount = 0;
        for (int i = 0; i < SLOT_COUNT; ++i) {
            bool free = true;
            for (int k = 0; k < booking_count; ++k) {
                if (bookings[k].expertName == expert[eidx].name &&
                    bookings[k].date == d &&
                    bookings[k].time == slots[i].label) {
                    free = false;
                    break;
                }
            }
            if (free) {
                freeMap[freeCount++] = i;
            }
        }
        if (freeCount == 0) {
            cout << "\nAll time slots for " << expert[eidx].name << " on Dec " << d << " are fully booked.\n";
            cout << "1. Pick another date\n";
            cout << "2. Back\n";
            int act = readIntInRange(1, 2);
            if (act == 2) {
                return;
            }
            else {
                clearscreen();
                continue;
            }
        }
        cout << "\nAvailable time slots on Dec " << d << ":\n";
        for (int i = 0; i < freeCount; ++i) {
            cout << "  " << (i + 1) << ". " << slots[freeMap[i]].label << "\n";
        }
        cout << "  0. Back\n";
        int choice = readIntInRange(0, freeCount);
        if (choice == 0) {
            clearscreen();
            continue;
        }
        int tidx = freeMap[choice - 1];
        if (booking_count < 256) {
            bookings[booking_count++] = {
                d,
                slots[tidx].label,
                services[sidx].serviceName,
                customer[custIndex].name,
                expert[eidx].name,
                services[sidx].price
            };
            cout << fixed << setprecision(2);
            cout << "\nAppointment booked for " << customer[custIndex].name
                << " on Dec " << d << " at " << slots[tidx].label
                << " with " << expert[eidx].name << ".\n";
            cout << "Service: " << services[sidx].serviceName
                << " | Amount Due: RM" << services[sidx].price << "\n";
            customer_payment(services[sidx].price);
            return;
        }
        else {
            cout << "Schedule is at full capacity; cannot add more bookings.\n";
            return;
        }
    }
}

void customer_payment(double amountDue) {
    cout << endl;
    cout << "Amount Due: " << amountDue << endl;
    cout << endl;
    cout << "Select payment method:" << endl;
    cout << "1. Cash (Exact amount only)" << endl;
    cout << "2. Card" << endl;
    cout << "3. Online Banking" << endl;
    cout << "4. E-Wallet (Scan QR)" << endl;
    int method = readIntInRange(1, 4);
    clearscreen();
    cout << fixed << setprecision(2);
    if (method == 1) {
        cout << "CASH PAYMENT\n";
        cout << "Please insert EXACT cash: RM" << amountDue << "\n";
        while (true) {
            double paid = 0.0;
            cout << "Cash Inserted (RM): ";
            if (!(cin >> paid)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid amount. Try again.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (paid == amountDue) {
                cout << "Cash accepted.\n";
                break;
            }
            else {
                cout << "Exact amount only. Required: RM" << amountDue << ". Try again.\n";
            }
        }
    }
    else if (method == 2) {
        cout << "CARD PAYMENT\n";
        string cardLast4, expiry, cvv;
        cout << "Enter last 4 digits: "; getline(cin >> ws, cardLast4);
        cout << "Enter expiry (MM/YY): "; getline(cin, expiry);
        cout << "Enter CVV: "; getline(cin, cvv);

        while (true) {
            double toCharge = 0.0;
            cout << "Enter amount to charge (RM): ";
            if (!(cin >> toCharge)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid amount. Try again.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (toCharge == amountDue) {
                cout << "Card charged RM" << amountDue << " successfully.\n";
                break;
            }
            else {
                cout << "Amount must match RM" << amountDue << " exactly.\n";
            }
        }
    }
    else if (method == 3) {
        cout << "ONLINE BANKING\n";
        cout << "Select bank:\n";
        cout << "  1. Maybank\n  2. CIMB\n  3. RHB\n  4. Public Bank\n  5. Hong Leong\n";
        readIntInRange(1, 5);
        cout << "Redirecting to FPX demo...\n";
        while (true) {
            double transferred = 0.0;
            cout << "Enter transfer amount (RM): ";
            if (!(cin >> transferred)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid amount. Try again.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (transferred == amountDue) {
                cout << "Transfer of RM" << amountDue << " confirmed.\n";
                break;
            }
            else {
                cout << "Amount must be exactly RM" << amountDue << ".\n";
            }
        }
        cout << "FPX reference recorded.\n";
    }
    else if (method == 4) {
        cout << "E-WALLET (Scan to Pay)\n";
        cout << "+-------------------------------+\n";
        cout << "| █████           █████        |\n";
        cout << "| █   █           █   █        |\n";
        cout << "| █ █ █           █ █ █        |\n";
        cout << "| █   █           █   █        |\n";
        cout << "| █████           █████        |\n";
        cout << "|                               |\n";
        cout << "| ██  ███  ██  ███  ██  ███    |\n";
        cout << "| █ █  █  █ █   █  █ █  █      |\n";
        cout << "| ██   █  ███  █   ██   ███    |\n";
        cout << "|                               |\n";
        cout << "| █████                         |\n";
        cout << "| █   █                         |\n";
        cout << "| █ █ █                         |\n";
        cout << "| █   █                         |\n";
        cout << "| █████                         |\n";
        cout << "+-------------------------------+\n";
        cout << "Scan the QR above with your e-wallet app.\n";
        while (true) {
            double paid = 0.0;
            cout << "Enter amount paid (RM): ";
            if (!(cin >> paid)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid amount. Try again.\n";
                continue;
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (paid == amountDue) {
                string ref;
                cout << "Enter e-wallet reference ID: ";
                getline(cin >> ws, ref);
                cout << "E-wallet payment RM" << amountDue << " received. Ref: " << ref << "\n";
                break;
            }
            else {
                cout << "Amount must be exactly RM" << amountDue << ". Try again.\n";
            }
        }
    }
    string paymentMethod;
    switch (method) {
    case 1: paymentMethod = "Cash";
    case 2: paymentMethod = "Card";
    case 3: paymentMethod = "Online Banking";
    case 4: paymentMethod = "E-Wallet";
    }
    cout << "\n+==================== RECEIPT ====================+\n";
    cout << "| Status         : PAID                           |\n";
    cout << "| Method         : " << paymentMethod << "\n";
    cout << "| Amount Due     : RM" << fixed << setprecision(2) << amountDue << "\n";
    cout << "| Amount Paid    : RM" << fixed << setprecision(2) << amountDue << "\n";
    cout << "+=================================================+\n";
}

// Admin Login
void admin_login(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count) {
    string username, password;
    string admin_user = "ansel", admin_pass = "iu123";
    cout << "             ADMIN LOGIN             " << endl << "";
    cout << "------------------------------------" << endl << "";
    cout << "Enter username : ";
    getline(cin >> ws, username);
    cout << "Enter password : ";
    getline(cin, password);
    clearscreen();
    if (username != admin_user || password != admin_pass) {
        cout << "Invalid username or password." << endl << "Returning to main menu" << endl << "" << endl << "";
        main_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        return;
    }
    cout << "" << endl << "Admin Login Successful" << endl << "Welcome, " << username << "." << endl << "" << endl << "";
    admin_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
}

// Admin Menu
void admin_menu(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int& booking_count) {
    cout << "             ADMIN MENU             " << endl;
    cout << "------------------------------------" << endl;
    cout << "1. View Individual Expert Schedule" << endl;
    cout << "2. View Overall Schedule          " << endl;
    cout << "3. View Customer List             " << endl;
    cout << "4. Generate Sales Reports         " << endl;
    cout << "5. View Expert Bonus Entitlements " << endl;
    cout << "6. Logout                         " << endl;
    cout << "------------------------------------" << endl;
    int choice = readIntInRange(1, 6);
    clearscreen();
    switch (choice) {
    case 1:
        admin_view_individual_expert_schedule(customer, customer_count, expert, EXPERT_COUNT,
            services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        break;
    case 2:
        admin_view_overall_schedule(customer, customer_count, expert, EXPERT_COUNT,
            services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        break;
    case 3:
        admin_view_customer_list(customer, customer_count, expert, EXPERT_COUNT,
            services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        break;
    case 4:
        admin_generate_sales_reports(customer, customer_count, expert, EXPERT_COUNT,
            services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        break;
    case 5:
        admin_view_expert_bonus_entitlements(customer, customer_count, expert, EXPERT_COUNT,
            services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        break;
    case 6:
        main_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        return;
    }
}

// Asks for which week (each week is Mon-Sun 1st week has less days because the month does not start on Monday and week 5
// also has less days because because the month does not end on Sunday, then asks for which expert, then displays that specific expert's schedule.
void admin_view_individual_expert_schedule(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {
    cout << "Booking is only available for December 2025." << endl;
    cout << "Week 1 : 1st to 6th" << endl;
    cout << "Week 2 : 7th to 13th" << endl;
    cout << "Week 3 : 14th to 20th" << endl;
    cout << "Week 4 : 21st to 27th" << endl;
    cout << "Week 5 : 28th to 31st" << endl;
    cout << "Select Week (1-5) : ";
    int week = readIntInRange(1, 5);
    cout << "" << endl << "1. " << expert[0].name << "" << endl << "2. " << expert[1].name << "" << endl << "Select Expert : ";
    int selectExpert = readIntInRange(1, EXPERT_COUNT);
    clearscreen();
    int startDate = 0, endDate = 0;
    switch (week) {
    case 1:
        startDate = 1;
        endDate = 6;
        break;
    case 2:
        startDate = 7;
        endDate = 13;
        break;
    case 3:
        startDate = 14;
        endDate = 20;
        break;
    case 4:
        startDate = 21;
        endDate = 27;
        break;
    case 5:
        startDate = 28;
        endDate = 31;
        break;
    }
    cout << "Viewing Expert Schedules - Week " << week << "" << endl << "" << endl << "";
    cout << "Selected Expert: " << expert[selectExpert - 1].name << "" << endl << "" << endl << "";
    cout << left;
    cout << setw(5) << "No." << setw(8) << "Date" << setw(8) << "Time" << setw(30) << "Service" << setw(15) << "Customer" << "" << endl << "";
    cout << "------------------------------------------------------------------------------------" << endl << "";
    int count = 0;
    for (int i = 0; i < booking_count; ++i) {
        if (bookings[i].expertName == expert[selectExpert - 1].name &&
            bookings[i].date >= startDate && bookings[i].date <= endDate) {
            cout << setw(5) << (count + 1) << setw(8) << bookings[i].date << setw(8) << bookings[i].time
                << setw(30) << bookings[i].service << setw(15) << bookings[i].custName << "" << endl << "";
            ++count;
        }
    }
    cout << "" << endl << "Total Records: " << count << "" << endl << "";
    cout << "Total Hours this Week: " << count * 3 << "hrs" << endl << "";
    cout << "Enter any integer to exit: ";
    readAnyInt();
    clearscreen();
    admin_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
}

// Displays the overall schedule of all experts/customers, along with a sorting option, sorting by date or customer name (A-Z).
void admin_view_overall_schedule(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {
    cout << "Sort Options:" << endl;
    cout << "1. Sort by Date (asc)" << endl;
    cout << "2. Sort by Customer Name (A-Z)" << endl;
    int sortChoice = readIntInRange(1, 2);

    int order[256];
    for (int i = 0; i < booking_count; ++i) order[i] = i;

    if (sortChoice == 1) {
        for (int i = 0; i < booking_count - 1; ++i) {
            for (int j = 0; j < booking_count - 1 - i; ++j) {
                const bookingsStruct& a = bookings[order[j]];
                const bookingsStruct& b = bookings[order[j + 1]];
                if (a.date > b.date || (a.date == b.date && a.time > b.time)) {
                    int t = order[j]; order[j] = order[j + 1]; order[j + 1] = t;
                }
            }
        }
    }
    else {
        for (int i = 0; i < booking_count - 1; ++i) {
            for (int j = 0; j < booking_count - 1 - i; ++j) {
                const bookingsStruct& a = bookings[order[j]];
                const bookingsStruct& b = bookings[order[j + 1]];
                if (a.custName > b.custName) {
                    int t = order[j]; order[j] = order[j + 1]; order[j + 1] = t;
                }
            }
        }
    }

    cout << left;
    cout << setw(5) << "No." << setw(8) << "Date" << setw(10) << "Time"
        << setw(30) << "Service" << setw(18) << "Customer" << setw(18) << "Assigned Expert" << "\n";
    cout << "------------------------------------------------------------------------------------\n";
    for (int i = 0; i < booking_count; ++i) {
        int idx = order[i];
        cout << setw(5) << (i + 1)
            << setw(8) << bookings[idx].date
            << setw(10) << bookings[idx].time
            << setw(30) << bookings[idx].service
            << setw(18) << bookings[idx].custName
            << setw(18) << bookings[idx].expertName << "\n";
    }
    cout << "------------------------------------------------------------------------------------\n";
    cout << "Total records: " << booking_count << "\n\n";
    cout << "Enter any integer to exit: ";
    readAnyInt();
    clearscreen();
    admin_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
}

// Displays all customers and all their different bookings
void admin_view_customer_list(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {
    cout << "All Registered Customers: " << endl << "";
    cout << "-------------------------------------------------------------------------------------------------------------" << endl << "";
    cout << left;
    cout << setw(5) << "No." << " | " << setw(20) << "Name" << " | " << setw(30) << "Service Booked" << " | "
        << setw(20) << "Assigned Expert" << " | " << setw(10) << "Date" << " | " << setw(10) << "Time" << "" << endl << "";
    cout << "-------------------------------------------------------------------------------------------------------------" << endl << "";
    for (int i = 0; i < booking_count; ++i) {
        cout << setw(5) << (i + 1) << " | " << setw(20) << bookings[i].custName << " | " << setw(30) << bookings[i].service
            << " | " << setw(20) << bookings[i].expertName << " | " << setw(10) << bookings[i].date
            << " | " << setw(10) << bookings[i].time << "" << endl << "";
    }
    cout << "-------------------------------------------------------------------------------------------------------------" << endl << "";
    cout << "Total records: " << booking_count << "" << endl << "";
    cout << "Enter any integer to exit: ";
    readAnyInt();
    clearscreen();
    admin_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
}

// Generates a sales report for December 2025.
void admin_generate_sales_reports(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {
    struct CountPrice { int count; int price; };
    CountPrice cp[4] = {
        {0, (int)services[0].price},
        {0, (int)services[1].price},
        {0, (int)services[2].price},
        {0, (int)services[3].price}
    };
    for (int i = 0; i < booking_count; ++i) {
        if (bookings[i].service == services[0].serviceName) ++cp[0].count;
        else if (bookings[i].service == services[1].serviceName) ++cp[1].count;
        else if (bookings[i].service == services[2].serviceName) ++cp[2].count;
        else if (bookings[i].service == services[3].serviceName) ++cp[3].count;
    }
    int total[4] = {
        cp[0].count * cp[0].price,
        cp[1].count * cp[1].price,
        cp[2].count * cp[2].price,
        cp[3].count * cp[3].price
    };
    cout << "Sales  Report - December 2025" << endl << "" << endl << "";
    cout << left;
    cout << setw(30) << "Service Type" << setw(18) << "Total Bookings" << setw(18) << "Unit Price (RM)" << setw(20) << "Total Sales (RM)" << "" << endl << "";
    cout << "-------------------------------------------------------------------------------------------" << endl << "";
    cout << setw(30) << services[0].serviceName << setw(18) << cp[0].count << setw(18) << cp[0].price << setw(20) << total[0] << "" << endl << "";
    cout << setw(30) << services[1].serviceName << setw(18) << cp[1].count << setw(18) << cp[1].price << setw(20) << total[1] << "" << endl << "";
    cout << setw(30) << services[2].serviceName << setw(18) << cp[2].count << setw(18) << cp[2].price << setw(20) << total[2] << "" << endl << "";
    cout << setw(30) << services[3].serviceName << setw(18) << cp[3].count << setw(18) << cp[3].price << setw(20) << total[3] << "" << endl << "";
    cout << "-------------------------------------------------------------------------------------------" << endl << "";
    cout << "Total Revenue: RM" << (total[0] + total[1] + total[2] + total[3]) << "" << endl << "" << endl << "";
    cout << "Enter any integer to exit: ";
    readAnyInt();
    clearscreen();
    admin_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
}

// Displays each expert's earnings and bonus entitlements.
void admin_view_expert_bonus_entitlements(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {
    struct bonusRow { string expertName; int hours; int servicevalue; double bonusPct; };
    bonusRow rows[2] = { {expert[0].name,0,0,0.0}, {expert[1].name,0,0,0.0} };
    for (int i = 0; i < booking_count; ++i) {
        int k = (bookings[i].expertName == expert[0].name) ? 0 : (bookings[i].expertName == expert[1].name) ? 1 : -1;
        if (k == -1) {
            continue;
        }
        int hours = 0;
        for (int j = 0; j < SLOT_COUNT; ++j) {
            if (bookings[i].time == slots[j].label) {
                double dur = (slots[j].end - slots[j].start);
                hours = (int)(dur + 0.5);
                break;
            }
        }
        rows[k].hours += hours;
        rows[k].servicevalue += (int)bookings[i].price;
    }
    for (int i = 0; i < 2; ++i) {
        if (rows[i].hours >= 30) {
            rows[i].bonusPct = 0.50;
        }
        else if (rows[i].hours >= 25) {
            rows[i].bonusPct = 0.25;
        }
        else {
            rows[i].bonusPct = 0.0;
        }
    }
    cout << "Expert Bonus Report - December 2025" << endl << "" << endl << "";
    cout << left;
    cout << setw(12) << "Expert" << " | " << setw(15) << "Total Hours" << " | " << setw(17) << "Service Value" << " | "
        << setw(13) << "Bonus %" << " | " << setw(12) << "Bonus (RM)" << "" << endl << "";
    cout << "---------------------------------------------------------------------------------------" << endl << "";
    for (int i = 0; i < 2; ++i) {
        cout << setw(12) << rows[i].expertName << " | " << setw(15) << rows[i].hours << " | "
            << "RM" << setw(15) << rows[i].servicevalue << " | "
            << setw(12) << (int)(rows[i].bonusPct * 100) << "%" << " | "
            << setw(12) << "RM" << (int)(rows[i].bonusPct * rows[i].servicevalue) << "" << endl << "";
    }
    cout << "" << endl << "Enter any integer to exit: ";
    readAnyInt();
    clearscreen();
    admin_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
}

void expert_login(users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {
    cout << "EXPERT LOGIN\n";
    cout << "Username: ";
    string u; getline(cin >> ws, u);
    cout << "Password: ";
    string p; getline(cin, p);
    int idx = -1;
    for (int i = 0; i < EXPERT_COUNT; ++i) if (expert[i].name == u && expert[i].password == p) { idx = i; break; }
    clearscreen();
    if (idx == -1) {
        cout << "Invalid username or password. Returning to main menu.\n\n";
        main_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
        return;
    }
    expert_menu(idx, customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
}

void expert_menu(int expertIndex,
    users customer[], int customer_count,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {
    bool inMenu = true;
    while (inMenu) {
        cout << endl;
        cout << "--------------------------" << endl;
        cout << "Welcome " << expert[expertIndex].name << endl;
        cout << "--------------------------" << endl;
        cout << "1. View Personal Schedule" << endl;
        cout << "2. View Assigned Customers" << endl;
        cout << "3. View Earnings & Bonus" << endl;
        cout << "4. Logout" << endl;
        cout << "Enter your choice: ";

        int choice = readIntInRange(1, 4);
        clearscreen();

        switch (choice) {
        case 1:
            expert_view_personal_schedule(expertIndex, expert, EXPERT_COUNT, slots, SLOT_COUNT, bookings, booking_count);
            break;
        case 2:
            expert_view_assigned_customers(expertIndex, expert, EXPERT_COUNT, slots, SLOT_COUNT, bookings, booking_count);
            break;
        case 3:
            expert_view_earnings_bonus(expertIndex, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
            break;
        case 4:
            cout << "Logging out..." << endl;
            inMenu = false;
            main_menu(customer, customer_count, expert, EXPERT_COUNT, services, SERVICE_COUNT, slots, SLOT_COUNT, bookings, booking_count);
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

        if (inMenu) {
            cout << "\n(Press ENTER to continue)";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            clearscreen();
        }
    }
}

void expert_view_personal_schedule(int expertIndex,
    users expert[], int EXPERT_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {

    string expertName = expert[expertIndex].name;

    bool submenu = true;
    while (submenu) {
        cout << "\nPersonal Schedule Options for " << expertName << ":\n";
        cout << "1. View full schedule\n";
        cout << "2. Search schedule\n";
        cout << "3. Return to menu\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\nFull Personal Schedule:\n";
            cout << "+----+------+------------+------------+---------------------+-----------------------------+\n";
            cout << "| No | Date | Start Time | End Time   | Customer            | Service                     |\n";
            cout << "+----+------+------------+------------+---------------------+-----------------------------+\n";

            bool hasBookings = false;
            int ccounter = 1;
            for (int i = 0; i < booking_count; i++) {
                if (bookings[i].expertName == expertName) {
                    hasBookings = true;

                    // Convert time label to start/end times
                    double startTime = 0.0, endTime = 0.0;
                    for (int j = 0; j < SLOT_COUNT; j++) {
                        if (bookings[i].time == slots[j].label) {
                            startTime = slots[j].start;
                            endTime = slots[j].end;
                            break;
                        }
                    }

                    cout << left
                        << "| " << setw(2) << ccounter++ << " | "
                        << setw(4) << bookings[i].date << " | "
                        << setw(10) << fixed << setprecision(2) << startTime << " | "
                        << setw(10) << fixed << setprecision(2) << endTime << " | "
                        << setw(19) << bookings[i].custName << " | "
                        << setw(27) << bookings[i].service << " |\n";
                }
            }

            if (!hasBookings) {
                cout << "| " << setw(66) << "No appointments scheduled." << " |\n";
            }
            cout << "+----+------+------------+------------+---------------------+-----------------------------+\n";
        }
        else if (choice == 2) {
            string searchTerm;
            cout << "Enter search term (service type or customer name): ";
            getline(cin, searchTerm);

            cout << "\nSearch Results:\n";
            cout << "+----+------+------------+------------+---------------------+-----------------------------+\n";
            cout << "| No | Date | Start Time | End Time   | Customer            | Service                     |\n";
            cout << "+----+------+------------+------------+---------------------+-----------------------------+\n";

            bool found = false;
            int counter = 1;
            for (int i = 0; i < booking_count; i++) {
                if (bookings[i].expertName == expertName &&
                    (bookings[i].service.find(searchTerm) != string::npos ||
                        bookings[i].custName.find(searchTerm) != string::npos)) {

                    found = true;

                    // Convert time label to start/end times
                    double startTime = 0.0, endTime = 0.0;
                    for (int j = 0; j < SLOT_COUNT; j++) {
                        if (bookings[i].time == slots[j].label) {
                            startTime = slots[j].start;
                            endTime = slots[j].end;
                            break;
                        }
                    }

                    cout << left
                        << "| " << setw(2) << counter++ << " | "
                        << setw(4) << bookings[i].date << " | "
                        << setw(10) << fixed << setprecision(2) << startTime << " | "
                        << setw(10) << fixed << setprecision(2) << endTime << " | "
                        << setw(19) << bookings[i].custName << " | "
                        << setw(27) << bookings[i].service << " |\n";
                }
            }

            if (!found) {
                cout << "| " << setw(66) << "No matching appointments found." << " |\n";
            }
            cout << "+----+------+------------+------------+---------------------+-----------------------------+\n";
        }
        else if (choice == 3) {
            submenu = false;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
}

void expert_view_assigned_customers(int expertIndex,
    users expert[], int EXPERT_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {

    string expertName = expert[expertIndex].name;

    bool submenu = true;
    while (submenu) {
        cout << "\nAssigned Customers Options for " << expertName << ":\n";
        cout << "1. View all assigned customers\n";
        cout << "2. Search assigned customers\n";
        cout << "3. Return to menu\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "\nALL ASSIGNED CUSTOMERS:\n";
            cout << "+----+---------------------+-----------------------------+------------+------------+------+\n";
            cout << "| No | Customer            | Service                     | Start Time | End Time   | Date |\n";
            cout << "+----+---------------------+-----------------------------+------------+------------+------+\n";

            bool hasCustomers = false;
            int ccounter = 1;
            for (int i = 0; i < booking_count; i++) {
                if (bookings[i].expertName == expertName) {
                    hasCustomers = true;

                    // Convert time label to start/end times
                    double startTime = 0.0, endTime = 0.0;
                    for (int j = 0; j < SLOT_COUNT; j++) {
                        if (bookings[i].time == slots[j].label) {
                            startTime = slots[j].start;
                            endTime = slots[j].end;
                            break;
                        }
                    }

                    cout << left
                        << "| " << setw(2) << ccounter++ << " | "
                        << setw(19) << bookings[i].custName << " | "
                        << setw(27) << bookings[i].service << " | "
                        << setw(10) << fixed << setprecision(2) << startTime << " | "
                        << setw(10) << fixed << setprecision(2) << endTime << " | "
                        << setw(4) << bookings[i].date << " |\n";
                }
            }

            if (!hasCustomers) {
                cout << "| " << setw(90) << "No customers assigned." << " |\n";
            }
            cout << "+----+---------------------+-----------------------------+------------+------------+------+\n";
        }
        else if (choice == 2) {
            string searchTerm;
            cout << "Enter search term (service type or customer name): ";
            getline(cin, searchTerm);

            cout << "\nSEARCH RESULTS:\n";
            cout << "+----+---------------------+-----------------------------+------------+------------+------+\n";
            cout << "| No | Customer            | Service                     | Start Time | End Time   | Date |\n";
            cout << "+----+---------------------+-----------------------------+------------+------------+------+\n";

            bool found = false;
            int counter = 1;
            for (int i = 0; i < booking_count; i++) {
                if (bookings[i].expertName == expertName &&
                    (bookings[i].service.find(searchTerm) != string::npos ||
                        bookings[i].custName.find(searchTerm) != string::npos)) {

                    found = true;

                    // Convert time label to start/end times
                    double startTime = 0.0, endTime = 0.0;
                    for (int j = 0; j < SLOT_COUNT; j++) {
                        if (bookings[i].time == slots[j].label) {
                            startTime = slots[j].start;
                            endTime = slots[j].end;
                            break;
                        }
                    }

                    cout << left
                        << "| " << setw(2) << counter++ << " | "
                        << setw(19) << bookings[i].custName << " | "
                        << setw(27) << bookings[i].service << " | "
                        << setw(10) << fixed << setprecision(2) << startTime << " | "
                        << setw(10) << fixed << setprecision(2) << endTime << " | "
                        << setw(4) << bookings[i].date << " |\n";
                }
            }

            if (!found) {
                cout << "| " << setw(90) << "No matches found." << " |\n";
            }
            cout << "+----+---------------------+-----------------------------+------------+------------+------+\n";
        }
        else if (choice == 3) {
            submenu = false;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
}

void expert_view_earnings_bonus(int expertIndex,
    users expert[], int EXPERT_COUNT,
    servicesStruct services[], int SERVICE_COUNT,
    timeSlots slots[], int SLOT_COUNT,
    bookingsStruct bookings[], int booking_count) {

    string expertName = expert[expertIndex].name;

    double totalTreatmentHours = 0.0;
    double totalConsultationHours = 0.0;
    double totalServiceValue = 0.0;
    int bookingCount = 0;

    // Calculate hours and service value
    for (int i = 0; i < booking_count; i++) {
        if (bookings[i].expertName == expertName) {
            double hours = 0.0;

            // Calculate hours based on time slot
            for (int j = 0; j < SLOT_COUNT; j++) {
                if (bookings[i].time == slots[j].label) {
                    hours = slots[j].end - slots[j].start;
                    break;
                }
            }

            double serviceValue = bookings[i].price;
            totalServiceValue += serviceValue;

            // Check if it's consultation or treatment
            if (bookings[i].service == "Consultation") {
                totalConsultationHours += hours;
            }
            else {
                totalTreatmentHours += hours;
            }

            bookingCount++;
        }
    }

    double totalCombinedHours = totalTreatmentHours + totalConsultationHours;

    // Calculate bonus based on rules
    double bonusPercentage = 0.0;
    double bonusAmount = 0.0;

    if (totalCombinedHours >= 30.0) {
        bonusPercentage = 50.0;
    }
    else if (totalCombinedHours >= 25.0) {
        bonusPercentage = 25.0;
    }
    else {
        bonusPercentage = 0.0;
    }

    bonusAmount = totalServiceValue * (bonusPercentage / 100.0);

    // Display earnings report
    cout << "\nEARNINGS & BONUS REPORT for " << expertName << ":\n";
    cout << "+-------------------------------+--------------------------------+\n";
    cout << "| Metric                        | Value                          |\n";
    cout << "+-------------------------------+--------------------------------+\n";
    cout << left
        << "| " << setw(30) << "Total Treatment Hours"
        << "| " << setw(31) << fixed << setprecision(2) << totalTreatmentHours << "|\n"
        << "| " << setw(30) << "Total Consultation Hours"
        << "| " << setw(31) << fixed << setprecision(2) << totalConsultationHours << "|\n"
        << "| " << setw(30) << "Total Combined Hours"
        << "| " << setw(31) << fixed << setprecision(2) << totalCombinedHours << "|\n"
        << "| " << setw(30) << "Total Service Value"
        << "| RM " << setw(28) << fixed << setprecision(2) << totalServiceValue << "|\n"
        << "| " << setw(30) << "Bonus Percentage (%)"
        << "| " << setw(31) << fixed << setprecision(1) << bonusPercentage << "|\n"
        << "| " << setw(30) << "Bonus Amount"
        << "| RM " << setw(28) << fixed << setprecision(2) << bonusAmount << "|\n";
    cout << "+-------------------------------+--------------------------------+\n";

    // Display bonus eligibility message
    if (bonusPercentage > 0.0) {
        cout << "| Congratulations! You earned a " << bonusPercentage << "% bonus for working "
            << totalCombinedHours << " hours this month. |\n";
    }
    else if (totalCombinedHours > 0.0) {
        cout << "| You need at least 25 hours to qualify for a bonus. Keep going! |\n";
    }
    else {
        cout << "| No bookings completed this month. |\n";
    }
    cout << "+-------------------------------+--------------------------------+\n";
}
