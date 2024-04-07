#include "../include/Menu.h"
#include<iostream>
#include <codecvt>
#include <iomanip>

void Menu::open() {
    loadedFiles.readCities();
    loadedFiles.readPipes();
    loadedFiles.readReservoirs();
    loadedFiles.readStations();

    while(true){
        if(!displayMainMenu()){
            break;
        }
    }
}

bool Menu:: displayMainMenu()
{
    cout << char(218)<< string(2, char(196)) << " Water Supply Management System " << string(2, char(196)) << char(191) << endl;
    cout << "|                                    |\n";
    cout << "|       1. Reservoir Functions       |\n";
    cout << "|        2. Station Functions        |\n";
    cout << "|          3. City Functions         |\n";
    cout << "|          4. Pipe Functions         |\n";
    cout << "|  5. Determine Maximum Water Flow   |\n";
    cout << "|        6. Verify Water Needs       |\n";
    cout << "|           7. Balance Load          |\n";
    cout << "|       8. Resilience Analysis       |\n";
    cout << "|    9. Pipeline Failure Analysis    |\n";
    cout << "|             10. Exit               |\n";
    cout << "|                                    |\n";
    cout << char(192) << string(36, char(196)) << char(217) << endl;

    string choice;
    cout<<"Enter your choice: ";
    cin >> choice;

    cout << "\n";

    // Display the menu based on the prompt from the user

    try{
        switch (stoi(choice)) {
            case 1:
                reservoirFunctions();
                break;

            case 2:
                stationFunctions();
                break;

            case 3:
                cityFunctions();
                break;

            case 4:
                pipeFunctions();
                break;

            case 5:
                determineMaxWaterFlow();
                break;

            case 6:
                verifyWaterNeeds();
                break;

            case 7:
                balanceLoad();
                break;

            case 8:
                resilienceAnalysis();
                break;

            case 9:
                pipelineFailureAnalysis();
                break;

            case 10:
                cout<<"Exiting program. Goodbye!"<<endl;
                return false;

            default:
                cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    catch (invalid_argument){
        cout << "Invalid Choice. Please try Again" << endl;
    }

    return true;
}


/* ======================== RESERVOIRS ===================================*/

void Menu::reservoirFunctions() {
    cout << char(218)<< string(12, char(196)) << " Reservoir Functions " << string(13, char(196)) << char(191) << endl;
    cout << "|                                              |\n";
    cout << "|            1. Print All Reservoirs           |\n";
    cout << "|            2. Find Reservoirs by Id          |\n";
    cout << "|       3. Find Reservoirs by Municipality     |\n";
    cout << "|    4. Get Reservoir with Max & Min Delivery  |\n";
    cout << "|             5. Return to Main Menu           |\n";
    cout << "|                                              |\n";
    cout << char(192) << string(46, char(196)) << char(217) << endl;

    string choice;
    cout<<"Enter your choice: ";
    cin>>choice;

    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                printReservoirs();
                break;

            case 2:
                findReservoirsById();
                break;

            case 3:
                findReservoirsByMunicipality();
                break;

            case 4:
                getReservoirMaxMinDelivery();
                break;

            case 5:
                displayMainMenu();
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;

        }
    }
    catch (invalid_argument){
                cout << "Invalid Choice. Please try Again" << endl;
    }
}

void Menu::printReservoirs() {
    cout << char(218)<< string(31, char(196)) << " Reservoirs " << string(30, char(196)) << char(191) << endl;
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|  Reservoir        |  Municipality      |  Id  |  Code  |  Max Delivery  |\n";
    cout << "|                                                                         |\n";

    vector<Reservoir> reservoirs = loadedFiles.getReservoirsVector();

    for (auto res: reservoirs) {
        cout << std::left;
        cout << "|  " << setw(15) << res.getReservoirName() << "  |  ";
        cout << setw(16) << res.getMunicipality() << "  |  ";
        cout << setw(2) << res.getReservoirId() << "  |  ";
        cout << setw(4) <<  res.getReservoirCode() << "  |  ";
        cout << setw(12) << res.getMaxDelivery() << "  |  " << endl;
    }
    cout << "|                                                                         |\n";
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|                         1. Reservoirs Functions                         |\n";
    cout << "|                              2. Main Menu                               |\n";
    cout << char(192) << string(73, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try{
        switch (stoi(choice)) {
            case 1:
                reservoirFunctions();
                break;
            case 2:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }
}

void Menu::findReservoirsById() {
    string id;
    vector<Reservoir> reservoirs = loadedFiles.getReservoirsVector();
    int vectorSize = reservoirs.size();
    cout << char(218)<< string(21, char(196)) << " Reservoir By ID " << string(20, char(196)) << char(191) << endl;
    cout << "| Enter a Reservoir ID. This value ranges between 1 and " << vectorSize << " |\n";
    cout << char(192) << string(58, char(196)) << char(217) << endl;

    cin >> id;

    if(stoi(id) < 1 || stoi(id)>vectorSize){
        cout << "Invalid choice. Please try again." << endl;
        cout << endl;
        findReservoirsById();
    }

    cout << endl;

    Reservoir chosenID;

    for (auto res: reservoirs){
        if(res.getReservoirId() == stoi(id)){
            chosenID = res;
        }
    }

    cout << char(218)<< string(31, char(196)) << " Reservoirs " << string(30, char(196)) << char(191) << endl;
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|  Reservoir        |  Municipality      |  Id  |  Code  |  Max Delivery  |\n";
    cout << "|                                                                         |\n";
    cout << std::left;
    cout << "|  " << setw(15) << chosenID.getReservoirName() << "  |  "
         << setw(16) << chosenID.getMunicipality() << "  |  "
         << setw(2) << chosenID.getReservoirId() << "  |  "
         << setw(4) <<  chosenID.getReservoirCode() << "  |  "
         << setw(12) << chosenID.getMaxDelivery() << "  |  " << endl;

    cout << "|                                                                         |\n";
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|                         1. Reservoirs Functions                         |\n";
    cout << "|                            2. Try Another ID                            |\n";
    cout << "|                              3. Main Menu                               |\n";
    cout << char(192) << string(73, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";
    try{
        switch (stoi(choice)) {
            case 1:
                reservoirFunctions();
                break;

            case 2:
                findReservoirsById();
                break;

            case 3:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }

}

void Menu::findReservoirsByMunicipality() {
    string municipality;
    vector<Reservoir> reservoirs = loadedFiles.getReservoirsVector();
    int vectorSize = reservoirs.size();
    cout << char(218)<< string(5, char(196)) << " Reservoir By Municipality " << string(5, char(196)) << char(191) << endl;
    cout << "| Enter a Reservoir Municipality Name |\n";
    cout << char(192) << string(37, char(196)) << char(217) << endl;

    cin >> municipality;
    cout << endl;

    vector <Reservoir> chosenMunicipality;
    bool foundMunicipality = false;                      // check if municipality has been found or not

    // Avoid Case Sensitive issues
    std::transform(municipality.begin(), municipality.end(), municipality.begin(),
                   [](unsigned char c){ return tolower(c); });

    municipality[0] = toupper(municipality[0]);


    for (auto res: reservoirs){
        if(res.getMunicipality() == municipality){
            chosenMunicipality.push_back(res);
            foundMunicipality = true;
        }
    }

    if(foundMunicipality == false){
        cout << char(218)<< string(12, char(196)) << " Reservoir By Municipality " << string(11, char(196)) << char(191) << endl;
        cout << "| There's no Reservoir with that Municipality Name |" << endl;
        cout << char(192) << string(50, char(196)) << char(217) << endl;
        cout << "|             Want to try another name?            |\n";
        cout << "|                       1. Yes                     |\n";
        cout << "|                       2. No                      |\n";
        cout << char(192) << string(50, char(196)) << char(217) << endl;

        string choice;
        cin >> choice;

        if(stoi(choice) == 1){
            cout << endl;
            findReservoirsByMunicipality();
        }
        else if (stoi(choice) == 2){
            cout << endl;
            reservoirFunctions();
        }
        else{
            cout<<"Invalid choice. Returning you to Reservoir Functions...."<<endl;
            reservoirFunctions();
        }
    }

    cout << char(218)<< string(31, char(196)) << " Reservoirs " << string(30, char(196)) << char(191) << endl;
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|  Reservoir        |  Municipality      |  Id  |  Code  |  Max Delivery  |\n";
    cout << "|                                                                         |\n";
    for(auto r : chosenMunicipality){
        cout << std::left;
        cout << "|  " << setw(15) << r.getReservoirName() << "  |  "
             << setw(16) << r.getMunicipality() << "  |  "
             << setw(2) << r.getReservoirId() << "  |  "
             << setw(4) <<  r.getReservoirCode() << "  |  "
             << setw(12) << r.getMaxDelivery() << "  |  " << endl;
    }
    cout << "|                                                                         |\n";
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|                         1. Reservoirs Functions                         |\n";
    cout << "|                       2. Try Another Municipality                       |\n";
    cout << "|                              3. Main Menu                               |\n";
    cout << char(192) << string(73, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";
    try{
        switch (stoi(choice)) {
            case 1:
                reservoirFunctions();
                break;
            case 2:
                findReservoirsByMunicipality();
                break;

            case 3:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }

}

void Menu::getReservoirMaxMinDelivery() {
    vector <Reservoir> reservoirs = loadedFiles.getReservoirsVector();
    Reservoir highest;
    Reservoir lowest;

    int maxDel = INT_MIN;
    int minDel = INT_MAX;

    for (auto r: reservoirs){
        if(r.getMaxDelivery()>maxDel){
            highest = r;
            maxDel = highest.getMaxDelivery();
        }
        if(r.getMaxDelivery()<minDel){
            lowest = r;
            minDel = lowest.getMaxDelivery();
        }
    }

    cout << char(218)<< string(26, char(196)) << " Reservoirs Delivery " << string(26, char(196)) << char(191) << endl;
    cout << "|                                                                         |\n";
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|                    Reservoir with Highest Delivery                      |\n";
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|  Reservoir        |  Municipality      |  Id  |  Code  |  Max Delivery  |\n";
    cout << "|                                                                         |\n";
    cout << std::left;
    cout << "|  " << setw(15) << highest.getReservoirName() << "  |  "
         << setw(16) << highest.getMunicipality() << "  |  "
         << setw(2) << highest.getReservoirId() << "  |  "
         << setw(4) <<  highest.getReservoirCode() << "  |  "
         << setw(12) << highest.getMaxDelivery() << "  |  " << endl;
    cout << "|                                                                         |\n";
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|                     Reservoir with Lowest Delivery                      |\n";
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|  Reservoir        |  Municipality      |  Id  |  Code  |  Max Delivery  |\n";
    cout << "|                                                                         |\n";
    cout << std::left;
    cout << "|  " << setw(15) << lowest.getReservoirName() << "  |  "
         << setw(16) << lowest.getMunicipality() << "  |  "
         << setw(2) << lowest.getReservoirId() << "  |  "
         << setw(4) <<  lowest.getReservoirCode() << "  |  "
         << setw(12) << lowest.getMaxDelivery() << "  |  " << endl;
    cout << "|                                                                         |\n";
    cout << "|" << string(73, char(196)) << "|" << endl;
    cout << "|                         1. Reservoirs Functions                         |\n";
    cout << "|                              2. Main Menu                               |\n";
    cout << char(192) << string(73, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";
    try{
        switch (stoi(choice)) {
            case 1:
                reservoirFunctions();
                break;

            case 2:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }
}

/* ======================== STATIONS ===================================*/

void Menu::stationFunctions() {
    cout << char(218)<< string(13, char(196)) << " Station Functions " << string(14, char(196)) << char(191) << endl;
    cout << "|                                              |\n";
    cout << "|             1. Print All Stations            |\n";
    cout << "|             2. Find Stations by Id           |\n";
    cout << "|             3. Return to Main Menu           |\n";
    cout << "|                                              |\n";
    cout << char(192) << string(46, char(196)) << char(217) << endl;

    string choice;
    cout<<"Enter your choice: ";
    cin>>choice;

    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                printStations();
                break;

            case 2:
                findStationsById();
                break;

            case 3:
                displayMainMenu();
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;

        }
    }
    catch (invalid_argument){
        cout << "Invalid Choice. Please try Again" << endl;
    }
}

void Menu::printStations() {
    cout << char(218)<< string(8, char(196)) << " Stations " << string(9, char(196)) << char(191) << endl;
    cout << "|" << string(27, char(196)) << "|" << endl;
    cout << "|     Id     |     Code     |\n";
    cout << "|                           |\n";

    vector<Station> stations = loadedFiles.getStationsVector();

    for (auto stat: stations) {
        cout << std::left;
        cout << "|     " << setw(2) << stat.getStationId() << "     |     ";
        cout << setw(4) <<  stat.getStationCode() << "     |     " << endl;
    }
    cout << "|                            |\n";
    cout << "|" << string(28, char(196)) << "|" << endl;
    cout << "|     1. Station Functions   |\n";
    cout << "|         2. Main Menu       |\n";
    cout << char(192) << string(28, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try{
        switch (stoi(choice)) {
            case 1:
                stationFunctions();
                break;
            case 2:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }
}

void Menu::findStationsById() {
    string id;
    vector<Station> stations = loadedFiles.getStationsVector();
    int vectorSize = stations.size();
    cout << char(218)<< string(20, char(196)) << " Station By ID " << string(21, char(196)) << char(191) << endl;
    cout << "| Enter a Station ID. This value ranges between 1 and " << vectorSize << " |\n";
    cout << char(192) << string(56, char(196)) << char(217) << endl;

    cin >> id;

    if(stoi(id) < 1 || stoi(id)>vectorSize){
        cout << "Invalid choice. Please try again." << endl;
        cout << endl;
        findStationsById();
    }

    cout << endl;

    Station chosenID;

    for (auto stat: stations){
        if(stat.getStationId() == stoi(id)){
            chosenID = stat;
        }
    }
    cout << char(218)<< string(9, char(196)) << " Stations " << string(9, char(196)) << char(191) << endl;
    cout << "|" << string(28, char(196)) << "|" << endl;
    cout << "|      Id     |     Code     |\n";
    cout << "|                            |\n";
    cout << std::left;
    cout << "|      " << setw(2) << chosenID.getStationId() << "     |     ";
    cout << setw(4) <<  chosenID.getStationCode() << "    |" << endl;

    cout << "|                            |\n";
    cout << "|" << string(28, char(196)) << "|" << endl;
    cout << "|    1. Station Functions    |\n";
    cout << "|       2. Main Menu         |\n";
    cout << char(192) << string(28, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";
    try{
        switch (stoi(choice)) {
            case 1:
                reservoirFunctions();
                break;

            case 2:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }

}

/* ======================== CITIES ===================================*/

void Menu::cityFunctions() {
    cout << char(218)<< string(16, char(196)) << " City Functions " << string(14, char(196)) << char(191) << endl;
    cout << "|                                              |\n";
    cout << "|              1. Print All Cities             |\n";
    cout << "|              2. Find Cities by Id            |\n";
    cout << "|       3. Get City with Max & Min Demand      |\n";
    cout << "|     4. Get City with Max & Min Population    |\n";
    cout << "|             5. Return to Main Menu           |\n";
    cout << "|                                              |\n";
    cout << char(192) << string(46, char(196)) << char(217) << endl;

    string choice;
    cout<<"Enter your choice: ";
    cin>>choice;

    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                printCities();
                break;

            case 2:
                findCityById();
                break;

            case 3:
                getCityMaxMinDemand();
                break;

            case 4:
                getCityMaxMinPopulation();
                break;

            case 5:
                displayMainMenu();
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;

        }
    }
    catch (invalid_argument){
        cout << "Invalid Choice. Please try Again" << endl;
    }
}

void Menu::printCities(){
    cout << char(218)<< string(27, char(196)) << " Cities " << string(27, char(196)) << char(191) << endl;
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|  Station           |  Id  |  Code  |  Demand  |  Population  |\n";
    cout << "|                                                              |\n";

    vector<City> cities = loadedFiles.getCitiesVector();

    for (auto city: cities) {
        cout << std::left;
        cout << "|  " << setw(16) << city.getCity() << "  |  ";
        cout << setw(2) << city.getCityId() << "  |  ";
        cout << setw(4) <<  city.getCityCode() << "  |  ";
        cout << setw(6) << city.getDemand() << "  |  ";
        cout << setw(10) << city.getPopulation() << "  |" << endl;
    }
    cout << "|                                                              |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|                      1. City Functions                       |\n";
    cout << "|                        2. Main Menu                          |\n";
    cout << char(192) << string(62, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try{
        switch (stoi(choice)) {
            case 1:
                cityFunctions();
                break;
            case 2:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }
}

void Menu::findCityById(){
    string id;
    vector<City> cities = loadedFiles.getCitiesVector();
    int vectorSize = cities.size();
    cout << char(218)<< string(21, char(196)) << " City By ID " << string(20, char(196)) << char(191) << endl;
    cout << "| Enter a City ID. This value ranges between 1 and " << vectorSize << " |\n";
    cout << char(192) << string(53, char(196)) << char(217) << endl;

    cin >> id;

    if(stoi(id) < 1 || stoi(id)>vectorSize){
        cout << "Invalid choice. Please try again." << endl;
        cout << endl;
        findCityById();
    }

    cout << endl;

    City chosenID;

    for (auto city: cities){
        if(city.getCityId() == stoi(id)){
            chosenID = city;
        }
    }

    cout << char(218)<< string(27, char(196)) << " Cities " << string(27, char(196)) << char(191) << endl;
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|  Station           |  Id  |  Code  |  Demand  |  Population  |\n";
    cout << "|                                                              |\n";

    cout << std::left;
    cout << "|  " << setw(16) << chosenID.getCity() << "  |  ";
    cout << setw(2) << chosenID.getCityId() << "  |  ";
    cout << setw(4) <<  chosenID.getCityCode() << "  |  ";
    cout << setw(6) << chosenID.getDemand() << "  |  ";
    cout << setw(10) << chosenID.getPopulation() << "  |" << endl;

    cout << "|                                                              |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|                      1. City Functions                       |\n";
    cout << "|                      2. Try Another ID                       |\n";
    cout << "|                        3. Main Menu                          |\n";
    cout << char(192) << string(62, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try{
        switch (stoi(choice)) {
            case 1:
                cityFunctions();
                break;
            case 2:
                findCityById();
                break;

            case 3:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }
}

void Menu::getCityMaxMinDemand() {
    vector <City> cities = loadedFiles.getCitiesVector();
    City highest;
    City lowest;

    int maxDel = INT_MIN;
    int minDel = INT_MAX;

    for (auto city: cities){
        if(city.getDemand()>maxDel){
            highest = city;
            maxDel = highest.getDemand();
        }
        if(city.getDemand()<minDel){
            lowest = city;
            minDel = lowest.getDemand();
        }
    }

    cout << char(218)<< string(23, char(196)) << " Cities Demand " << string(24, char(196)) << char(191) << endl;
    cout << "|                                                              |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|                    City with Highest Demand                  |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|  Station           |  Id  |  Code  |  Demand  |  Population  |\n";
    cout << "|                                                              |\n";
    cout << std::left;
    cout << "|  " << setw(16) << highest.getCity() << "  |  ";
    cout << setw(2) << highest.getCityId() << "  |  ";
    cout << setw(4) <<  highest.getCityCode() << "  |  ";
    cout << setw(6) << highest.getDemand() << "  |  ";
    cout << setw(10) << highest.getPopulation() << "  |" << endl;

    cout << "|                                                              |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|                    City with Lowest Demand                   |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|  Station           |  Id  |  Code  |  Demand  |  Population  |\n";
    cout << "|                                                              |\n";
    cout << std::left;
    cout << "|  " << setw(16) << lowest.getCity() << "  |  ";
    cout << setw(2) << lowest.getCityId() << "  |  ";
    cout << setw(4) <<  lowest.getCityCode() << "  |  ";
    cout << setw(6) << lowest.getDemand() << "  |  ";
    cout << setw(10) << lowest.getPopulation() << "  |" << endl;

    cout << "|                                                              |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|                      1. City Functions                       |\n";
    cout << "|                        2. Main Menu                          |\n";
    cout << char(192) << string(62, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";
    try{
        switch (stoi(choice)) {
            case 1:
                cityFunctions();
                break;

            case 2:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }
}

void Menu::getCityMaxMinPopulation(){
    vector <City> cities = loadedFiles.getCitiesVector();
    City highest;
    City lowest;

    int maxDel = INT_MIN;
    int minDel = INT_MAX;

    for (auto city: cities){
        if(city.getPopulation()>maxDel){
            highest = city;
            maxDel = highest.getPopulation();
        }
        if(city.getPopulation()<minDel){
            lowest = city;
            minDel = lowest.getPopulation();
        }
    }

    cout << char(218)<< string(21, char(196)) << " Cities Population " << string(22, char(196)) << char(191) << endl;
    cout << "|                                                              |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|                  City with Highest Population                |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|  Station           |  Id  |  Code  |  Demand  |  Population  |\n";
    cout << "|                                                              |\n";
    cout << std::left;
    cout << "|  " << setw(16) << highest.getCity() << "  |  ";
    cout << setw(2) << highest.getCityId() << "  |  ";
    cout << setw(4) <<  highest.getCityCode() << "  |  ";
    cout << setw(6) << highest.getDemand() << "  |  ";
    cout << setw(10) << highest.getPopulation() << "  |" << endl;

    cout << "|                                                              |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|                   City with Lowest Population                |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|  Station           |  Id  |  Code  |  Demand  |  Population  |\n";
    cout << "|                                                              |\n";
    cout << std::left;
    cout << "|  " << setw(16) << lowest.getCity() << "  |  ";
    cout << setw(2) << lowest.getCityId() << "  |  ";
    cout << setw(4) <<  lowest.getCityCode() << "  |  ";
    cout << setw(6) << lowest.getDemand() << "  |  ";
    cout << setw(10) << lowest.getPopulation() << "  |" << endl;

    cout << "|                                                              |\n";
    cout << "|" << string(62, char(196)) << "|" << endl;
    cout << "|                      1. City Functions                       |\n";
    cout << "|                        2. Main Menu                          |\n";
    cout << char(192) << string(62, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";
    try{
        switch (stoi(choice)) {
            case 1:
                cityFunctions();
                break;

            case 2:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }
}

/* ======================== PIPES ===================================*/

void Menu::pipeFunctions() {
    cout << char(218)<< string(15, char(196)) << " Pipes Functions " << string(14, char(196)) << char(191) << endl;
    cout << "|                                              |\n";
    cout << "|              1. Print All Pipes              |\n";
    cout << "|     2. Get Pipe with Max & Min Capacity      |\n";
    cout << "|             3. Return to Main Menu           |\n";
    cout << "|                                              |\n";
    cout << char(192) << string(46, char(196)) << char(217) << endl;

    string choice;
    cout<<"Enter your choice: ";
    cin>>choice;

    cout << "\n";

    try {
        switch (stoi(choice)) {
            case 1:
                printPipes();
                break;

            case 2:
                getPipesMaxMinCapacity();
                break;

            case 3:
                displayMainMenu();
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;

        }
    }
    catch (invalid_argument){
        cout << "Invalid Choice. Please try Again" << endl;
    }
}

void Menu::printPipes(){
    cout << char(218)<< string(25, char(196)) << " Pipes " << string(24, char(196)) << char(191) << endl;
    cout << "|" << string(56, char(196)) << "|" << endl;
    cout << "|  S. Point A  |  S. Point B  |  Capacity  |  Direction  |\n";
    cout << "|                                                        |\n";
    vector<Pipe> pipes = loadedFiles.getPipesVector();

    for (auto pipe: pipes) {
        cout << std::left;
        cout << "|  " << setw(10) << pipe.getPointA() << "  |  ";
        cout << setw(10) <<  pipe.getPointB() << "  |  ";
        cout << setw(8) << pipe.getCapacity() << "  |  ";
        cout << setw(9) << pipe.getDirection() << "  |" << endl;
    }
    cout << "|                                                        |\n";
    cout << "|" << string(56, char(196)) << "|" << endl;
    cout << "|                 1. Pipe Functions                      |\n";
    cout << "|                    2. Main Menu                        |\n";
    cout << char(192) << string(56, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";

    try{
        switch (stoi(choice)) {
            case 1:
                pipeFunctions();
                break;
            case 2:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }
}

void Menu::getPipesMaxMinCapacity(){
    vector <Pipe> pipes = loadedFiles.getPipesVector();
    Pipe highest;
    Pipe lowest;

    int maxDel = INT_MIN;
    int minDel = INT_MAX;

    for (auto pipe: pipes){
        if(pipe.getCapacity()>maxDel){
            highest = pipe;
            maxDel = highest.getCapacity();
        }
        if(pipe.getCapacity()<minDel){
            lowest = pipe;
            minDel = lowest.getCapacity();
        }
    }

    cout << char(218)<< string(20, char(196)) << " Pipes Capacity " << string(20, char(196)) << char(191) << endl;
    cout << "|                                                        |\n";
    cout << "|" << string(56, char(196)) << "|" << endl;
    cout << "|                Pipe with Highest Capacity              |\n";
    cout << "|" << string(56, char(196)) << "|" << endl;
    cout << "|  S. Point A  |  S. Point B  |  Capacity  |  Direction  |\n";
    cout << "|                                                        |\n";

    cout << std::left;
    cout << "|  " << setw(10) << highest.getPointA() << "  |  ";
    cout << setw(10) <<  highest.getPointB() << "  |  ";
    cout << setw(8) << highest.getCapacity() << "  |  ";
    cout << setw(9) << highest.getDirection() << "  |" << endl;

    cout << "|                                                        |\n";
    cout << "|" << string(56, char(196)) << "|" << endl;
    cout << "|                 Pipe with Lowest Capacity              |\n";
    cout << "|" << string(56, char(196)) << "|" << endl;
    cout << "|  S. Point A  |  S. Point B  |  Capacity  |  Direction  |\n";
    cout << "|                                                        |\n";
    cout << std::left;
    cout << "|  " << setw(10) << lowest.getPointA() << "  |  ";
    cout << setw(10) <<  lowest.getPointB() << "  |  ";
    cout << setw(8) << lowest.getCapacity() << "  |  ";
    cout << setw(9) << lowest.getDirection() << "  |" << endl;

    cout << "|                                                        |\n";
    cout << "|" << string(56, char(196)) << "|" << endl;
    cout << "|                 1. Pipe Functions                      |\n";
    cout << "|                    2. Main Menu                        |\n";
    cout << char(192) << string(56, char(196)) << char(217) << endl;

    string choice;
    cin >> choice;
    cout << "\n";
    try{
        switch (stoi(choice)) {
            case 1:
                pipeFunctions();
                break;

            case 2:
                displayMainMenu();
                break;

            default:
                cout<<"Invalid choice. Please try again."<<endl;

        }
    }
    catch (invalid_argument) {
        cout<<"Invalid choice. Please try again."<<endl;
    }
}

/* ======================== OTHERS ===================================*/

void Menu:: determineMaxWaterFlow()
{
    Graph *g = loadedFiles.getGraph();

    vector <Pipe> pipes = loadedFiles.getPipesVector();
    vector <Reservoir> reservoir = loadedFiles.getReservoirsVector();
    vector <Station> stations = loadedFiles.getStationsVector();
    vector <City> cities = loadedFiles.getCitiesVector();
    int vectorSize = cities.size();

    cout << char(218)<< string(17, char(196)) << " Max Water Ammount " << string(17, char(196)) << char(191) << endl;
    cout << "| Enter a City ID. This value ranges between 1 and " << vectorSize << " |\n";
    cout << char(192) << string(53, char(196)) << char(217) << endl;

    string cityId;
    cin >> cityId;

    if(stoi(cityId) < 1 || stoi(cityId)>vectorSize){
        cout << "Invalid choice. Please try again." << endl;
        cout << endl;
        determineMaxWaterFlow();
    }

    cout << endl;

    City chosenCity;

    for (auto city: cities){
        if(city.getCityId() == stoi(cityId)){
            chosenCity = city;
        }
    }

    // source = Reservoirs
    // sink = Cities
    // pumping stations = Intermediates

    for(int i= 0; i<reservoir.size(); i++){
        Utils::edmondsKarp(g, reservoir[0].getReservoirCode(), chosenCity.getCityCode());
    }


}

void Menu:: verifyWaterNeeds()
{

}

void Menu:: balanceLoad()
{
    cout<<"Balancing load..."<<endl;
}
void Menu:: resilienceAnalysis()
{
    cout<<"Performing resilience analaysis..."<<endl;
}
void Menu:: pipelineFailureAnalysis()
{
    cout<<"Performing pipeline failire analaysis..."<<endl;
}