#ifndef MODELTEST_H
#define MODELTEST_H

#include <QObject>
#include <QTest>

class ModelTest : public QObject
{
    Q_OBJECT


private slots:
    void testNormalModel();
    void testVertexStrWithoutComponents();
    void testEmptyStringInputInVertex();
    void testVertexFloatComponent();
    void testVertexDoubleDotInNumber();
    void testNotNumberInputInVertex01();
    void testNotNumberInputInVertex02();
    void testNotNumberInputInVertex03();
    void testLessStrLengthInVertex01();
    void testExtraStrLengthInVertex01();
    void testEmptyInputStringInFace();
    void testWrongFormatInputInFace01();
    void testWrongFormatInputInFace02();
    void testWrongFormatInputInFace03();
    void testRightRefferenceInFace01();
    void testRightRefferenceInFace02();
    void testWrongRefferenceInFace01();
    void testWrongRefferenceInFace02();
    void testWrongRefferenceInFace03();
    void testInputRefOnDifComponentInFace();
};

#endif // MODELTEST_H
