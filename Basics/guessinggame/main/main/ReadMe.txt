*******************************************************
*  Name      :  Adam Smith        
*  Student ID:  106969176               
*  Class     :  CSC 2421           
*  HW#       :  1                
*  Due Date  :  Jan. 22, 2017
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program is a random number guessing game. It inputs
the range and number of random numbers from the user. 
It then computes random numbers based of time.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls sub-functions
   to read data from the user and start the game.

Name:  guess.h
   Contains the definition for the class Guess.  

Name: guess.cpp
   Defines and implements the Guess class for implementing a game.  
   This class provides routines to construct and start th game.

*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on gnu g++ 4.4.2.  It was 
   compiled, run, and tested on csegrid.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [SmithHW1]

   Now you should see a directory named homework with the files:
        main.cpp
        guess.h
        guess.cpp
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [SmithHW1] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[guess]

4. Delete the obj files, executables, and core dump by
   %./make clean
