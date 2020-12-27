#include "MenuController.h"
using namespace std;

int MenuController::menu()
{
    int action;
    string filename;
    while (true) {
        system("cls");
        printf_s("\nWelcome to main menu!\nEnter corresponding number to start actions.\n"
            "1) Enter new data;\n"
            "2) Print data;\n"
            "3) Save data to file;\n"
            "4) Load data from file;\n"
            "5) Find object;\n"
            "6) Exit.\n");
        try {
            cout << "Your action: ";
            cin >> action;
            switch (action) {
            case 1:
                enterNewData();
                break;
            case 2:
                printData();
                break;
            case 3:
                saveFile();
                break;
            case 4:
                loadFile();
                break;
            case 5:
                break;
            case 6:
                return 0;
            default:
                printf_s("\nIncorrect number.");
                system("pause");
            }
        }
        catch (std::exception e) {
            printf_s(e.what());
            system("pause");
        }
    }
    return 0;
}

void MenuController::loadFile()
{
    system("cls");
    printf_s("\nLoading file.\nEnter corresponding number to start actions."
        "\n1) Load from JSON file;"
        "\n2) Load from binary file;"
        "\n*) Enter any number to cancel.\n");
    int action;
    string filename;
    cout << "Enter number: ";
    cin >> action;
    switch (action) {
    case 1:
        cout << "Please enter filename: ";
        cin >> filename;
        loadFromJSONFile(filename);
        break;
    case 2:
        cout << "Please enter filename: ";
        cin >> filename;
        loadFromBinaryFile(filename);
        break;
    default:
        return;
    }
}

void MenuController::saveFile()
{
    system("cls");
    printf_s("\nSaving file.\nEnter corresponding number to start actions."
        "\n1) Save to JSON file;"
        "\n2) Save to binary file;"
        "\n*) Enter any number to cancel.\n");
    int action;
    string filename;
    cout << "Enter number: ";
    cin >> action;
    switch (action) {
    case 1:
        cout << "Please enter filename: ";
        cin >> filename;
        saveToJSONFile(filename);
        break;
    case 2:
        cout << "Please enter filename: ";
        cin >> filename;
        saveToBinaryFile(filename);
        break;
    default:
        return;
    }
}

void MenuController::loadFromBinaryFile(const string& filePath)
{
    fstream fs;
    fs.open(filePath, ios::binary | ios::in);
    if (fs.is_open()) {
        cereal::BinaryInputArchive iarchive(fs);
        iarchive(arr);
        printf_s("\nThe data has been loaded from file %s\n", filePath.c_str());
    }
    else {
        printf_s("\nThe file can't be opened. Check filename\n");
    }
    system("pause");
}

void MenuController::loadFromJSONFile(const string& filePath)
{
    ifstream is;
    is.open(filePath, ios::in);
    if (is.is_open()) {
        cereal::JSONInputArchive iarchive(is);
        iarchive(arr);
        printf_s("\nThe data has been loaded from file %s\n", filePath.c_str());
    }
    else {
        printf_s("\nThe file can't be opened. Check filename\n");
    }
    system("pause");
}

void MenuController::saveToBinaryFile(const string& filePath)
{
    ofstream os;
    os.open(filePath, ios::binary | ios::out);
    if (os.is_open()) {
        cereal::BinaryOutputArchive oarchive(os);
        oarchive(arr);
        printf_s("\nThe data has been saved to file %s\n", filePath.c_str());
    }
    else {
        printf_s("\nThe file can't be opened. Check filename\n");
    }
    system("pause");
}

void MenuController::saveToJSONFile(const string& filePath)
{
    ofstream os;
    os.open(filePath, ios::out | ios::trunc);
    if (os.is_open()) {
        cereal::JSONOutputArchive oarchive(os);
        oarchive(arr);
        printf_s("\nThe data has been saved to file %s\n", filePath.c_str());
    }
    else {
        printf_s("\nThe file can't be opened. Check filename\n");
    }
    system("pause");
}

void MenuController::enterNewData()
{
    string surname, name;
    int b_year = 1, b_month = 1, b_day = 1, o_year = 1, o_month = 1, o_day = 1,
        d_year = 1, d_month = 1, d_day = 1;
    int acc_number;
    double coeff, sum, percent;
    try {
    start:
        system("cls");
        printf_s("\nProvide data to add new Deposit\n");

        cout << "\nEnter deposit's year, month and day one by one: ";
        cin >> d_year;
        cin >> d_month;
        cin >> d_day;
        cout << "\nEnter client's birthday year, month and day one by one: ";
        cin >> b_year;
        cin >> b_month;
        cin >> b_day;
        cout << "\nEnter client's first service year, month and day one by one: ";
        cin >> o_year;
        cin >> o_month;
        cin >> o_day;

        Date birthday(b_year, b_month, b_day);
        Date firstServiceDay(o_year, o_month, o_day);
        Date depositDate(d_year, d_month, d_day);
        if (firstServiceDay - birthday < 0 || depositDate - birthday < 0 || firstServiceDay - depositDate > 0) {
            printf_s("\nYou have entered incorrect dates. Check client's birthday, first service date and deposit date.");
            goto start;
        }
        cout << "\nEnter client's surname: ";
        cin >> surname;
        cout << "\nEnter client's name: ";
        cin >> name;
        cout << "\nEnter deposit increase coefficient: ";
        cin >> coeff;
        enter_num:
        cout << "\nEnter account number: ";
        cin >> acc_number;
        if (acc_number < 0) {
            printf_s("\nYou have entered incorrect account number.");
            goto enter_num;
        }
        enter_sum:
        cout << "\nEnter deposit sum: ";
        cin >> sum;
        if (sum <= 0) {
            printf_s("\nYou have entered incorrect sum.");
            goto enter_sum;
        }
        enter_percent:
        cout << "\nEnter deposit percent: ";
        cin >> percent;
        if (percent < 0 || percent > 100) {
            printf_s("\nYou have entered incorrect deposit percent. \nPercent can't be less than 0 or larger than 100");
            goto enter_percent;
        }
        
        Client tempClient(surname, name, birthday, firstServiceDay, coeff);
        Deposit tempDeposit(tempClient, acc_number, sum, percent);
        
        addNewDeposit(tempDeposit, depositDate);
    }
    catch (std::exception e) {
        printf_s(e.what());
    }
}

void MenuController::addNewDeposit(const Deposit& d, const Date& dt)
{
    if (arr.size() == 0) {
        arr.push_back(WeekdaySummary());
        arr.back().addOperationDay(OperationDay(dt));
        arr.back().addDeposit(d, dt);
    }
    else {
        for (auto it = arr.begin(); it != arr.end(); ++it)
        {
            if (it->operationDayId((OperationDay)dt) >= 0) {
                it->addDeposit(d, dt);
                return;
            }
        }
        arr.push_back(WeekdaySummary());
        arr.back().addOperationDay(OperationDay(dt));
        arr.back().addDeposit(d, dt);
    }
}

void MenuController::printData()
{
    system("cls");
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        printf_s("-------------------------------------------------------------------------------------------------------\n");
        printf_s("|                                      Weekday summary                                                |\n");
        printf_s("-------------------------------------------------------------------------------------------------------\n");
        for (auto day_it = it->getOperationDayVector().begin(); day_it != it->getOperationDayVector().end(); ++day_it)
        {
            printf_s("|                                      Day %2d.%2d.%4d                                                 |\n",
                day_it->getDay(), day_it->getMonth(), day_it->getYear());
            printf_s("-------------------------------------------------------------------------------------------------------\n");
            printf_s("|#  |Surname       |Name        |Birthday   |FSD        |DC     |Account number   |Sum           |DP  |\n");
            printf_s("-------------------------------------------------------------------------------------------------------\n");
            int i = 1;
            for (auto dep_it = day_it->getDepositVector().begin(); dep_it != day_it->getDepositVector().end(); ++dep_it)
            {
                printf_s("|%-2d |%-13s |%-11s |%2d.%2d.%4d |%2d.%2d.%4d |%-6.2f |%-16d |%-13.2f |%3.2f|\n", i, dep_it->getClient().getSurname().c_str(), 
                    dep_it->getClient().getName().c_str(), dep_it->getClient().getBirthday().getDay(),
                    dep_it->getClient().getBirthday().getMonth(), dep_it->getClient().getBirthday().getYear(),
                    dep_it->getClient().getFirstServiceDay().getDay(), dep_it->getClient().getFirstServiceDay().getMonth(),
                    dep_it->getClient().getFirstServiceDay().getYear(), dep_it->getClient().getDepositIncreaseCoefficient(),
                    dep_it->getAccountNumber(), dep_it->getSum(), dep_it->getPercent());
                printf_s("-------------------------------------------------------------------------------------------------------\n");
                ++i;
            }
        }
    }
    system("pause");
}
