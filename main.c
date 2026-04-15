/*
Name:Manjusha Thiruveedhula
Registration Number:25048_005
Submission date:03-04-2026
Description:				About "addressbook.h" 

			1.This header file is basically the backbone of the project. 
			2.It defines all the important structures and declares the functions that are used throughout the program. 
			3.The Contact structure is used to store details of each person, by their name, phone number, and email. 
			4.The AddressBook structure stores multiple contacts in an array, keeps track of the total number of contacts, and also Contactcount.

							About "addressbook.c"

			->This file contains the actual implementation of all the functions like validation, creating contact, editing, deleting, searching, saving, and listing contacts is written.

							i)validation_phone

			1.This function checks if the phone number entered is valid.
			2.It must be exactly 10 digits, all characters must be numbers, and the first digit should be between 6 and 9. 
			3.If these conditions are not met, the number is rejected.

							ii)validation_email

			1.This function checks if the email entered is valid. 
			2.It only accepts emails ending with @gmail.com. 
			3.It also ensures the email does not start with @ or . and that the characters used are valid.
			4.And make sure that entered email doesn't contain any special characters other than @ and .
			5.If the above conditions met then the email is valid otherwise not.

							iii)is_unique_number

			1. This function makes sure that the phone number entered does not already exist in the address book. 
			2.It prevents duplicate contacts with the same phone number. 

							iv)add_contact

			1.This function allows the user to add a new contact. 
			2.It asks for the name, phone number, and email, and validates them before saving. 
			3.If the phone number is not unique or the email is invalid, it asks the user to re-enter until it is correct.

							v)savecontactstofile

			1.This function saves all the contacts into a file called database.csv.
			2.Each contact is written in a line separated by commas. 
			3.This makes sure that the data is not lost when the program exits.

							vi)loadcontactstofile

			1.This function loads the contacts from the file back into the program when it starts. 
			2.It reads each line from the CSV file and stores the details into the contacts array.

							vii)search_contact

			1.This function allows the user to search for a contact by name, phone number, or email. 
			2.It prints the matching contacts in a table format and stores their indices in the index_record array for further operations like edit or delete.
			3.sets ir_size to the number of matches found.

							viii)edit_contact

			1.This function lets the user edit an existing contact.
			2.It first searches for the contact, then allows the user to change the name, phone number, or email. 
			3.The new details are validated before updating.

							ix)delete_contact

			1.This function deletes a contact from the address book. 
			2.It first searches for the contact, confirms with the user, and then removes it by shifting the remaining contacts in the array.

							x)list_contact

			1. This function displays all the contacts in a neatly aligned table. It shows the serial number, name, phone, and email. 
			2.If there are no contacts, it prints a message saying no contacts found.

							About "main.c"

			1.It provides a menu-driven interface so the user can easily interact with the program.
			2.When the program begins, it initializes the address book and loads any previously saved contacts from the file. 
			3.After that, it shows a menu with different options like add, search, edit, delete, list, and exit. 
			4.Depending on what the user selects, it calls the required function from the other file. 
			5.When the user decides to exit, all the contacts are saved back to the file and then exits.
			6.Each file is interlinked to main.c

							About database.csv

			1.A CSV file stands for Comma-Separated Values file.
			2.It’s a very simple text file format that is used to store tabular data, like a spreadsheet, in plain text by seperating with comma.
			3.In our project database.csv is used to store contacts with name,phone number,email.
*/


#include "addressbook.h"

int main() 
{
    int choice;

    struct AddressBook addressBook;
    addressBook.contactCount = 0;
    addressBook.ir_size = 0;

    printf("%zu\n", sizeof(addressBook));
    loadcontactstostruct(&addressBook);
    do 
    {
	printf("\nAddress Book Menu:\n");
	printf("1. Add/Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6. Exit\n");
	printf("Enter your choice: ");

	scanf("%d", &choice);
	switch (choice) 
	{
	    case 1:
		add_contact(&addressBook);
		break;
	    case 2:
		search_contact(&addressBook);
		break;
	    case 3:
		edit_contact(&addressBook);
		break;
	    case 4:
		delete_contact(&addressBook);
		break;
	    case 5:
		list_contacts(&addressBook);
		break;
	    case 6:
		printf("Saving and Exiting...\n");
		savecontactstofile(&addressBook);
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 6);

    return 0;
}
