#include "ragnarstest.h"

#include "student2_arrstack.h"

#include <iostream>
#include <string>
#include <cassert>
#include <QThread>
#include <QElapsedTimer>
#include "stuff.h"

using namespace ragstuff;

using namespace std;



static bool stackTest1(){
    slout << endl << "stackTest1, testar att använda två olika stackobjekt." << endl;

    slout << endl << "stack1: Nu skapas första AStack-objektet." << endl;
    AStack stack1;

    slout << "stack1: pushar på talen 1.5, 2.5, 3.5 och 4.5" << endl;

    stack1.pushBack(1.5);
    stack1.pushBack(2.5);
    stack1.pushBack(3.5);
    stack1.pushBack(4.5);

    slout << "stack1: verifierar att back() returnerar 4.5" << endl;
    assert( stack1.back() == 4.5 );

    slout << "stack1: verifierar size är 4" << endl;
    assert( stack1.size() == 4 );


    slout << "stack1: poppa och verifiera att storleken blev 3" << endl;
    stack1.popBack();
    assert( stack1.size() == 3 );



    slout << "  stack2: skapar  stack2" << endl;
    AStack stack2;
    slout << "  stack2: pushar 5 och 6" << endl;
    stack2.pushBack(5);
    stack2.pushBack(6);
    slout << "  stack2: verifierar att size är 2" << endl;
    assert( stack2.size() == 2 );

    slout << "stack1: verifiera att stack1.back()==3.5" << endl;
    assert( stack1.back() == 3.5 );


    slout << "stack1: poppa från stack1 tills size()==0" << endl;
    while( stack1.size() > 0){
        stack1.popBack();
    }

    slout << "stack1: pushar talen 1..25 till stack1" << endl;
    for (int i=1; i<=25; ++i){
        slout << i;
        stack1.pushBack( i );
        if (stack1.size() == i)
            slout << ",";
        else slout << endl << "fel storlek" << endl;
        if (stack1.back() == i)
            slout << " ";
        else slout << endl << "fel back" << endl;
        assert( stack1.size() == i);
        assert( stack1.back() == i);
    }
    slout << endl;

    slout << "Nu kommer destruktorena att köras.." << endl;

    return true;
}




template<class CStack> bool stackTest2(){

    slout << endl << "stackTest2: Tidtagning.." << endl;

    const int big = 1000000;

    slout << "  Testen kommer att pusha " << big << " element till stacken och  mäta hur lång tid det tar. " << endl;
    slout << "  Nu startar testen!" << endl;

    CStack stack;

    QElapsedTimer myTimer;
    myTimer.start();

    for (int i=0;i<big ; ++i){
        stack.pushBack( 1.2 );
        if (big%100==0){

            int duration = myTimer.elapsed();
            if (duration>1000){
                slout << "BUG:  Stacken är för långsam!!!" << endl;
                slout << "      testen avbrots vid i=" << i << "av ("<<big<<")" << endl;

                return false;
            }
        }
    }

    int duration = myTimer.elapsed();
    slout << "  Det tog " << duration << " ms." << endl;
    return true;

}//stackTest2


bool displayTestStartMessage( const char *testName, const char *studentName ){

    slout << endl << endl;
    slout << "------------------------------------------\n";
    slout << "Testing " << testName << " for student:" << studentName << endl;


    verifyStudentsName( studentName );

    return true;
}

bool displayTestStopMessage( const char *testName, bool success ){

    slout << endl << testName << " " << (success? "Lyckades" : "MISSLYCKADES\7") << endl;
    slout << "------------------------------------------\n";
    assert( success );
    return true;
}

//***********************************************************************
// ANROP:   ragnarsTest(  );
// VERSION: 2010-01-15
// UPPFIFT: Testar en eller flera rutiner som studenten har skrivit.
//***********************************************************************
bool ragnarsTest(){

    setlocale(LC_ALL, "Swedish" );


    bool ok = true;


    displayTestStartMessage("AStack" , nameOfStudentAStack() );
    ok = ok && stackTest1();
    ok = ok && stackTest2<AStack>();
    displayTestStopMessage("AStack", ok);


    return ok;

}// ragnarsTest
