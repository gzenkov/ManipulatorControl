#ifndef LINK_H
#define LINK_H

#include <QObject>
#include <3rdparty/Eigen/Eigen/Dense>
#include <QtMath>

class Link
{
public:
    Link();
    Link(double inParam[4]);
    ~Link();

    union
    {
        double param[4];
        struct
        {
            double d;
            double a;
            double q;
            double alfa;
        };
    };

    qint8 genCoorIndex;

    void setCoor(double value, qint8 index);
    void setGenCoor(quint8 index);
    void deleteGenCoor();

    //Eigen::Matrix4d *transMat() {return &m_transMat;}

    Eigen::Matrix4d *transMatPtr;

//private:
    Eigen::Matrix4d m_transMat;
};

inline void Link::setCoor(double value, qint8 index)
{
    switch (index) {
    case 0:
        d = value;

        m_transMat(2,3) = value;
        break;
    case 1:
        a = value;

        m_transMat(0,3) = value * qCos(q);
        m_transMat(1,3) = value * qSin(q);
        break;
    case 2:
        q = value;

        m_transMat(0,0) = qCos(value);
        m_transMat(1,0) = qSin(value);
        m_transMat(0,1) = - qCos(alfa) * qSin(value);
        m_transMat(1,1) = qCos(alfa) * qCos(value);
        m_transMat(0,2) = qSin(alfa) * qSin(value);
        m_transMat(1,2) = - qSin(alfa) * qCos(value);
        m_transMat(0,3) = a * qCos(value);
        m_transMat(1,3) = a * qSin(value);
        break;
    case 3:
        alfa = value;

        m_transMat(2,1) = qSin(value);
        m_transMat(2,2) = qCos(value);
        m_transMat(0,1) = - qCos(value) * qSin(q);
        m_transMat(1,1) = qCos(value) * qCos(q);
        m_transMat(0,2) = qSin(value) * qSin(q);
        m_transMat(1,2) = - qSin(value) * qCos(q);
        break;
    }
}

#endif // LINK_H

//Q_DECLARE_TYPEINFO(Link,Q_MOVABLE_TYPE);

