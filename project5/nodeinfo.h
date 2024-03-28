#ifndef INFO_H
#define INFO_H

#include <iostream>
using namespace std;
class NodeInfo {
private:
    char dataC;
    int  freq;

public:
    NodeInfo(); //Default constructor
    NodeInfo(char data, int freq); //Parameterized constructor
    NodeInfo( const NodeInfo &myNodeInfo ); // copy constructor

    ~NodeInfo(); //Default destructor
    bool operator<(const NodeInfo &myInfo) const;
    bool operator>(const NodeInfo &myInfo) const;
    bool operator<=(const NodeInfo &myInfo) const;
    bool operator>=(const NodeInfo &myInfo) const;
    bool operator==(const NodeInfo &myInfo) const;
    bool operator!=(const NodeInfo &myInfo) const;
    NodeInfo operator+ ( const NodeInfo &myNodeInfo ) const;
    int getFreq(void);
    char getChar(void);

    friend ostream & operator<< (std::ostream &os, const NodeInfo &myInfo){
        os << "[ ";
        os<< "(" << myInfo.freq << "," << myInfo.dataC << ")" << "  ";
        os << "]";
        return os;
    };
};

#endif

//==============================================
// Info(void)
// Contructor for BT class
// INPUT: none
// RETURN: none
//==============================================
NodeInfo::NodeInfo( void ){

    dataC = 0;
    freq = 0;

}

NodeInfo::NodeInfo( const NodeInfo &myNodeInfo ){
    dataC = myNodeInfo.dataC;
    freq = myNodeInfo.freq;
}




//==============================================
// Info(void)
// Contructor for BT class
// INPUT: none
// RETURN: none
//==============================================
NodeInfo::NodeInfo( char data, int freq ){

    this->dataC = data;
    this->freq = freq;

}

//==============================================
// Info(void)
// Contructor for BT class
// INPUT: none
// RETURN: none
//==============================================
NodeInfo::~NodeInfo( void ){
    
}


//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool NodeInfo::operator< ( const NodeInfo &myInfo )const{

    return freq < myInfo.freq;

}

//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool NodeInfo::operator <= ( const NodeInfo &myInfo )const{



    return freq <= myInfo.freq;

}



//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool NodeInfo::operator > ( const NodeInfo &myInfo )const{



    return freq > myInfo.freq;

}



//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool NodeInfo::operator>= ( const NodeInfo &myInfo )const{



    return freq >= myInfo.freq;

}



//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool NodeInfo::operator!= ( const NodeInfo &myInfo )const{



    return freq != myInfo.freq;

}



//==============================================
// operator< ( const Info &myInfo  )
// compare operator.
// INPUT: const Info &myInfo
// RETURN: bool
//==============================================
bool NodeInfo::operator== ( const NodeInfo &myInfo )const{



    return freq == myInfo.freq;

}




//==============================================

//==============================================
int NodeInfo::getFreq(void){



    return freq;

}


//==============================================

//==============================================
char NodeInfo::getChar(void){

    return dataC;

}

NodeInfo  NodeInfo::operator+ ( const NodeInfo &myNodeInfo ) const{
    NodeInfo newInfo;
    newInfo.dataC = 0;
    newInfo.freq = freq + myNodeInfo.freq;
    return newInfo;
}




