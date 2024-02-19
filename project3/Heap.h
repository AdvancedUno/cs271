//===============================
// Heap.h
// Heap data structure with method implementations
// Name: EunHo Lee, Ritika Shrestha, Tomer
// Date: 23 Feb 2024
//===============================

#include <iostream>
#include <string>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

template <class T> 
class Heap
{
private:

	

	
public:
	Heap		( void );
	Heap		( const List<T> &mylist );
	~Heap		( void );
List<T> operator=	( const List<T> &mylist );
void	prepend	( const T &item);
void	append		( const T &item );
T &	operator[]	( int index );
void	insert		( const T &item, int index );
void	remove		( int index );
int	search		( const T &item ) const;
int	length		( void ) const;
bool	empty		( void ) const;
List<T> concat		( const List<T> &list ) const;

friend ostream & operator<< ( ostream &os, List<T> &mylist )
{



}





};


#endif











