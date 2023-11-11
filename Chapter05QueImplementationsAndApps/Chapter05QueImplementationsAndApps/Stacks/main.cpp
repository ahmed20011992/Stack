#include <QCoreApplication>
#include "qcoreapplication.h"
#include "ragnarstest.h"

#include "student2_arrstack.h"



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    studentTest2();

    ragnarsTest();

    return a.exec();

}
