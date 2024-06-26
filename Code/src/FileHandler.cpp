#include "../include/FileHandler.h"

Graph * WaterSupply;

void FileHandler::readReservoirs() {
    string filePathReservoirs = "../Code/datasets/Reservoir.csv";
    fstream reservoirsCSV;              // Declare File Stream Object
    reservoirsCSV.open(filePathReservoirs);  // filePath is passed as constructor and opens said file
    int linePos = 0;

    if(reservoirsCSV.fail()) {          // If file fails to open
        cerr << "Unable to open specified file" << filePathReservoirs << endl;         // Prints error message
    }

    string line;
    while(getline(reservoirsCSV, line)) {
        if(line.empty()) {      // skip possible empty lines
            continue;
        }

        if(linePos == 1) {
            parseReservoir(line);                   // if line is not header, do function parse Reservoir to divide string into values of reservoir data type and add to reservoir vector
        }
        linePos = 1;
    }

    reservoirsCSV.close();              // close the csv file
}

void FileHandler::parseReservoir(string currLine) {
    vector<string> parsed;                               // Create  a vector to store the single lines different attributes for easier access
    stringstream ss(currLine);                           // Constructor of object w/ type stringstream, and currLine is copied to said ss
    string singleColumn;                                 // Auxiliary string to help

    while(getline(ss, singleColumn, ',')) {     // Read data from an input stream into string variable, delimiter indicates where the input should stop reading
        parsed.push_back(singleColumn);
    }

    // Since id and delivery are integers, the strings are converted to integers to match
    Reservoir reservoirInput(parsed[0],parsed[1],stoi(parsed[2]),parsed[3],stoi(parsed[4]));        // Construct Reservoir item with info from string vector

    // Check if Reservoir is not already in the vector
    for(auto res: getReservoirsVector()) {
        if(res.getReservoirName()==reservoirInput.getReservoirName() && res.getMunicipality()==reservoirInput.getMunicipality() && res.getReservoirId()==reservoirInput.getReservoirId() && res.getReservoirCode()==reservoirInput.getReservoirCode() && res.getMaxDelivery()==reservoirInput.getMaxDelivery()) {
            return;             // Exit function if Reservoir is in the vector
        }
    }

    WaterSupply.addVertex(reservoirInput.getReservoirCode());
    reservoirs_.push_back(reservoirInput);
}


vector<Reservoir> FileHandler::getReservoirsVector() {
    return reservoirs_;
}

void FileHandler::readStations() {
    string filePathStations = "../Code/datasets/Stations.csv";
    fstream stationsCSV;                                                        // Declare File Stream Object
    stationsCSV.open(filePathStations);                                         // filePath is passed as constructor and opens said file
    int linePos = 0;

    if(stationsCSV.fail()) {                                                           // If file fails to open
        cerr << "Unable to open specified file" << filePathStations << endl;         // Prints error message
    }

    string line;
    while(getline(stationsCSV, line)) {
        if(line.empty()) {      // skip possible empty lines
            continue;
        }

        if(linePos == 1) {                                 // checks if the line position is 1, if it's is 0, it means that current line is header
            parseStation(line);                   // if line is not header, do function parse Station to divide string into values of station data type and add to stations vector
        }

        linePos = 1;
    }

    stationsCSV.close();              // close the csv file
}

void FileHandler::parseStation(string currLine) {
    vector<string> parsed;                               // Create  a vector to store the single lines different attributes for easier access
    stringstream ss(currLine);                           // Constructor of object w/ type stringstream, and currLine is copied to said ss
    string singleColumn;                                 // Auxiliary string to help

    while(getline(ss, singleColumn, ',')) {     // Read data from an input stream into string variable, delimiter indicates where the input should stop reading
        parsed.push_back(singleColumn);
    }

    // Since id is an integer, the string is converted to integer to match
    Station stationInput(stoi(parsed[0]), parsed[1]);        // Construct Station item with info from string vector

    // Check if Reservoir is not already in the vector
    for(auto stat: getStationsVector()) {
        if(stat.getStationId()==stationInput.getStationId() && stat.getStationCode()==stationInput.getStationCode()) {
            return;             // Exit function if Station is in the vector
        }
    }

    WaterSupply.addVertex(stationInput.getStationCode());
    stations_.push_back(stationInput);
}

vector<Station> FileHandler::getStationsVector() {
    return stations_;
}

void FileHandler::readCities() {
    string filePathCities = "../Code/datasets/Cities.csv";
    fstream citiesCSV;                                                        // Declare File Stream Object
    citiesCSV.open(filePathCities);                                         // filePath is passed as constructor and opens said file
    int linePos = 0;

    if(citiesCSV.fail()) {                                                           // If file fails to open
        cerr << "Unable to open specified file" << filePathCities << endl;         // Prints error message
    }

    string line;
    while(getline(citiesCSV, line)) {
        if(line.empty()) {      // skip possible empty lines
            continue;
        }

        if(linePos == 1) {                              // checks if the line position is 1, if it's is 0, it means that current line is header
            parseCity(line);                   // if line is not header, do function parse City to divide string into values of City data type and add to cities vector
        }
        linePos = 1;
    }

    citiesCSV.close();              // close the csv file
}

void FileHandler::parseCity(string currLine) {
    vector<string> parsed;                               // Create  a vector to store the single lines different attributes for easier access
    stringstream ss(currLine);                           // Constructor of object w/ type stringstream, and currLine is copied to said ss
    string singleColumn;                                 // Auxiliary string to help
    while(getline(ss, singleColumn, ',')) {     // Read data from an input stream into string variable, delimiter indicates where the input should stop reading
        parsed.push_back(singleColumn);
    }

    // Since id, demand and population are integers, the strings are converted to integers to match
    City cityInput(parsed[0],stoi(parsed[1]),parsed[2],stoi(parsed[3]),stoi(parsed[4]));        // Construct City item with info from string vector

    // Check if City is not already in the vector
    for(auto city: getCitiesVector()) {
        if(city.getCity()==cityInput.getCity() && city.getCityId()==cityInput.getCityId() && city.getCityCode()==cityInput.getCityCode() && city.getDemand()==cityInput.getDemand() && city.getPopulation()==cityInput.getPopulation()) {
            return;             // Exit function if Deposit Site is in the vector
        }
    }

    WaterSupply.addVertex(cityInput.getCityCode());
    cities_.push_back(cityInput);
}

vector<City> FileHandler::getCitiesVector() {
    return cities_;
}

void FileHandler::readPipes() {
    string filePathPipes = "../Code/datasets/Pipes.csv";
    fstream pipesCSV;                                                        // Declare File Stream Object
    pipesCSV.open(filePathPipes);                                         // filePath is passed as constructor and opens said file
    int linePos = 0;

    if(pipesCSV.fail()) {                                                           // If file fails to open
        cerr << "Unable to open specified file" << filePathPipes << endl;         // Prints error message
    }

    string line;
    while(getline(pipesCSV, line)) {
        if(line.empty()) {      // skip possible empty lines
            continue;
        }

        if(linePos == 1) {                              // checks if the line position is 1, if it's is 0, it means that current line is header
            parsePipe(line);                   // if line is not header, do function parse Pipe to divide string into values of Pipe data type and add to pipes vector
        }
        linePos = 1;
    }

    pipesCSV.close();              // close the csv file
}

void FileHandler::parsePipe(string currLine) {
    vector<string> parsed;                               // Create  a vector to store the single lines different attributes for easier access
    stringstream ss(currLine);                           // Constructor of object w/ type stringstream, and currLine is copied to said ss
    string singleColumn;                                 // Auxiliary string to help

    while(getline(ss, singleColumn, ',')) {     // Read data from an input stream into string variable, delimiter indicates where the input should stop reading
        parsed.push_back(singleColumn);
    }

    // Since capacity and direction are integers/boolean, the strings are converted to integers to match
    Pipe pipeInput(parsed[0],parsed[1],stoi(parsed[2]),stoi(parsed[3]));        // Construct Pipe item with info from string vector

    // Check if Reservoir is not already in the vector
    for(auto pip: getPipesVector()) {
        if(pip.getPointA()==pipeInput.getPointA() && pip.getPointB()==pipeInput.getPointB() && pip.getCapacity()==pipeInput.getCapacity() && pip.getDirection()==pipeInput.getDirection()) {
            return;             // Exit function if Pipeline is in the vector
        }
    }

    WaterSupply.addEdge(pipeInput.getPointA(), pipeInput.getPointB(), pipeInput.getCapacity());
    pipes_.push_back(pipeInput);
}

vector<Pipe> FileHandler::getPipesVector() {
    return pipes_;
}


Graph * FileHandler::getGraph() {
    return WaterSupply;
}



