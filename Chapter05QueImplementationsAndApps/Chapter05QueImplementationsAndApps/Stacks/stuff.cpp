#include "stuff.h"

#include <iostream>
#include <string>

#include <chrono>
#include <thread>
#include <random>
#include <assert.h>

using namespace  std;
using namespace chrono;
using namespace  this_thread;




namespace ragstuff{

Slout slout( cout );


/*********************************************************
 * ANROP:   dalgoRandom(  );
 * UPPGIFT: Returnerar ett slumptal i intervallet [0,1).
 *********************************************************/
float dalgoRandom(){
    static bool seeded = false;
    static std::default_random_engine e;
    static std::uniform_real_distribution<> dis(0, 1); // rage 0 - 1
    if (!seeded){
        static std::random_device rd;
        e.seed(rd());
        seeded = true;
    }
    return dis(e);
}


/*************************************************
 * ANROP:  verifyStudentsName( studentsName );
 * UPPGIFT: Kollar att studenter ändrat namnet från
 *          "Homer Simpson" till ngt annat.
 *          Krashar om så icke är fallet.
 **************************************************/
void verifyStudentsName(const std::string &name){
    if (name == "Homer Simpson"){
        slout << "Students name is incorrect! " << endl
              << slow
              << "==> I will crash! " << endl;
        assert( false );
    }
}





Slout::Slout(std::ostream &ostr)
    : m_ostr( ostr )
{

}

Slout &Slout::operator<<(ostream &(*pf)(std::ostream &))
{
    m_ostr << pf;
    return *this;
}

void Slout::setNormalSpeed(){
    m_characterDelayInMs = m_normalCharacterDelayInMs;
}

void Slout::setFastSpeed(){
    m_characterDelayInMs = m_fastCharacterDelayInMs;
}

void Slout::setSlowSpeed(){
    m_characterDelayInMs = m_slowlCharacterDelayInMs;
}


Slout& Slout::operator<<(Slout& (*pf)(Slout&)){
    pf( *this );
    return *this;
}



Slout& Slout::operator<<(const string& str){
    for (unsigned int i=0; i<str.size(); i+=1){
        m_ostr << str[i];
        m_ostr << flush;
        if (str[i]=='-' || str[i]=='_')
             sleep_for( milliseconds(m_fastCharacterDelayInMs));
        else sleep_for( milliseconds(m_characterDelayInMs));
    }
    return *this;
}

Slout& Slout::operator<<(int i){
    *this << to_string(i);
    return *this;
}

Slout& Slout::operator<<(double f){
    *this << to_string(f);
    return *this;
}



Slout& slow(Slout &ostr){
    ostr.setSlowSpeed();
    return ostr;
}

Slout& fast(Slout &ostr){
    ostr.setFastSpeed();
    return ostr;
}

Slout& normal(Slout &ostr){
    ostr.setNormalSpeed();
    return ostr;
}
}
