// Chapter 12, Programming Challenge 13: Inventory Program
#include <bits/stdc++.h>

using namespace std;

// Constant for array sizes
const int DESC_SIZE = 31;
const int DATE_SIZE = 11;

// Declaration of Inventory structure
struct Inventory
{
   char desc[DESC_SIZE];  // Description
   int qty;               // Quantity
   double wholeSale;      // Wholesale cost
   double retail;         // Retail price
   char date[DATE_SIZE];  // Date added to inventory

   Inventory* next = nullptr; // Only the printList and buildList
                             // functions use the next pointer
};

// Function prototypes
void addRecord(fstream &);
void viewRecord(fstream &);
void changeRecord(fstream &);
void buildList(fstream &, Inventory *&);
void printList(Inventory *);

int main()
{
   Inventory *head = nullptr; // pointer to the head of the linked list
                              // initialize to nullptr since the list
                              // is empty at the start of the program   

   // File stream object
   fstream inventoryFile;
   
   // User's menu choice
   int choice;
   
   // Display the menu and process the user's request.
   do
   {
      // Display the menu.
      cout << "\n1. Add a new record\n";
      cout << "2. View an existing record\n";
      cout << "3. Change an existing record\n";
      cout << "4. Exit\n\n";

      // Get the user's menu selection.
      cout << "Enter your choice (1-4): ";
      cin >> choice;
      
      // Validate the menu selection.
      while (choice < 1 || choice > 4)
      {
         cout << "ERROR. Enter 1, 2, 3, or 4: ";
         cin >> choice;
      }
   
      // Process the selection.
      switch (choice)
      {
         // Choice 1 is to add a record.
         case 1:  
            addRecord(inventoryFile);
            break;
        
         // View an existing record
         case 2:
            viewRecord(inventoryFile); 
            break;
                 
         // Change an existing record
         case 3:
            changeRecord(inventoryFile);
            break;
            
         // Quit the program 
         case 4:
            buildList(inventoryFile, head);
            printList(head);
            break;
      }
         
   } while (choice != 4);
   
   return 0;
}

//************************************************
// Function addRecord                            *
// This function gets the data for a record      *
// and writes it to the file.                    *
//************************************************
void addRecord(fstream &invFile)
{
   // An inventory structure to hold an inventory record.
   Inventory record;

   // Open the file.
   invFile.open("invtry.dat", ios::out | ios::app | ios::binary);

   // If an error happened, exit.
   if (invFile.fail())
   {
      cout << "Error opening file.\n";
      exit(EXIT_FAILURE);
   }
   cin.get(); //make sure that the keyboard buffer is empty 
             // before prompting the user for the description

   cout << "\nEnter the following inventory data:\n";
   
   // Get the description.
   cout << "Description: ";
   cin.getline(record.desc, DESC_SIZE);
   
   // Get the quantity.
   cout << "Quantity: ";
   cin >> record.qty;
   while (record.qty < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.qty;
   }

   // Get the wholesale cost.
   cout << "Wholesale cost: ";
   cin >> record.wholeSale;
   while (record.wholeSale < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.wholeSale;
   }
   
   // Get the retail price.
   cout << "Retail price: ";
   cin >> record.retail;
   while (record.retail < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.retail;
   }
   
   // Get the date added to inventory.
   cout << "Date added to inventory: ";
   cin >> record.date;

   // Write the record.
   invFile.write(reinterpret_cast<char *>(&record), sizeof(record));
   
   // Make sure we didn't have an error writing.
   if (invFile.fail())
      cout << "Error writing record to file.\n";
   else
      cout << "record written to file.\n\n";
      
   // Close the file.
   invFile.close();
}

//************************************************
// Function viewRecord                           *
// This function reads a specified record from   *
// the file and displays it on the screen.       *
//************************************************
void viewRecord(fstream &invFile)
{
   Inventory record;
   long recNum;

   // Open the file for input.
   invFile.open("invtry.dat", ios::in | ios::binary);

   // Get the record number.
   cout << "Enter the record number: ";
   cin >> recNum;

   // Move to the record and read it.
   invFile.seekg(recNum * sizeof(record), ios::beg);
   invFile.read(reinterpret_cast<char *>(&record), sizeof(record));

   // Display the record contents.
   cout << "Description: ";
   cout << record.desc << endl;
   cout << "Quantity: ";
   cout << record.qty << endl;
   cout << "Wholesale cost: ";
   cout << record.wholeSale << endl;
   cout << "Retail price: ";
   cout << record.retail << endl;
   cout << "Date added: ";
   cout << record.date << endl;

   // Close the file.
   invFile.close();
}

//***************************************************
// Function changeRecord                            *
// This function reads a specified record from      *
// the file, displays it, and allows the user       *
// to modify it.                                    * 
//***************************************************
void changeRecord(fstream &invFile)
{
   Inventory record;
   long recNum;

   // Open the file for input/output.
   invFile.open("invtry.dat", ios::in | ios::out | ios::binary);

   // Get the record number.
   cout << "Enter the record number: ";
   cin >> recNum;

   // Move to the record and read it.
   invFile.seekg(recNum * sizeof(record), ios::beg);
   invFile.read(reinterpret_cast<char *>(&record), sizeof(record));

   // Display the record contents.
   cout << "Description: ";
   cout << record.desc << endl;
   cout << "Quantity: ";
   cout << record.qty << endl;
   cout << "Wholesale cost: ";
   cout << record.wholeSale << endl;
   cout << "Retail price: ";
   cout << record.retail << endl;
   cout << "Date added: ";
   cout << record.date << endl;

   // Get the new record data.
   cout << "Enter the new data:\n";
   cout << "Description: ";
   cin.ignore();
   cin.getline(record.desc, DESC_SIZE);
   cout << "Quantity: ";
   cin >> record.qty;
   cout << "Wholesale cost: ";
   cin >> record.wholeSale;
   cout << "Retail price: ";
   cin >> record.retail;
   cout << "Date added: ";
   cin >> record.date;
   
   // Move back to the beginning of this record's position.
   invFile.seekp(recNum * sizeof(record), ios::beg);
   
   // Write the new record over the current record.
   invFile.write(reinterpret_cast<char *>(&record), sizeof(record));
   
   // Close the file.
   invFile.close();  
}

//************************************************************
// buildList                                                 *
// Reads each record from the binary file and inserts it     *  
// into a linked list                                        *  
//************************************************************
void buildList(fstream &invFile, Inventory * &head) {
   Inventory record;

   // Open the file for input.
   invFile.open("invtry.dat", ios::in | ios::binary);

   // Go to the end of the file 
   invFile.seekg(0L, ios::end);

   // Calculate the number of records in the file
   int numRecords = invFile.tellg() / sizeof(record);
   
   // Go back to the beginning of the file
   invFile.seekg(0L, ios::beg);

   for (int count = 0; count < numRecords; count++) {
      // read a record from the file
      invFile.read(reinterpret_cast<char *>(&record), sizeof(record));
      
      // create a new node to store the record
      Inventory * newNode = new Inventory;
      *newNode = record;
      
      // insert the node at the beginning of the list
      newNode->next = head;
      head = newNode;
   }
   
   // Close the file.
   invFile.close();
}

//*************************************************************
// printList                                                  *
// Traverses a linked list of Inventory objects and prints    *
// out each of the fields stored in each object               *
//*************************************************************
void printList(Inventory *head) {
   cout << "\n\nHere is a list of the records in the file:\n\n\n";

   Inventory *p = head;

   while (p != nullptr) {
      cout << "Description: ";
      cout << p->desc << endl;
      cout << "Quantity: ";
      cout << p->qty << endl;
      cout << "Wholesale cost: ";
      cout << p->wholeSale << endl;
      cout << "Retail price: ";
      cout << p->retail << endl;
      cout << "Date added: ";
      cout << p->date << endl << endl;
      
      p = p->next;  
   }
}