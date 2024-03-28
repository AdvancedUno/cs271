#include <ctime>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

// Info structure for binary tree
class Info {
private:
    char data;
    int freq;

public:
	Info		                    ( void );   //Default constructor
	Info		                    ( char data, int freq );   //Default constructor
    bool        operator<	        ( const Info &myInfo ) const;
    bool        operator>	        ( const Info &myInfo ) const;
    bool        operator<=	        ( const Info &myInfo ) const;
    bool        operator>=	        ( const Info &myInfo ) const;
    bool        operator==	        ( const Info &myInfo ) const;
    bool        operator!=	        ( const Info &myInfo ) const;
    Info        operator+	        ( const Info &myInfo );
    friend ostream & operator<< ( ostream &os, const Info &myInfo )
    {
        os << "[ ";
        os << "char : " << myInfo.data << "  freq : " << myInfo.freq;
        os << "]";
        return os;
    }

};


//==============================================
// Info(void)
// Contructor for BT class
// INPUT: none
// RETURN: none
//==============================================
Info::Info( void ){

    data = 0;
    freq = 0;

}


//==============================================
// Info(void)
// Contructor for BT class
// INPUT: none
// RETURN: none
//==============================================
Info::Info( char data, int freq ){

    this->data = data;
    this->freq = freq;

}



//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool Info::operator< ( const Info &myInfo ) const {



    return freq < myInfo.freq;

}

//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool Info::operator<= ( const Info &myInfo ) const {



    return freq <= myInfo.freq;

}



//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool Info::operator> ( const Info &myInfo ) const {



    return freq > myInfo.freq;

}



//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool Info::operator>= ( const Info &myInfo ) const {



    return freq >= myInfo.freq;

}



//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool Info::operator!= ( const Info &myInfo ) const {



    return freq != myInfo.freq;

}



//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool Info::operator== ( const Info &myInfo ) const {



    return freq == myInfo.freq;

}


Info  Info::operator+ ( const Info &myInfo ){
    Info newInfo;
    newInfo.data = 0;
    newInfo.freq = freq + myInfo.freq;
    return newInfo;
}







