#include "modeltest.h"
#include "model.h"
#include <QDebug>
#include <QTextStream>




void ModelTest::testNormalModel()
{
    QString test = "v 1 2 3\n v 4 5 6\n v 56 13 1\n f 1 2 3";
    Model model;
    QTextStream stream(&test);
    QString errInput = model.importModel(stream);
    //qDebug() << errStr;

    //QVERIFY(errInput);
    QCOMPARE(QString(errInput), QString("Success"));
}

void ModelTest::testVertexStrWithoutComponents()
{
    QString test = "v 1 2 3 \n v\n v 56 13 1\n f 1 2 3";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);
    //qDebug() << errStr;

    //QVERIFY(errInput);
    QCOMPARE(QString(errInput), QString("Incorrect count of component in vertex (line 2)"));
}

void ModelTest :: testVertexFloatComponent()
{
    QString test = "v 1.5 5 1";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);
    //qDebug() << errStr;

    //QVERIFY(errInput);
    QCOMPARE(QString(errInput), QString("Success"));
}

void ModelTest :: testVertexDoubleDotInNumber()
{
    QString test = "v 3.56.3 5 1";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);
    //qDebug() << errStr;

    //QVERIFY(errInput);
    QCOMPARE(QString(errInput), QString("Input vertex string contents letters or wrong symbols (line 1)"));
}

void ModelTest :: testNotNumberInputInVertex03()
{
    QString test = "v a1.5 5b 1";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);
    //qDebug() << errStr;

    //QVERIFY(errInput);
    QCOMPARE(QString(errInput), QString("Input vertex string contents letters or wrong symbols (line 1)"));
}

void ModelTest::testEmptyStringInputInVertex()
{
    QString test = "v 1 2 3\n\nv 56 13 1\nv 56 13 115\n f 1 2 3";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);
    //qDebug() << errStr;

    //QVERIFY(errInput);
    QCOMPARE(QString(errInput), QString("Success"));
}

void ModelTest::testNotNumberInputInVertex01()
{
    QString test = "v 1 2 3\n v lox 5 1\n v 56 13 1\n f 1 2 3";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);
    //qDebug() << errStr;

    //QVERIFY(errInput);
    QCOMPARE(QString(errInput), QString("Input vertex string contents letters or wrong symbols (line 2)"));
}

void ModelTest::testNotNumberInputInVertex02()
{
    QString test = "v 1 2 3\n v 1 lox 7.3\n v 56 13 1\n f 1 2 33";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);
    //qDebug() << errStr;

    //QVERIFY(errInput);
    QCOMPARE(QString(errInput), QString("Input vertex string contents letters or wrong symbols (line 2)"));
}

void ModelTest::testLessStrLengthInVertex01()
{
    QString test = "v 1 2 3\n v 5 1\n v 56 13 1\n f 1 2 3";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);
    //qDebug() << errStr;

    //QVERIFY(errInput);
    QCOMPARE(QString(errInput), QString("Incorrect count of component in vertex (line 2)"));
}

void ModelTest::testExtraStrLengthInVertex01()
{
    QString test = "v 1 2 3\n v 2 5 1 76\n v 56 13 1\n f 1 2 3";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);
    //qDebug() << errStr;

    //QVERIFY(errInput);
    QCOMPARE(QString(errInput), QString("Incorrect count of component in vertex (line 2)"));
}

void ModelTest :: testEmptyInputStringInFace()
{
    QString test = "v 1 2 3\n v 2 5 1\n v 56 13 1\n f 2 3";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);

    QCOMPARE(QString (errInput), QString("Incorrect count of component in face (line 4)"));
}

void ModelTest :: testWrongFormatInputInFace01()
{
    QString test = "v 1 2 3\n v 2 5 1\n v 56 13 1\n f 1 p2 3";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);

    QCOMPARE(QString (errInput), QString("Input face string has wrong format (line 4)"));
}

void ModelTest :: testWrongFormatInputInFace02()
{
    QString test = "v 1 2 3\n v 2 5 1\n v 56 13 1\n f 1/ p/2 3";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);

    QCOMPARE(QString (errInput), QString("Input face string has wrong format (line 4)"));
}

void ModelTest :: testWrongFormatInputInFace03()
{
    QString test = "v 1 2 3\n v 2 5 1\n v 56 13 1\n f 1//1 1//2 3/5/";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);

    QCOMPARE(QString (errInput), QString("Input face string has wrong format (line 4)"));
}

void ModelTest :: testRightRefferenceInFace01()
{
    QString test = "v 1 2 3\n v 2 5 1\n v 56 13 1\n vn 1 2 3\n vn 2 5 1\n vn 56 13 1\n f 2//2 1//3 3//1";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);

    QCOMPARE(QString (errInput), QString("Success"));
}

void ModelTest :: testRightRefferenceInFace02()
{
    QString test = "v 1 2 3\n v 2 5 1\n v 56 13 1\n v 10 20 30\n f 4 1 3\n f 2 1 4";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);

    QCOMPARE(QString (errInput), QString("Success"));
}

void ModelTest :: testWrongRefferenceInFace01()
{
    QString test = "v 1 2 3\n v 2 5 1\n v 56 13 1\n vn 1 2 3\n vn 2 5 1\n vn 56 13 1\n f 4//2 1//3 3//1";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);

    QCOMPARE(QString (errInput), QString("Refference on unexistable vertex (line 7)"));
}

void ModelTest :: testWrongRefferenceInFace02()
{
    QString test = "v 1 2 3\n v 2 5 1\n v 56 13 1\n vn 1 2 3\n vn 2 5 1\n vn 56 13 1\n f 2//2 1//3 3//4";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);

    QCOMPARE(QString (errInput), QString("Refference on unexistable normal vector (line 7)"));
}

void ModelTest :: testWrongRefferenceInFace03()
{
    QString test = "v 1 2 3\n v 2 5 1\n v 56 13 1\n v 10 20 30\n f 3 -1 2\n f 2 1 4";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);

    QCOMPARE(QString (errInput), QString("Input face string has wrong format (line 5)"));
}

void ModelTest :: testInputRefOnDifComponentInFace()
{
    QString test = "v 1 2 3\n v 2 5 1\n v 56 13 1\n vn 1 2 3\n vn 2 5 1\n vt 56 13 1\n f 1//1 3 2/1";
    Model model;
    QTextStream stream(&test);
    //QTextStream* stream  = new QTextStream(&test);
    QString errInput = model.importModel(stream);

    QCOMPARE(QString (errInput), QString("Success"));
}
