#include "ragnarstest.h"


#include "student3_listque.h"
#include "student4_arrayque.h"
#include "student5_adeque.h"

#include "stuff.h"

#include <iostream>
#include <string>
#include <deque>
#include <assert.h>
#include <QDebug>
#include <cassert>
#include <chrono>
#include <thread>


using namespace std;
using namespace ragstuff;




bool  ALLOK = true;

bool equalEndings(ADeque &q1, std::deque<float>  &q2){
    if (q1.size() == 0 && q2.size()==0)
        return true;

    return  q1.size() == int(q2.size()) && q1.front() == q2.front()  && q1.back() == q2.back();
}

bool dequePushBack(ADeque &q1, std::deque<float>  &q2){
    float v = dalgoRandom();

    q1.pushBack( v );
    q2.push_back( v );

    return equalEndings(q1,q2);
}

bool dequePushFront(ADeque &q1, std::deque<float>  &q2){
    float v = dalgoRandom();

    q1.pushFront( v );
    q2.push_front( v );
    return equalEndings(q1,q2);
}

bool dequePopBack(ADeque &q1, std::deque<float>  &q2){

    if (q2.size()>0){
        q1.popBack(  );
        q2.pop_back( );
    }
    return equalEndings(q1,q2);
}


bool dequePopFront(ADeque &q1, std::deque<float>  &q2){
   if (q2.size()>0){
        q1.popFront( );
        q2.pop_front( );
   }
    return equalEndings(q1,q2);
}




bool ragnarsDequetest(int lev ){
    if (lev==0)
        slout << "  testar en instans av ADeque " << endl;
    else slout << "  testar en annan instans av ADeque " << endl;

    ADeque q1;
    deque<float>  q2;

    bool ok = true;
    int maxSize = 0;
    for (int i=0; i<1000000 && ok; i+=1){

        float prcIncrease = 0.5;
        float prcDecrease = 0.5;

        if (i>10000 && i<20000)
            prcIncrease = 0.7;
        if (i>9000)
            prcDecrease = 0.9;

        if (ok && lev==0 && i == 108)
            ok = ragnarsDequetest(1);

        if (dalgoRandom() < prcIncrease)
            ok = ok && dequePushBack((q1), (q2));
        if (dalgoRandom() < prcIncrease)
            ok = ok && dequePushFront((q1), (q2));
        if (dalgoRandom() < prcDecrease)
            ok = ok & dequePopBack((q1), (q2));
        if (dalgoRandom() < prcDecrease)
            ok = ok && dequePopFront((q1), (q2));

        if (q1.size()>maxSize)
            maxSize = q1.size();
    }
    return ok;
}



void tst(bool err, string str)
{
  if (err)
    { slout << str << endl;
      assert( false );
    }
}


// ändra ej på denna funktion
template<typename Que> bool ragnarsKoeTest(int lev=0)
{
  if (lev==0)
    slout << "  testar den första instansen av en ko" << endl;
  else slout << "  testar en andra instans av an ko" << endl;


  float arr[100];
  for (int i=0 ; i<100; ++i)
    arr[i] = dalgoRandom();

  Que que;

  tst(que.size()!=0, "initial size() ar ej noll");

  slout << "  " << lev << " anropar pushBack 8 ggr" << endl;
  for (int i=0; i< 8 ; ++i)
    que.pushBack( arr[i] );

  tst(que.size()!=8, "  size() okade inte till 8");

  tst(que.front()!=arr[0], "  front() returnerade fel" );
  tst(que.back()!=arr[7],  "  back() returnerade fel"  );

  if (lev==0) ragnarsKoeTest<Que>(1);

  slout << "  " << lev << "  kommer att omvaxklande anropa popFront och pushBack" << endl;

  int iRemove = 0;
  for (int i=8 ; i<20 ; ++i)
  {
    tst(que.front()!=arr[iRemove], "  front() returnerar fel" );
    que.popFront();

    ++iRemove;
    tst(que.size()!=7, "  size() returnerar ej 7");
    que.pushBack(arr[i]);
    tst(que.back()!=arr[i], "  back() returnerar fel");
  }

  return true;
}



bool displayTestStartMessage( const char *testName, const char *studentName ){

    slout << "------------------------------------------" << endl
          << " Testing " << testName << " for student " << studentName << endl;

    verifyStudentsName( nameOfStudentLQue() );

    return true;
}

bool displayTestStopMessage( const char *testName, bool success ){

    slout << endl
          << endl
          << testName << (success? " Lyckades" : " MISSLYCKADES\7") << endl
          << "------------------------------------------" << endl;
    assert( success );
    return true;
}



//***********************************************************************
// ANROP:   ragnarsTest( testQue, testLQue, testADeque );
// VERSION: 2010-01-15
// UPPFIFT: Testar en eller flera rutiner som studenten har skrivit.
//***********************************************************************
bool ragnarsTest(bool testAQue, bool testLQue, bool testADeque){
    setlocale(LC_ALL, "Swedish" );


    slout << "ragnarsTest" << endl;

    bool ok = true;

    if (testLQue){
        displayTestStartMessage("LQue", nameOfStudentLQue() );

        ok = ragnarsKoeTest<LQue>();
        if (ok)
            slout << "(LQue lyckades! Jag har dock inte testat minnesläckor! " << endl
                  << " Verifiera själv att destruktor och pop inte läcker!)" << endl;
        displayTestStopMessage("LQue", ok);
    }
    else cout << "LQue kommer ej att testas (andra detta i main)" << endl;

    if (testAQue){
        displayTestStartMessage("AQue", nameOfStudentAQue() );
        ok = ragnarsKoeTest<AQue>();

        if (ok)
            slout << "(AQue lyckades!" << endl
                  << "  Jag har dock inte testat minnesläckor!" << endl
                  << "     Verifiera själv att destruktor och pop inte läcker" << endl
                  << "  Jag har inte heller testat om kon kan växa." << endl
                  << "     Se uppdrags-PM for hur man testar detta.) " << endl;
        displayTestStopMessage("AQue", ok);
    }
    else slout << "AQue kommer ej att testas (andra detta i main)" << endl;


    if (testADeque){
        displayTestStartMessage("ADeque", nameOfStudentADeque() );

        ok = ragnarsDequetest(0);

        if (ok)
            slout << "(ADeque lyckades! Jag har dock inte testat minnesläckor!"  << endl
                  << " Verifiera själv att destruktor och pop inte läcker)" << endl;

        displayTestStopMessage("ADeque", ok);
    }
    else slout << "ADeque kommer ej att testas (andra detta i main)" << endl;

    return ok;


}// ragnarsTest
