#include "widget.hpp"
#include "app.hpp"
#include "widget.hpp"
using namespace genv;

widget::widget(app *parent, int x, int y, int sx, int sy): _parent(parent), _x(x), _y(y), _size_x(sx), _size_y(sy) {
    _parent->register_widget(this);
}

bool widget::kivalasztva(int mx, int my){
    return mx>_x && mx<_x+_size_x && my>_y && my<_y+_size_y;
}
