#include "../include/Menu.h"
#include<iostream>

void Menu:: open(){

    char choice;

    // Display the main menu and prompt for user input

    do{

        displayMainMenu();
        cout<<"Enter your choice: ";
        cin>>choice;


        // user's choice
        switch (choice)
        {
        case '1':
            readAndParseData();
            break;
        
        case '2':
            determineMaxWaterFlow();
            break;

        case '3':
            verifyWaterNeeds();
            break;

        case '4':
            balanceLoad();
            break;

        case '5':
            resilienceAnalysis();
            break;
         
        case '6':
            pipelineFailureAnalysis();
            break;
        
        case '7':
            exitProgram();
            break;

        default:
            cout<<"Invalid choice. Please try again."<<endl;;
        }
    } while (choice!='7');
    
    
}

void Menu:: displayMainMenu()
{
    cout << "\n=== Water Supply Management System ===\n";
    cout << "1. Read and Parse Data\n";
    cout << "2. Determine Maximum Water Flow\n";
    cout << "3. Verify Water Needs\n";
    cout << "4. Balance Load\n";
    cout << "5. Resilience Analysis\n";
    cout << "6. Pipeline Failure Analysis\n";
    cout << "7. Exit\n";
}

void Menu:: readAndParseData()
{
    cout<<"Reading and parsing data..."<<endl;
}

void Menu:: determineMaxWaterFlow()
{
    cout<<"Determining maximum water flow..."<<endl;
}

void Menu:: verifyWaterNeeds()
{
    cout<<"Verifying water needs..."<<endl;
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

void Menu:: exitProgram()
{
    cout<<"Exiting program. Goodbye!"<<endl;
}