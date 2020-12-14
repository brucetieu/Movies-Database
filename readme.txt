Name      :  Bruce Tieu
*  Student ID:  107841636
*  Class     :  CSCI 2421
*  Due Date  :  12/11/2020
*******************************************************


Read Me


*******************************************************
*  Description of the program
*******************************************************

For this Final Project you will develop a simple database system. The database is to handle multiple records,
each composed of several fields. The database will store its information in a file, it will update the file based on
addition of records and field modifications. It will allow users to sort records based on the selected keys
and produce reports (output) according to predefined criteria.

More detail in the Final Report.



*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
       Main function is to display the main menu. This is what is looks like:

       a. Read in a file
       b. Add a record
       c. Search a record
       d. Sort database by a field
       e. Export latest database (after adds or modifies).
       q. Quit


Name: BinaryTree.h
      Defines and implements a BST template. Functions include getRoot(), inorderPrint(), getNewNode(), insert(), clearTree(),
      and getSize() function. Each node in the BST is of type TreeNode, with type T.

Name: ActorsActresses.h / ActorsActresses.cpp
      Define and implement methods for reading fiel, adding, searching, modifying, sorting fields, writing fields.
      There is a functor object which is used to make comparisons on the fields in ActorsActresses.

Name: Pictures.h / Pictures.cpp
      Define and implement methods for reading file, adding, searching, modifying, sorting fields, writing fields.
      There is a functor object which is used to make comparisons on the fields in Pictures.

Name: Menu.h / Menu.cpp
      Define and implement methods for creating the menu system to navigate options for both databases.

Name: Utility.h / Utility.cpp
      Define and implement methods for helping out the Pictures and ActorsActresses classes. There is only one method
      which is used to convert a string to lowercase.

Name: picturesOutput.csv and actorsOutput.csv
     These are sample output csv files from exporting search results or adding records 	   from each database.
*******************************************************
*  Status of program
*******************************************************

The program runs successfully.

The program was developed and tested on Clion with g++. It was compiled, run, and tested on gcc csegrid.ucdenver.pvt. and
repl.it gcc and gnu.

******************************************************
*  How to run the program
******************************************************

in the terminal, type:

1) make ./CSCI2421FinalProject_BT
2) ./CSCI2421FinalProject_BT




