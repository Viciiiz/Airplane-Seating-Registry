# include <iostream>
# include <cstdlib>
# include <ctime>
# include <string>
# include <algorithm>
# include "nameGenerator.cpp"

using namespace std;


/**
 * A class for the format of seating. Set the number of rows, columns, and sections in the airplane using the constructor.
 */
class Seating{

    private:
        int rows;
        int columns;
        int sections;
        const int maxSeats = 853; // number of seats cannot exceed 853, which is the max capacity of the largest aircraft (Airbus A380)    
        string fullNames [853];
        int numPass = 0;
        string alphabet[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

    public:

        // constructor
        Seating(int rows, int columns, int sections){
            this->rows = rows;
            this->columns = columns;
            this->sections = sections;
        }

        int numberOfSeats(){
            return rows*columns;
        }


        /**
         * Method to get the number of passengers, and therefore the number of occupied seats in the plane.
         * The number of passengers is a random number between 0 and the number of seats in the airplane.
         */
        int passCount(){
            srand(time(0));
            return rand() % (rows * columns);
        }


        /**
         * Method that returns a random number
         */
        int randNum(int max, int increment){
            srand(time(0));
            int a = rand() * increment;
            return abs(a % max);
        }


        /**
         * call the name generator class to generate random full names in an array. No duplicates.
         */
        void nameGen () {
            numPass = passCount();
            nameGenerator name;
            // make sure all the seats in the array are empty
            for (int i = 0 ; i < maxSeats; i++){
                fullNames[i] = "EMPTY";
            }
            // insert names, no duplicates
            int increment = 173;
            for(int i = 0 ; i < numPass;  i++){
                bool newName = false;
                while (!newName){
                    int count = 0;
                    // generate random numbers for random names
                    //srand(time(0));
                    int randLast = randNum(numPass, increment);
                    increment+= 26;
                    int randFirst = randNum(numPass, increment);
                    string currentName = name.getFullName(randLast,randFirst);
                    for (int j = 0 ; j < numPass; j++){
                        if (fullNames[j]!=currentName){
                            count++;
                        }
                    }
                    if (count == passCount()){
                        newName = true;
                        fullNames[i]=currentName;
                    }
                }
            }
        }


        /**
         * Method to separate the first and last names, and display the final output
         */ 
        void format (){
            // separate first and last names
            string first[numPass];
            string last[numPass];
            for (int i = 0; i < numPass; i++){
                string currentFirst = string(fullNames[i].cbegin(), find(fullNames[i].cbegin(),fullNames[i].cend(), '*'));
                string currentLast = string(find(fullNames[i].cbegin(),fullNames[i].cend(), '*')+1, fullNames[i].cend());
                first[i] = currentFirst;
                last[i] = currentLast;
            }

            // find the longest name
            int max = 0;
            if (numPass == 0){
                max = 5;
            } else {
                for (int i = 0; i < numPass; i++){
                    if (first[i].length()>max){
                        max = first[i].length();
                    }
                    if (last[i].length()>max){
                        max = last[i].length();
                    }
                }
            }

            // display the seatings
            string border = repeat(repeat("+--" + repeat("-",max), columns/sections) + "+" + repeat(" ",6),sections);
            int currentIndex = 0;
            int firstNameIndex = 0;
            int lastNameIndex = 0;
            for(int i = 0; i < rows; i++){
                // border
                cout << border << endl;

                // seat number
                std::string iToStr = std::to_string(i+1);
                int columnNum = 0;
                for (int j = 0 ; j < sections; j++){
                    for (int k = 0; k < columns/sections; k++){
                        string currentSeat = iToStr + alphabet[columnNum];
                        columnNum++;
                        cout << "| " + currentSeat + repeat(" ", max-currentSeat.length()) + " ";
                    }
                    cout << "|" + repeat(" ",6);
                }
                cout << "\n";
                
                // first name
                for (int j = 0 ; j < sections; j++){
                    for (int k = 0; k < columns/sections; k++){
                        string currFirst;
                        if(firstNameIndex >= numPass){
                            currFirst = "EMPTY";
                        } else {
                            currFirst = first[firstNameIndex];
                        }
                        cout << "| " + currFirst + repeat(" ", max-currFirst.length());
                        if (currFirst.length()!=max){
                            cout << " ";
                        }
                        firstNameIndex++;
                    }
                    cout << "|" + repeat(" ",6);
                }
                cout << "\n";

                // last name
                for (int j = 0 ; j < sections; j++){
                    for (int k = 0; k < columns/sections; k++){
                        string currLast;
                        if(lastNameIndex >= numPass){
                            currLast = "EMPTY";
                        } else {
                            currLast = last[lastNameIndex];
                        }
                        cout << "| " + currLast + repeat(" ", max-currLast.length());
                        if (currLast.length()!=max){
                            cout << " ";
                        }
                        lastNameIndex++;
                    }
                    cout << "|" + repeat(" ",6);
                }
                cout << "\n";
            }

            // last border 
            cout << border << endl;

            // summary
            cout << "Number of seats: " << rows*columns << "\n"
            << "Number of passengers: " << numPass << "\n"
            << "Number of empty seats: " << rows*columns - numPass << "\n"
            << "Number of rows: " << rows << "\n"
            << "Number of columns: " << columns << "\n"
            << "Number of sections: " << sections << "\n"; 
        }


        /** 
         * Method to repeat a string n times
         */
        string repeat(string s, int n) { 
            string s1 = s; 
            for (int i=1; i<n;i++) {
                s += s1; // Concatinating strings 
            }
            return s; 
        } 


};


// MAIN 
int main () {
    
    cout << "Airplane seating registry: \n" << endl;
    // the number of columns must be a multiple of the number of sections, i.e. columns % sections = 0
    // the number of columns cannot exceed 26 (26 letters of the alphabet)
    // rows, columns, sections
    Seating seating(4,8,4);
    seating.nameGen();
    seating.format();
    
    return 0;
}