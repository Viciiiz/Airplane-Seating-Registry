# include <iostream>
using namespace std;

/**
 * A class to generate random full names from two arrays of last and first names.
 */
class nameGenerator {

        // array of first names
    public:
        /**
         * array of last names 
         */
        string lastNames[34] = {
            "Ahlgren", "Alic", "Anwar",
            "Bacon",
            "Caira", "Colgan", "Collins",
            "Fister", "Fletcher",
            "Gonzalez", "Grinsell",
            "Handa", "Hernandez", "Hernandez", "Hightower",
            "Jones",
            "Ladney",
            "Neuhardt", "Nguyen",
            "Pacalso", "Paras", "Patel", "Pecho", "Pecoraro",
            "Rakotondranoro",
            "Santana", "Scott", "Shaw", "Staloch",
            "Villaraza",
            "Wassan",
            "Xie",
            "Zukauskas",
            "Irakliotis"
        };
    
        /**
         * array of first names
         */
        string firstNames[21] = {
            "James",
            "John",
            "Robert",
            "Michael",
            "William",
            "David",
            "Richard",
            "Charles",
            "Joseph",
            "Thomas",
            "Christopher",
            "Daniel",
            "Paul",
            "Mark",
            "Donald",
            "George",
            "Kenneth",
            "Steven",
            "Edward",
            "Brian",
            "Leo"
        };

        /**
         * Method to return a full name with random first and last names from the two arrays above
         */
        string getFullName(int randLast, int randFirst){
            // pick random first and last names 
            string first = firstNames[randFirst];
            string last = lastNames[randLast];
            // assemble the two, separated with a "*"
            string fullName = first + "*" + last;
            return fullName;
        }

};