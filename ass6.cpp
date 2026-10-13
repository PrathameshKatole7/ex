#include <iostream>
#include <fstream>
using namespace std;

class employee
{
public:
    int emplyid;
    string emplyname;
    float emplysalary;

    void accept()
    {
        cout << "Enter employee ID: ";
        cin >> emplyid;

        cout << "Enter employee name: ";
        cin >> emplyname;

        cout << "Enter employee salary: ";
        cin >> emplysalary;
    }

    void display()
    {
        cout << "\n*** Employee Details ***" << endl;
        cout << "Employee ID: " << emplyid << endl;
        cout << "Employee Name: " << emplyname << endl;
        cout << "Employee Salary: " << emplysalary << endl;
    }
};

int main()
{
    employee e;
    int n;

    ofstream outfile("employee.dat", ios::binary);

    if (!outfile)
    {
        cout << "Error in opening file";
        return 1;
    }

    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter employee details " << i + 1 << endl;
        e.accept();
        outfile.write((char*)&e, sizeof(e));
    }

    outfile.close();

    ifstream infile("employee.dat", ios::binary);

    if (!infile)
    {
        cout << "Error in opening file";
        return 1;
    }

    while (infile.read((char*)&e, sizeof(e)))
    {
        e.display();
    }

    infile.close();
    return 0;
}
