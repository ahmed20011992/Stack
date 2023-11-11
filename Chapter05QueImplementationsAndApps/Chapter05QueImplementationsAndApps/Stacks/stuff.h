#ifndef STUFF_H
#define STUFF_H

#include <string>
#include <ostream>




namespace ragstuff {

float dalgoRandom(); // Returnerar ett slumptal mellan 0 och 1

void verifyStudentsName(const std::string &name);

/***********************************************************
 * CLASS:   Slout // Slow Output
 * UPPGIFT: Med denna klass skapar vi globalen slout
 *          som fungerar som cout men ger oss långsammare
 *          utskrift.
 ***********************************************************/
class Slout
{
public:
    Slout( std::ostream &ostr);

    Slout& operator<<(std::ostream& (*pf)(std::ostream&));
    Slout& operator<<(Slout& (*pf)(Slout&));

    Slout& operator<<(const std::string& str);
    Slout& operator<<(int i);
    Slout& operator<<(double f);

    void setNormalSpeed();
    void setFastSpeed();
    void setSlowSpeed();

private:
    std::ostream &m_ostr;
    const int m_normalCharacterDelayInMs = 0;
    const int m_fastCharacterDelayInMs = 0;
    const int m_slowlCharacterDelayInMs = 0;

    int m_characterDelayInMs = m_normalCharacterDelayInMs;
};



Slout& slow(Slout &ostr);
Slout& fast(Slout &ostr);
Slout& normal(Slout &ostr);


extern Slout slout;    // Globalen slout ger oss långsammare utskrift

}
#endif // STUFF_H
