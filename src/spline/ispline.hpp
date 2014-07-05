#ifndef ISPLINE_HPP
#define ISPLINE_HPP

#include "mesh/mesh_structs.hpp"

#include <irrlicht.h>



using namespace irr;
using namespace scene;
using namespace core;

struct ControlPoint
{
    vector3df        vel;
    vector3df        pos;
    vector3df        normal;
    float            width;
    float            t;
    ISceneNode*      node;
    ISceneNode*      normal_node;
    ISceneNode*      width_node;
};

class ISpline :public ISceneNode
{
// ----------------------------------------------------------------------------
    // variables

private:
    aabbox3d<f32>       m_bounding_box;
protected:
    list<ControlPoint>  m_control_points;
    int                 m_cp_num;

// ----------------------------------------------------------------------------
    // functions
protected:
    vector3df       calculateVelInPoint(vector3df pm1, vector3df p0, vector3df p1,
                                        list<ControlPoint>::Iterator it);
    void            calculateVelocity();
    ControlPoint    newControlPoint(vector3df p);

// ----------------------------------------------------------------------------
public:
    ISpline(ISceneNode* parent, ISceneManager* mgr, s32 id);

    virtual vector3df   p(float t) = 0;
    virtual vector3df   getNormal(float t) = 0;
    virtual float       getWidth(float t) = 0;
    void                setNodeVisibility(bool visible);
    u32                 addControlPoint(vector3df p);
    u32                 insertControlPoint(vector3df p);
    void                addControlPoint(ControlPoint cp);
    void                addControlPoint(ControlPoint cp, u32 pos);
    ControlPoint        removeControlPoint(u32 ix);
    ISceneNode*         getNode(u32 ix);
    void                updatePosition();
    bool                hasEnoughPoints()   { return m_cp_num > 1; }
    int                 getPointNum()       { return m_cp_num;     }

// ----------------------------------------------------------------------------
    // inherited functions - ISceneNode
    void                 OnRegisterSceneNode();
    void                 render();

    const aabbox3d<f32>& getBoundingBox()   const { return m_bounding_box; }
    u32                  getMaterialCount() const { return 1; }
};
#endif