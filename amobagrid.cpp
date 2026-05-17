#include "AmobaGrid.hpp"
#include "graphics.hpp"

using namespace genv;

AmobaGrid::AmobaGrid(app* parent, int x, int y, int sx, int sy, JatekMester* mester)
    : widget(parent, x, y, sx, sy), _mester(mester) {
    _cella_meret = (_size_y - 40) / _mester->get_meret();
}
void AmobaGrid::rajzol() {
    gout << move_to(_x, _y) << color(20, 20, 20) << box(_size_x, _size_y);
    int m = _mester->get_meret();
    gout << color(100, 100, 100);
    for (int i = 0; i <= m; ++i) {
        gout << move_to(_x, _y + i * _cella_meret) << line(m * _cella_meret, 0);
        gout << move_to(_x + i * _cella_meret, _y) << line(0, m * _cella_meret);
    }
    for (int s = 0; s < m; ++s) {
        for (int o = 0; o < m; ++o) {
            Jatekos j = _mester->get_cella(s, o);
            int cx = _x + o * _cella_meret;
            int cy = _y + s * _cella_meret;
            int padding = 4;

            if (j == X_JATEKOS) {
                gout << color(255, 50, 50);
                gout << move_to(cx + padding, cy + padding) << line(_cella_meret - 2 * padding, _cella_meret - 2 * padding);
                gout << move_to(cx + _cella_meret - padding, cy + padding) << line(-_cella_meret + 2 * padding, _cella_meret - 2 * padding);
            }
            else if (j == O_JATEKOS) {
                gout << color(50, 50, 255);
                gout << move_to(cx + padding, cy + padding) << box(_cella_meret - 2 * padding, _cella_meret - 2 * padding);
                gout << move_to(cx + padding + 2, cy + padding + 2) << color(20, 20, 20) << box(_cella_meret - 2 * padding - 4, _cella_meret - 2 * padding - 4);
            }
        }
    }
    gout << move_to(_x + 10, _y + m * _cella_meret + 15) << color(255, 255, 255) << text(_mester->get_uzenet());
    gout << move_to(_x + 10, _y + m * _cella_meret + 30) << color(150, 150, 150) << text("Uj jatekhoz nyomj [R] billentyut!");
}
void AmobaGrid::handle(event ev) {
    if (ev.type == ev_mouse && ev.button == btn_left) {
        int m = _mester->get_meret();
        int r_max = m * _cella_meret;

        if (ev.pos_x >= _x && ev.pos_x < _x + r_max && ev.pos_y >= _y && ev.pos_y < _y + r_max) {
            int oszlop = (ev.pos_x - _x) / _cella_meret;
            int sor = (ev.pos_y - _y) / _cella_meret;

            _mester->lep(sor, oszlop);
        }
    }
    if (ev.type == ev_key && (ev.keycode == 'r' || ev.keycode == 'R')) {
        _mester->uj_jatek();
    }
}
void AmobaGrid::novel() {}
void AmobaGrid::csokkent() {}
bool AmobaGrid::folottefel(int, int) { return false; }
bool AmobaGrid::folottele(int, int) { return false; }
