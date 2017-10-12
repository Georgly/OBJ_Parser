#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

class OBJParse//
{
public:

    OBJParse()
    {

    }

    static QVector<QString> Parser(QString fileName)
    {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;

        QVector<QString> lines();
        while(!file.atEnd())
        {
            QString line = file.readLine();
            if (line.trimmed()[0] != '#')
            {
                lines << line;
            }
        }

        return lines;
    }
};

class Vertex
{
public:
    float x, y, z;

    Vertex()
    {
        x = 0;
        y = 0;
        z = 0;
    }
    Vertex(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

};

class NormalVector//
{
public:
    float x, y, z;

    NormalVector(){}
    NormalVector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class TextureCoord//
{
public:
    float u, v, w;

    TextureCoord() {
        u = 0;
        v = 0;
        w = 0;
    }

    TextureCoord(float u, float v, float w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class Face
{
public:
    QList<int> vertexIndex();
    QList<int> textureCoordIndex();
    QList<int> normalVectorIndex();

    Face()
    {}
};

class Model
{
private:
    QVector<Vertex> vertexModel();
    QVector<NormalVector> normalVectorModel();
    QVector<TextureCoord> textureCoordModel();

public:

    Model(){
//        vertexModel = new QList<Vertex>();
//        normalVectorModel = new QList<NormalVector>();
//        textureCoordModel = new QList<TextureCoord>();
    }

    void CreateVertexModel(QString fileName){
        QVector<QString> vertexList = OBJParse.Parser(fileName);
        int length = vertexList.count();

        for (int i = 0; i < length; i++)
        {
            QStringList vertexStr = vertexList[i].split(' ',  QString::SkipEmptyParts);
            if(vertexStr[0] == "v")
            {
                Vertex vertex = new Vertex(vertexStr[1].toFloat(),
                        vertexStr[2].toFloat(),
                        vertexStr[3].toFloat());
                vertexModel << vertex;
            }
            else if(vertexStr[0] == "vn")
            {
                NormalVector normalVector = new NormalVector(vertexStr[1].toFloat(),
                        vertexStr[2].toFloat(),
                        vertexStr[3].toFloat());
                normalVectorModel << normalVector;
            }
            else if(vertexStr[0] == "vt")
            {
                TextureCoord textureV = new TextureCoord(vertexStr[1].toFloat(),
                        vertexStr[2].toFloat(),
                        vertexStr.count() == 3 ? 0 : vertexStr[3].toFloat());
                textureCoordModel << textureV;
            }
            else if(vertexStr[0] == "f")
            {
                Face face = new Face();
                for (int j = 1; j < vertexStr.count(); j++)
                {
                    QStringList indexes = vertexStr[j].split('/');
                    switch (indexes.count()) {
                    case 1:
                    {
                        face.vertexIndex() << indexes[0];
                        break;
                    }
                    case 2:
                    {
                        face.vertexIndex() << indexes[0];
                        face.textureCoordIndex() << indexes[1];
                        break;
                    }
                    case 3:
                    {
                        face.vertexIndex() << indexes[0];
                        if (indexes[1] != "")
                        {
                            face.textureCoordIndex() << indexes[1];
                        }
                        face.normalVectorIndex() << indexes[2];
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
        }
    }
};
