//================================================================
// EunHo, Retika, Tomer
// February 2024
//
// This is a stub file driver for testing the Board classs with
// the RushHour configuration files.  You can use it for the basis
// of your main file.
//
// To execute:
// ./main 10 <Config0.txt
//================================================================

#include "Board.h"
#include "Hash.h"
#include <iostream>
#include<cstring>
using namespace std;

//================================================================
// This main method simply reads boards one at a time and prints
// the board along with its hash value.
//================================================================
int		main	( int argc, char *argv[] )
{

   // notice the hash table size is a command-line parameter
   if ( argc != 2 )
   {
      printf("Error: you must include the hash table size as a");
      printf(" command-line parameter.\n");
      exit(0);
   }
   int size = atoi(argv[1]);

   // here is what your declaration should look like
   // when you eventually create the HashTable class
   HashTable<Board>  table(size);

   // Now we attempt to read in boards until "EOF" is detected
   Board	b; // used to store the boards being read
   cin >> b;
   while ( !cin.eof() )
   {
      // here is where you might test if you have seen this board
      // before, if not enter it into your hash table.
      table.insert(b);

      cout << "Read in board: \n";     // comment this out later
      cout << b;
      cin >> b;
      
   };

   // add some code here to compute statistics for your
   // hashing performance

   double mean = 0;
   int min = 10000000;
   int max = 0;
   int total_item=0;

   // mean

   for (int i = 0; i < table.getNumSlots(); ++i) {
      mean += table.getSlotCount(i);
      total_item += table.getSlotCount(i);

      if(table.getSlotCount(i) < min){
         min = table.getSlotCount(i);
      }

      if(table.getSlotCount(i)  > max ){
         max = table.getSlotCount(i);
      }
      // std::cout << table.getSlotCount(i) << std::endl;
   }
   mean /= static_cast<double>(table.getNumSlots());

   // sum of squared differences
   double sumSquaredDifferences = 0;
   for (int i = 0; i < table.getNumSlots(); ++i) {
      double difference = table.getSlotCount(i) - mean;
      sumSquaredDifferences += difference * difference;
   }

   // standard deviation
   double standardDeviation = std::sqrt(sumSquaredDifferences / table.getNumSlots());

   std::cout << "Total number of unique items: " << total_item << std::endl;
   std::cout << "Mean: " << mean << std::endl;
   std::cout << "Standard Deviation: " << standardDeviation << std::endl;
   std::cout << "Min: " << min << std::endl;
   std::cout << "Max: " << max << std::endl;



   return 0;
}
