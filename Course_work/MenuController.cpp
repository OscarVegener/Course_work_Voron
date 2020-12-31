#include "MenuController.h"
using namespace std;

int MenuController::menu()
{
    int action;
    string tmp;
    while (true) {
        system("cls");
        printf_s("\nWelcome to main menu!\nEnter corresponding number to start actions.\n"
            "1) Enter new data;\n"
            "2) Print data;\n"
            "3) Save data to file;\n"
            "4) Load data from file;\n"
            "5) Find object;\n"
            "6) Mean value of deposit operations\n"
            "7) Mean value of deposit sums\n"
            "8) Exit.\n");
        try {
            cout << "Your action: ";
            cin >> tmp;
            action = stoi(tmp);
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
                find();
                break;
            case 6:
                meanOperations();
                break;
            case 7:
                meanSum();
                break;
            case 8:
                return 0;
            default:
                printf_s("\nIncorrect number.\n");
                system("pause");
            }
        }
        catch (std::exception e) {
            printf_s(e.what());
            printf_s("\n");
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
    string surname, name, temp;
    int b_year = 1, b_month = 1, b_day = 1, o_year = 1, o_month = 1, o_day = 1,
        d_year = 1, d_month = 1, d_day = 1;
    int acc_number;
    double coeff, sum, percent;
    try {
    start:
        system("cls");
        printf_s("\nProvide data to add new Deposit\n");

        cout << "\nEnter deposit's year, month and day one by one: ";
        cin >> temp;
        d_year = stoi(temp);
        cin >> temp;
        d_month = stoi(temp);
        cin >> temp;
        d_day = stoi(temp);
        cout << "\nEnter client's birthday year, month and day one by one: ";
        cin >> temp;
        b_year = stoi(temp);
        cin >> temp;
        b_month = stoi(temp);
        cin >> temp;
        b_day = stoi(temp);
        cout << "\nEnter client's first service year, month and day one by one: ";
        cin >> temp;
        o_year = stoi(temp);
        cin >> temp;
        o_month = stoi(temp);
        cin >> temp;
        o_day = stoi(temp);

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
        cin >> temp;
        coeff = stof(temp);
        enter_num:
        cout << "\nEnter account number: ";
        cin >> temp;
        acc_number = stoi(temp);
        if (acc_number < 0) {
            printf_s("\nYou have entered incorrect account number.");
            goto enter_num;
        }
        enter_sum:
        cout << "\nEnter deposit sum: ";
        cin >> temp;
        sum = stof(temp);
        if (sum <= 0) {
            printf_s("\nYou have entered incorrect sum.");
            goto enter_sum;
        }
        enter_percent:
        cout << "\nEnter deposit percent: ";
        cin >> temp;
        percent = stof(temp);
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

void MenuController::meanSum()
{
    system("cls");
    if (arr.empty()) {
        printf_s("\nNo information to display.\n");
        system("pause");
        return;
    }
    printf_s("\nMean sum\n");
    for (auto it = arr.begin(); it != arr.end() ; ++it)
    {
        printf_s("-------------------------------------------------------------------------------------------------------\n");
        printf_s("|                                      Weekday %2d.%2d.%4d - %2d.%2d.%4d                                |\n",
            it->getOperationDayVector().begin()->getDay(), it->getOperationDayVector().begin()->getMonth(),
            it->getOperationDayVector().begin()->getYear(), it->getOperationDayVector().back().getDay(),
            it->getOperationDayVector().back().getMonth(), it->getOperationDayVector().back().getYear());
        printf_s("-------------------------------------------------------------------------------------------------------\n");
        printf_s("|Mean deposit sum per day: %13.2f                                                              |\n", it->getAverageDepositSumPerDay());
        printf_s("-------------------------------------------------------------------------------------------------------\n");
    }
    system("pause");
}

void MenuController::meanOperations()
{
    system("cls");
    if (arr.empty()) {
        printf_s("\nNo information to display.\n");
        system("pause");
        return;
    }
    system("cls");
    printf_s("\nMean operations\n");
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        printf_s("-------------------------------------------------------------------------------------------------------\n");
        printf_s("|                                      Weekday %2d.%2d.%4d - %2d.%2d.%4d                                |\n",
            it->getOperationDayVector().begin()->getDay(), it->getOperationDayVector().begin()->getMonth(),
            it->getOperationDayVector().begin()->getYear(), it->getOperationDayVector().back().getDay(),
            it->getOperationDayVector().back().getMonth(), it->getOperationDayVector().back().getYear());
        printf_s("-------------------------------------------------------------------------------------------------------\n");
        printf_s("|Mean deposit operations per day: %5f                                                            |\n", it->getAverageOperationsPerDay());
        printf_s("-------------------------------------------------------------------------------------------------------\n");
    }
    system("pause");
}

void MenuController::find()
{
    system("cls");
    printf_s("\nFind client\n");
    printf_s("Please enter information about any of client's deposits below.\n");
    string temp;
    int acc_number;
    double sum, percent;
    try {
        cout << "Enter deposit account number: ";
        cin >> temp;
        acc_number = stof(temp);
        cout << "Enter deposit sum: ";
        cin >> temp;
        sum = stof(temp);
        cout << "Enter deposit percent: ";
        cin >> temp;
        percent = stof(temp);
        system("cls");
        printf_s("\nPossible clients\n");
        for (auto it = arr.begin(); it != arr.end(); ++it)
        {
            for (auto day_it = it->getOperationDayVector().begin(); day_it != it->getOperationDayVector().end(); ++day_it)
            {
                for (auto dep_it = day_it->getDepositVector().begin(); dep_it != day_it->getDepositVector().end(); ++dep_it)
                {
                    if (dep_it->getAccountNumber() == acc_number && (dep_it->getSum() - sum < 0.0001) && (dep_it->getPercent() - percent < 0.0001)) {
                        Client tmp_client = dep_it->getClient();
                        printf_s("%s %s %2d.%2d.%4d %2d.%2d.%4d %f\n", tmp_client.getSurname().c_str(), tmp_client.getName().c_str(),
                            tmp_client.getBirthday().getDay(), tmp_client.getBirthday().getMonth(),
                            tmp_client.getBirthday().getYear(), tmp_client.getFirstServiceDay().getDay(),
                            tmp_client.getFirstServiceDay().getMonth(), tmp_client.getFirstServiceDay().getYear(),
                            tmp_client.getDepositIncreaseCoefficient());
                    }
                }
            }
        }
    }
    catch (std::exception e) {
        printf_s("\n%s\n", e.what());
        system("pause");
    }
    system("pause");
}
