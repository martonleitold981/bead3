#ifndef APP_HPP
#define APP_HPP
#include <vector>
#include "widget.hpp"

class app
{
public:
    app();
    void event_loop();
    void register_widget(widget*);
    virtual void event_handle(genv::event ev);
protected:
    std::vector<widget *>widgets;
};

#endif // APP_HPP
