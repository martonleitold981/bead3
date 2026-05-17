#include "app.hpp"
#include "graphics.hpp"

using namespace genv;

app::app() {
    genv::gout.open(600, 640);
}
void app::event_loop(){
    event ev;
    int focus = -1;
    while(gin >> ev){
        if(ev.type == ev_mouse && ev.button == btn_left){
            for (size_t i = 0; i < widgets.size(); ++i) {
                if(widgets[i]->kivalasztva(ev.pos_x, ev.pos_y)){
                    focus = i;
                }
            }
        }
        if(focus != -1){
            widgets[focus]->handle(ev);
        }

        for (widget *w : widgets) {
            w->rajzol();
        }
        event_handle(ev);
        gout << refresh;
    }
}
void app::register_widget(widget *w){
    widgets.push_back(w);
}
void app::event_handle(event ev){

}
