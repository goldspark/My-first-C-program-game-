//here we define load and save
#include "loadsave.h"

#include <iostream>
#include <cstring>


bool no_save = true;

int save_game1(char *name, std::ofstream &save)
{
    char *password = new char[80];
    save.open("save.txt");
        if(!save.is_open())// checing if it is open or corrupted
        {
            std::cout << "save.txt is corrupted! " << std::endl;

            return - 1;
        }

    std::cout << "Enter password: ";
    std::cin.getline(password, 19);
    save << name << "\n" << password;

    delete [] password;
    save.close();
    return 0;

}


int load_game1(char *input, std::ifstream &load)
{
    char *read_line = new char[80]; //used to read lines of a file
    char *temp = new char[10]; // used to store name
if(!load.is_open()) //checking if file exists or is corrupted
    {
      std::cout << "save.txt is corrupted! " << std::endl;
      return -1;
    }

    load.getline(read_line, 79);
    strncpy(temp, read_line, 9);
    if(strcmp(read_line, input) == 0) // if it exists it will ask for password
    {
        no_save = false; // save is found!

        load.getline(read_line, 79);
    } //end of password check

     /////////////////////////////////////// Password check loop
        while(no_save == false)
        {

        std::cout << "Account found. Please enter password(0 to exit): ";
        std::cin.getline(input, 79);

        if(strcmp(input, "0") == 0) //if user wants to exit
        {
            no_save = false;
            break;
        }

        if(strcmp(input, read_line) == 0) // check password
        {
            std::cout << "Welcome " << temp << std::endl;
            break;
        }

        }
     delete [] read_line;
     delete [] temp;
     load.close();


}
