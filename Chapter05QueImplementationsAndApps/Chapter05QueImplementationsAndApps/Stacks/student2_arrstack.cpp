#include "student2_arrstack.h"
#include <assert.h>

const char* nameOfStudentAStack(){
    return "Ahmed Elhasan";
}



AStack::AStack()
{
    // TODO
    m_capacity=10;
    m_pArr= new float [m_capacity];
    m_size=0;


}


AStack::~AStack()
{

   delete [] m_pArr;
}

void AStack::pushBack(float value){

    if ( m_size == m_capacity){
        float *Newarr= new float [m_capacity*2];
        for(int i =0; i < m_capacity ; i++)
            m_pArr[i] = Newarr[i];
        float *oldpArr = m_pArr;
         m_pArr = Newarr;
         delete [] oldpArr;
         m_capacity = m_capacity*2;


    }

    m_pArr[m_size]=value;
    m_size +=1;
}


float &AStack::back()
{
    //
    return m_pArr[m_size-1]; // felaktig kodrad, tag bort

}

void AStack::popBack()
{
    m_size-=1;
}

int AStack::size() const
{
    // TODO
    return m_size;
}




void studentTest2(){

}

/******** kommentar som efterfrågades i "öka istället linjärt"

  blev det någon skillnad när du ökade arraystorleken med 10 istället för med dubbleing?



 ***********************************************************************/
