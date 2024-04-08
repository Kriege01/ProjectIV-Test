#include <QtCore/QCoreApplication>
#include <QtTest>
#include "TestFunctions.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Manually print the names of all test cases
    qDebug() << "Running test cases:";
  
    // Run the tests
    QTest::qExec(new TestFunctions, argc, argv);

    return 0;
 
}
