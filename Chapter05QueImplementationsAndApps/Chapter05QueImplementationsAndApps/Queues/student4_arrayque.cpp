#include "student4_arrayque.h"
#include "assert.h"
#include <cassert>

const char* nameOfStudentAQue(){
    return "Ahmed Elhasan";
}

float *m_pArr;
int    m_indexOfFront;
int    m_size;
int    m_capacity;

AQue::AQue()
{
    m_capacity=10;
    m_pArr= new float [m_capacity];
    m_size=0;
    m_indexOfFront =0;


}

AQue::~AQue()
{
    delete [] m_pArr;
    m_pArr= nullptr;
}


void AQue::pushBack(float value)
{
    assert( m_size < m_capacity);
    m_pArr[ (m_indexOfFront + m_size)% m_capacity]= value;
    m_size+=1;





//    if ( m_size == m_capacity ){
//        float *m_pArr2= new float [m_capacity *2];
//        for(int i =0 ; i< m_capacity ; i++){
//            m_pArr2[i] = m_pArr[i+m_indexOfFront];
//        }
//        float *pOldArr = m_pArr;
//        m_pArr = m_pArr2;
//        delete pOldArr;
//    }
//    m_pArr[(m_indexOfFront +m_size)% m_capacity];
}

float &AQue::back()
{
    // TODO
    assert(m_size>0);
    return m_pArr[(m_indexOfFront + m_size-1)% m_capacity];
}

void AQue::popFront()
{
    // TODO
//    m_indexOfFront+=1;
//    if(m_indexOfFront>=m_capacity)
//        m_indexOfFront-=m_capacity;
    assert( m_size >0);
    m_indexOfFront = (m_indexOfFront +1)% m_capacity;
    m_size -=1;

}

float &AQue::front()
{
    // TODO
    assert(m_size>0);
    return m_pArr[m_indexOfFront]; // felaktig kodrad, tag bort
}


int AQue::size() const
{
    // TODO
    return m_size; // felaktig kodrad, tag bort
}

