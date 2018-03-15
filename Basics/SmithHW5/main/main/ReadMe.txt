*******************************************************
*  Name      :  Adam Smith        
*  Student ID:  106969176               
*  Class     :  CSC 2421           
*  HW#       :  1                
*  Due Date  :  Feb. 05, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program inputs two arrays from a file. It then outputs 
the union of both arrays and the difference of the arrays.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from the user and start the game.

Name:  ArrayBag.h
   Contains the definition for the class.  

Name: ArrayBag.cpp
   Defines and implements the Guess class for implementing a game.  
   This class provides routines to construct and start th game.

Name: SetFunctions.h
   Contains definitions of functions to manipulate the arrays.

Name: SetFunctions.cpp 
   Defines what the functions do.
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on visual studios 2015.  It was 
   compiled, run, and tested on csegrid.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [SmithHW2]

   Now you should see a directory named homework with the files:
        main.cpp
        ArrayBag.h
        ArrayBag.cpp
	SetFunctions.h
	SetFunctions.cpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [SmithHW2] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[arraybag]

4. Delete the obj files, executables, and core dump by
   %./make clean
