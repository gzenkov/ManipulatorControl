#include "manipulator.h"

Manipulator::Manipulator()
{
    recentPosition << 0,0,0;
}

void Manipulator::updateRecentPosition()
{
    quint8 size = links.size();

    if (size)
    {
        Eigen::Matrix4d temp = links.constFirst().m_transMat;
        for (quint8 i=1; i<size; ++i)
            temp *= links.at(i).m_transMat;

        recentPosition = temp.col(3).head(3);
    }
    else
        recentPosition << 0,0,0;
}
