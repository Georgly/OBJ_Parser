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

    static void Parser(QString fileName)
    {
        QFile file(fileName);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;

        QList<QString> lines = new QList<QString>();
        while(!file.atEnd())
        {
            QString line = file.readLine();
            if (line.trimmed()[0] != '#'){
                lines << line;
            }
        }

        return lines;
    }
};

class Vertex
{
public:
    double x, y, z;

    Vertex() {
        x = 0;
        y = 0;
        z = 0;
    }
    Vertex(double x, double y, double z) : base() {
        this->x = x;
        this->y = y;
        this->z = z;
    }

};

class NormalVector : Vertex//
{
public:
    double x, y, z;

    NormalVector() : base() {}
    NormalVector(double x, double y, double z) : base(x, y, z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class TextureCoord//
{
public:
    double u, v, w;

    TextureCoord() {
        u = 0;
        v = 0;
        w = 0;
    }

    TextureCoord(double u, double v, double w) : base(){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class Model
{
public:
    QList<Vertex> vertexModel;
    QList<NormalVector> normalVectorModel;
    QList<TextureCoord> textureCoordModel;

    Model(){
        vertexModel = new QList<Vertex>();
        normalVectorModel = new QList<NormalVector>();
        textureCoordModel = new QList<TextureCoord>();
    }

    void CreateVertexModel(QString fileName){
        QList<QString> vertexList = OBJParse.Parser(fileName);
        int length = vertexList.count();

        for (int i = 0; i < length; i++)
        {
            QStringList vertexStr = vertexList[i].split(' ',  QString::SkipEmptyParts);
            switch (vertexStr[0])
            case "v":
            {
                Vertex vertex = new Vertex(vertexStr[1].toDouble(),vertexStr[2].toDouble(),vertexStr[3].toDouble());
                vertexModel << vertex;
                break;
            }
            case "vn":
            {
                NormalVector normalVector = new NormalVector(vertexStr[1].toDouble(),vertexStr[2].toDouble(),vertexStr[3].toDouble());
                normalVectorModel << normalVector;
                break;
            }
            case "vt":
            {
                TextureCoord textureV = new TextureCoord(vertexStr[1].toDouble(),vertexStr[2].toDouble(),
                        vertexStr[3].toDouble() == null ? 0 : vertexStr[3].toDouble());
                textureCoordModel << textureV;
                break;
            }
            case "f"://см определение сторон
            {
                break;
            }
        }
    }
};
