#include "student3_listque.h"
#include "assert.h"


const char* nameOfStudentLQue(){
    return "Ahmed Elhasan";
}



LQue::LQue()
{
// TODO

}

LQue::~LQue()
{

}

void LQue::pushBack(float value)
{


}

float &LQue::back()
{
  return (*m_pBack).m_value; // felaktig rad tag bort!

}

void LQue::popFront()
{
  assert( m_size>0 );


}

float &LQue::front()
{
    assert( m_size> 0);
    return m_pFront->m_value; //felaktig rad tag bort!
}

int LQue::size() const
{
    return 0; // felaktig rad tag bort!
}
