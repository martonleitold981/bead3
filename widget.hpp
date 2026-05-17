#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"

class app;

class widget
{
protected:
    int _x, _y, _size_x, _size_y;
    app* _parent;
public:
    widget(app*, int x, int y, int sx, int sy);
    virtual bool kivalasztva(int mx, int my);
    virtual void rajzol() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual void novel() = 0;
    virtual void csokkent() = 0;
    virtual bool folottefel(int mx, int my) = 0;
    virtual bool folottele(int mx, int my) = 0;

};

#endif // WIDGET_HPP
