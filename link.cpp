#include "link.h"
#include <QDebug>

Link::Link() :
    genCoorIndex(-1),
    d(0),
    a(0),
    q(0),
    alfa(0),
    transMatPtr(&m_transMat),
    m_transMat(Eigen::Matrix4d::Zero())
{
    m_transMat(0,0) = 1;
    m_transMat(1,1) = 1;
    m_transMat(2,2) = 1;
    m_transMat(3,3) = 1;
}

Link::Link(double inParam[4]) :
    genCoorIndex(-1),
    transMatPtr(&m_transMat),
    m_transMat(Eigen::Matrix4d::Zero())
{
    memcpy(param,inParam,sizeof(inParam));

    //translation matrix
    m_transMat(0,0) = qCos(q);
    m_transMat(0,1) = - qCos(alfa) * qSin(q);
    m_transMat(0,2) = qSin(alfa) * qSin(q);
    m_transMat(0,3) = a * qCos(q);
    m_transMat(1,0) = qSin(q);
    m_transMat(1,1) = qCos(alfa) * qCos(q);
    m_transMat(1,2) = - qSin(alfa) * qCos(q);
    m_transMat(1,3) = a * qSin(q);
    m_transMat(2,1) = qSin(alfa);
    m_transMat(2,2) = qCos(alfa);
    m_transMat(2,3) = d;

    m_transMat(3,3) = 1;
}

Link::~Link()
{
    //qDebug() << "huy";
}

void Link::setGenCoor(quint8 index)
{
    genCoorIndex = index;
}

void Link::deleteGenCoor()
{
    genCoorIndex = -1;
}
