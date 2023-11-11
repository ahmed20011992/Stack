#ifndef STUDENTSARRSTACK_H
#define STUDENTSARRSTACK_H

const char* nameOfStudentAStack();


class AStack
{
    // Till studenten: Man får ändra på denna privata del av klassen om man vill

    float *m_pArr;
    int    m_size;
    int    m_capacity;

public:
    // Till studenten: implementera dessa metoder i cpp-filen

    AStack();
    ~AStack();

    // nedanstående metoder skall ha en genomsnittlig komplexitet O(1)

    void pushBack(float value);
    float &back();
    void  popBack();
    int   size()  const;

};



void studentTest2();



#endif // STUDENTSARRSTACK_H
