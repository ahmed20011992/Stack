#include <QCoreApplication>
#include "studentstest.h"

#include "ragnarstest.h"

#include "stuff.h"
#include <iostream>

using namespace std;
using namespace ragstuff;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    slout   << "--------------------"  << endl
            << "Valkommen till Queues" << endl
            << "Nu kor vi studenttest" << endl
            << "--------------------"  << endl
            << endl;


    studentstest();

    bool testAQue  = true;    // Ange vilka tester du vill genomföra !
    bool testLQue   = false;
    bool testADeque   = true;

    ragnarsTest(testAQue, testLQue, testADeque);


    return a.exec();
}

