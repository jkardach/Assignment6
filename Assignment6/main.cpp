//
//  main.cpp
//  Assignment6
//
//  5/27/21.
//

#include <iostream>
#include <fstream>
#include <string>

#include "LinkedList.hpp"
#include "Composer.hpp"
using namespace std;

// forward declarations
char displayMenu();
void removeRec(LinkedList<Composer> &list);
void displayList(LinkedList<Composer> list);
void searchRec(LinkedList<Composer> &list);

// main function, reads composers in from file
// into a linked list on the heap
// then prompts the users for what to do
int main(int argc, const char * argv[]) {
    // open composers.txt, and read data into linked list.
    LinkedList<Composer> list;  // create list
    string name = "";
    int year = 0;
    ifstream inFile;
    inFile.open("composers.txt");
    while(!inFile.eof()) {
        getline(inFile, name, ','); // read the name, ',' is delimiter
        inFile >> year;             // read the year
        Composer composer = Composer(name, year); // create composer object
        list.insert(composer);      // append composer to linked list
        getline(inFile, name);      // read rest of line (CR/LF)
    }
    inFile.close();     // close the input file
    
    // display the menu and execute commands
    bool done = false;
    do {
        char prompt = displayMenu();
        switch (prompt) {
            case 's':
                searchRec(list);    // search for record
                break;
            case 'r':
                removeRec(list);    // remove record
                break;
            case 'd':
                displayList(list);  // display list
                break;
            case 'e':
                done = true;        // exit program
                break;

            default:
                cout << "Need to enter a valid command";  // invalid input
                cout << " ('s', 'r', 'd' or 'e')\n" << endl;
                break;
        }
        
    } while(!done);
    cout << "Thanks for using our composer database!" << endl;
    cout << endl;
    
    return 0;
}

// dislayMenu displays a menu and returns a char for the selection
char displayMenu() {
    char p = ' ';
    bool done = false;
    do {
        cout << endl;
        cout << "Enter 's' to search, 'r' to remove,";
        cout << " 'd' to display, or 'e' to exit: " << flush;
        cin >> p;
        cin.ignore(INT_MAX, '\n');  // clears the buffer
        cout << endl;
        done = p == 's' || p == 'r' || p == 'd' || p == 'e';
        if(!done) {
            cout << "Do not recognize the selection " << p << "!" << endl;
        }
    } while(!done);
    return p;
}

// this removes the composer with name
void removeRec(LinkedList<Composer> &list) {
    Composer composer = Composer();
    string name = "";
    cout << "Enter a composer's name to remove: ";
    getline(cin, name);
    composer.setName(name);  // create a composer object with name
    if(list.remove(composer)) {
        cout << "\n        " << name << " was successfully removed from the list";
        cout << endl;
    } else {
        cout << "\n        " << name << " was not found in the list when ";
        cout << "attempting to remove" << endl;
    }
    cout << endl;
}

// this displays the composers list
void displayList(LinkedList<Composer> list) {
    cout << endl;
    cout << "Displaying Composer List" << endl;
    cout << endl;
    list.printList();
    cout << endl;
}

// this prompts for the item to search for
void searchRec(LinkedList<Composer> &list) {
    Composer composer = Composer();
    string name = "";
    cout << "Enter a composer's name to search for: ";
    getline(cin, name);
    composer.setName(name);  // create a composer object with name
    if(list.find(composer)) {
        cout << "\n        " << name << " was found in the list" << endl;
    } else {
        cout << "\n        " << name << " was not found in the list" << endl;
    }
    cout << endl;
}

/*
 Sample Run
 

 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d


 Displaying Composer List

 Claudio Monteverdi - 1643
 Henry Purcell - 1695
 Antonio Vivaldi - 1741
 Johann Sebastian Bach - 1750
 George Frideric Handel - 1759
 Wolfgang Amadeus Mozart - 1791
 Joseph Haydn - 1809
 Ludwig van Beethoven - 1827
 Franz Schubert - 1828
 Felix Mendelssohn - 1847
 Frederic Chopin - 1849
 Robert Schumann - 1856
 Hector Berlioz - 1869
 Richard Wagner - 1883
 Franz Liszt - 1886
 Pyotr Ilyich Tchaikovsky - 1893
 Johannes Brahms - 1897
 Giuseppe Verdi - 1901
 Antonin Dvorak - 1904
 Edvard Grieg - 1907
 Gustav Mahler - 1911
 Claude Debussy - 1918
 Camille Saint-Saens - 1921
 Giacomo Puccini - 1924
 George Gershwin - 1937
 Maurice Ravel - 1937
 Sergei Rachmaninoff - 1943
 Bela Bartok - 1945
 Arnold Schoenberg - 1951
 Sergei Prokofiev - 1953
 Igor Stravinsky - 1971
 Dmitri Shostakovich - 1975
 Leonard Bernstein - 1990
 Aaron Copland - 1990



 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s

 Enter a composer's name to search for: Aaron Copland

         Aaron Copland was found in the list


 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r

 Enter a composer's name to remove: Aaron Copland

         Aaron Copland was successfully removed from the list


 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r

 Enter a composer's name to remove: Dmitri Shostakovich

         Dmitri Shostakovich was successfully removed from the list


 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d


 Displaying Composer List

 Claudio Monteverdi - 1643
 Henry Purcell - 1695
 Antonio Vivaldi - 1741
 Johann Sebastian Bach - 1750
 George Frideric Handel - 1759
 Wolfgang Amadeus Mozart - 1791
 Joseph Haydn - 1809
 Ludwig van Beethoven - 1827
 Franz Schubert - 1828
 Felix Mendelssohn - 1847
 Frederic Chopin - 1849
 Robert Schumann - 1856
 Hector Berlioz - 1869
 Richard Wagner - 1883
 Franz Liszt - 1886
 Pyotr Ilyich Tchaikovsky - 1893
 Johannes Brahms - 1897
 Giuseppe Verdi - 1901
 Antonin Dvorak - 1904
 Edvard Grieg - 1907
 Gustav Mahler - 1911
 Claude Debussy - 1918
 Camille Saint-Saens - 1921
 Giacomo Puccini - 1924
 George Gershwin - 1937
 Maurice Ravel - 1937
 Sergei Rachmaninoff - 1943
 Bela Bartok - 1945
 Arnold Schoenberg - 1951
 Sergei Prokofiev - 1953
 Igor Stravinsky - 1971
 Leonard Bernstein - 1990



 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s Johann Seebastian Bach

 Enter a composer's name to search for: Johann Seebastian Bach

         Johann Seebastian Bach was not found in the list


 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: s

 Enter a composer's name to search for: Johann Sebastian Bach

         Johann Sebastian Bach was found in the list


 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: r

 Enter a composer's name to remove: Johann Sebastian Bach

         Johann Sebastian Bach was successfully removed from the list


 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: d


 Displaying Composer List

 Claudio Monteverdi - 1643
 Henry Purcell - 1695
 Antonio Vivaldi - 1741
 George Frideric Handel - 1759
 Wolfgang Amadeus Mozart - 1791
 Joseph Haydn - 1809
 Ludwig van Beethoven - 1827
 Franz Schubert - 1828
 Felix Mendelssohn - 1847
 Frederic Chopin - 1849
 Robert Schumann - 1856
 Hector Berlioz - 1869
 Richard Wagner - 1883
 Franz Liszt - 1886
 Pyotr Ilyich Tchaikovsky - 1893
 Johannes Brahms - 1897
 Giuseppe Verdi - 1901
 Antonin Dvorak - 1904
 Edvard Grieg - 1907
 Gustav Mahler - 1911
 Claude Debussy - 1918
 Camille Saint-Saens - 1921
 Giacomo Puccini - 1924
 George Gershwin - 1937
 Maurice Ravel - 1937
 Sergei Rachmaninoff - 1943
 Bela Bartok - 1945
 Arnold Schoenberg - 1951
 Sergei Prokofiev - 1953
 Igor Stravinsky - 1971
 Leonard Bernstein - 1990



 Enter 's' to search, 'r' to remove, 'd' to display, or 'e' to exit: e

 Thanks for using our composer database!

 Program ended with exit code: 0
 */
