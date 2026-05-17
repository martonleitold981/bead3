#include "app.hpp"
#include "JatekMester.hpp"
#include "AmobaGrid.hpp"

class AmobaApp : public app {
public:
    AmobaApp() {
        JatekMester* mester = new JatekMester(15);
        AmobaGrid* grid = new AmobaGrid(this, 0, 0, 600, 640, mester);
        register_widget(grid);
    }
};

int main() {
    AmobaApp jatek;
    jatek.event_loop();
    return 0;
}
