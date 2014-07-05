#ifndef ROADCOMMAND_HPP
#define ROADCOMMAND_HPP

#include "commands/icmd.hpp"
#include "spline/ispline.hpp"

#include <irrlicht.h>

using namespace irr;
using namespace scene;
using namespace core;


class IRoad;
struct ControlPoint;

// ----------------------------------------------------------------------------
class RoadCmd :public ICmd
{
private:
    IRoad*          m_road;
    ISpline*        m_spline;
    vector3df       m_pos;
    bool            m_insert;
    bool            m_created;
    u32             m_ix;
    ControlPoint    m_cp;
public:
    RoadCmd(IRoad* road, bool insert);
    virtual ~RoadCmd() {};
    void updatePos(vector3df pos);
    void redo();
    void undo();
};

#endif
