// OBS OBS OBS OBS OBS OBS
// Denna fil tillhör INTE rekursionslabbarna, utan en senare laboration!!!!





#include "studentfill2.h"
#include <QDebug>
#include <deque>   // double-ended-que, har du tillåtelse att använda här!

using namespace std;


const char* nameOfStudent2(){
    return "Ahmed Elhasan";
}

// Nedanstående struct kan användas för att lagra koordinater
struct RK {
    RK(int r, int k): _r(r),_k(k) {}
    int _r;
    int _k;
};


// Denna metod visar bara hur man använder en sk deque
void exempelkodDemonstrerarDeque(){

    deque<RK> minQueue;


    qDebug() <<"Demo: vi använder minQueue som en STACK";
    qDebug() <<"      med push_back back och pop_back";

    minQueue.push_back( RK(0,0) );
    minQueue.push_back( RK(1,10) );
    minQueue.push_back( RK(2,20) );

    while (!minQueue.empty()) {
        RK rk = minQueue.back();
        minQueue.pop_back();
        qDebug() << "vi poppar: (" << rk._r << ", " << rk._k << ")";
    }

    qDebug() <<"Demo: vi använder nu minQueue som en FIFO";
    qDebug() <<"      med push_back front och pop_front";

    minQueue.push_back( RK(0,0) );
    minQueue.push_back( RK(1,10) );
    minQueue.push_back( RK(2,20) );

    while (!minQueue.empty()) {
        RK rk = minQueue.front();
        minQueue.pop_front();
        qDebug() << "vi pop_frontar: (" << rk._r << ", " << rk._k << ")";
    }

}



void nonRecursiveFillStack(int r, int k, IDrawingParent *im, QColor colorOld, QColor colorNew){

    //procedure fill(r,k);
    //////////////
    deque<RK> ragnar1;
    ragnar1.push_back(RK(r,k));
    while(ragnar1.size() > 0 ){
       RK zaber = ragnar1.back();
       ragnar1.pop_back();
       int r=zaber._r;
       int k=zaber._k;
       if (im->isInside(r,k) && im->pixel(r,k) == colorOld ){
           im->setPixel(r,k,colorNew);

           ragnar1.push_back(RK (r, k+1));
           ragnar1.push_back(RK(r, k-1));
           ragnar1.push_back(RK(r+1,k));
           ragnar1.push_back(RK(r-1,k));
       }
    }
//    todolist.push_back(RK(r,k));
//    while(todolist.size()>0){
//        RK rk= todolist.back();
//        todolist.pop_back();


//        if (im->isInside(rk._r,rk._k) && im->pixel(rk._r,rk._k)== colorOld){
//            im->setPixel(rk._r,rk._k,colorNew);
//            todolist.push_back(RK(rk._r+1,rk._k));
//            todolist.push_back(RK(rk._r-1,rk._k));
//            todolist.push_back(RK(rk._r,rk._k+1));
//            todolist.push_back(RK(rk._r,rk._k-1));
//        }
//    }
}
void nonRecursiveFillFifo(int r, int k, IDrawingParent *im, QColor colorOld, QColor colorNew){
    deque<RK> todolist;

    //////////////
    todolist.push_front(RK(r,k));
    while(todolist.size()>0){
         RK rk= todolist.front();
         todolist.pop_front();


        if (im->isInside(rk._r,rk._k) && im->pixel(rk._r,rk._k)== colorOld){
            im->setPixel(rk._r,rk._k,colorNew);
            todolist.push_back(RK(rk._r+1,rk._k));
            todolist.push_back(RK(rk._r-1,rk._k));
            todolist.push_back(RK(rk._r,rk._k+1));
            todolist.push_back(RK(rk._r,rk._k-1));


        }



    }
    ///todolist.pop_front();
}
