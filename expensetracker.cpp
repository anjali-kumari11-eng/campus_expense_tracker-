#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct Expense {
    string category;
    float amount;
};

// Save expenses to file
void saveToFile(vector<Expense>& expenses) {
    ofstream file("expenses.txt");
    for (auto &e : expenses) {
        file << e.category << " " << e.amount << endl;
    }
    file.close();
}

// Load expenses from file
void loadFromFile(vector<Expense>& expenses) {
    ifstream file("expenses.txt");
    Expense e;
    while (file >> e.category >> e.amount) {
        expenses.push_back(e);
    }
    file.close();
}

int main() {
    vector<Expense> expenses;
    loadFromFile(expenses);

    float budget;
    cout << "Enter your monthly budget: ";
    cin >> budget;

    int choice;
    while (true) {
        cout << "\n===== Advanced Expense Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Total Spending\n";
        cout << "4. Category-wise Analysis\n";
        cout << "5. Budget Status\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Expense e;
            cout << "Enter category (Food/Gym/Travel/etc): ";
            cin >> e.category;
            cout << "Enter amount: ";
            cin >> e.amount;

            expenses.push_back(e);
            saveToFile(expenses);

            cout << "Expense added & saved!\n";
        }

        else if (choice == 2) {
            cout << "\n--- All Expenses ---\n";
            for (int i = 0; i < expenses.size(); i++) {
                cout << i + 1 << ". " << expenses[i].category
                     << " - Rs. " << expenses[i].amount << endl;
            }
        }

        else if (choice == 3) {
            float total = 0;
            for (auto &e : expenses) total += e.amount;

            cout << "Total Spending: Rs. " << total << endl;
        }

        else if (choice == 4) {
            float food = 0, gym = 0, travel = 0, other = 0;

            for (auto &e : expenses) {
                if (e.category == "Food") food += e.amount;
                else if (e.category == "Gym") gym += e.amount;
                else if (e.category == "Travel") travel += e.amount;
                else other += e.amount;
            }

            cout << "\n--- Category-wise Analysis ---\n";
            cout << "Food: Rs. " << food << endl;
            cout << "Gym: Rs. " << gym << endl;
            cout << "Travel: Rs. " << travel << endl;
            cout << "Other: Rs. " << other << endl;
        }

        else if (choice == 5) {
            float total = 0;
            for (auto &e : expenses) total += e.amount;

            cout << "Budget: Rs. " << budget << endl;
            cout << "Spent: Rs. " << total << endl;

            if (total > budget) {
                cout << " You exceeded your budget!\n";
            } else {
                cout << " You are within budget.\n";
            }
        }

        else if (choice == 6) {
            cout << "Saving & Exiting...\n";
            saveToFile(expenses);
            break;
        }

        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}