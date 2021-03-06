#include "gui/extra_panel.hpp"
#include "editor.hpp"

ExtraPanel* ExtraPanel::m_extra_panel = 0;

// ----------------------------------------------------------------------------
void ExtraPanel::init()
{
    Editor* editor = Editor::getEditor();
    IGUIEnvironment* gui_env = editor->getGUIEnv();
    path icons = editor->getIconsLoc();

    m_wndw->setRelativePosition(position2di(0, 50));

    gui_env->addStaticText(_(L"Items:"), rect<s32>(10, 10, 200, 30),
                           false, false, m_wndw, -1, false)->setOverrideFont(editor->getFont());


    IGUIButton* b4 = gui_env->addButton(rect<s32>(10,  50, 60,  100), m_wndw, BTN_BANANA);
    IGUIButton* b5 = gui_env->addButton(rect<s32>(70,  50, 120, 100), m_wndw, BTN_ITEM);
    IGUIButton* b6 = gui_env->addButton(rect<s32>(130, 50, 180, 100), m_wndw, BTN_SNITRO);
    IGUIButton* b7 = gui_env->addButton(rect<s32>(190, 50, 240, 100), m_wndw, BTN_BNITRO);

    b4->setImage(Editor::loadImg(icons + L"banana.png"));
    b5->setImage(Editor::loadImg(icons + L"gift.png"));
    b6->setImage(Editor::loadImg(icons + L"snitro.png"));
    b7->setImage(Editor::loadImg(icons + L"bnitro.png"));

} // init

// ----------------------------------------------------------------------------
ExtraPanel* ExtraPanel::getExtraPanel(IGUIWindow* wndw)
{
    if (m_extra_panel != 0) return m_extra_panel;

    m_extra_panel = new ExtraPanel();
    m_extra_panel->m_wndw = wndw;
    m_extra_panel->init();
    return m_extra_panel;
} // getTerrPanel

// ----------------------------------------------------------------------------
void ExtraPanel::reallocate(dimension2du ss)
{
    m_wndw->setMinSize(dimension2du(250, ss.Height - 50));
} // reallocate

