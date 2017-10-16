#ifndef MANIPULATOR_H
#define MANIPULATOR_H

#include <QList>
#include "link.h"


class Manipulator
{
public:
    Manipulator();

    void updateRecentPosition();
    Eigen::Vector3d getPossiblePosition(double *coor);
    QList<Link> links;

    Eigen::Vector3d recentPosition;
};

inline Eigen::Vector3d Manipulator::getPossiblePosition(double *coor) //for later use
{

}

#endif // MANIPULATOR_H
