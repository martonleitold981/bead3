#include "JatekMester.hpp"

JatekMester::JatekMester(int meret) : _meret(meret) {
    if (_meret < 15) _meret = 15;
    if (_meret > 30) _meret = 30;
    uj_jatek();
}
void JatekMester::uj_jatek() {
    _palya.assign(_meret, std::vector<Jatekos>(_meret, SENKI));
    _aktualis_jatekos = X_JATEKOS;
    _jatek_vege = false;
    _uzenet = "X jatekosa jon!";
}
bool JatekMester::ellenoriz_irany(int sor, int oszlop, int d_sor, int d_oszlop) {
    Jatekos j = _palya[sor][oszlop];
    if (j == SENKI) return false;
    int db = 1;
    int r = sor + d_sor;
    int c = oszlop + d_oszlop;
    while (r >= 0 && r < _meret && c >= 0 && c < _meret && _palya[r][c] == j) {
        db++;
        r += d_sor;
        c += d_oszlop;
    }
    r = sor - d_sor;
    c = oszlop - d_oszlop;
    while (r >= 0 && r < _meret && c >= 0 && c < _meret && _palya[r][c] == j) {
        db++;
        r -= d_sor;
        c -= d_oszlop;
    }
    return db >= 5;
}
bool JatekMester::lep(int sor, int oszlop) {
    if (_jatek_vege || sor < 0 || sor >= _meret || oszlop < 0 || oszlop >= _meret) return false;
    if (_palya[sor][oszlop] != SENKI) return false;
    _palya[sor][oszlop] = _aktualis_jatekos;
    if (ellenoriz_irany(sor, oszlop, 0, 1) ||
        ellenoriz_irany(sor, oszlop, 1, 0) ||
        ellenoriz_irany(sor, oszlop, 1, 1) ||
        ellenoriz_irany(sor, oszlop, 1, -1)) {
        _jatek_vege = true;

        if (_aktualis_jatekos == X_JATEKOS) {
            _uzenet = "X NYERT!";
        } else {
            _uzenet = "O NYERT!";
        }
        return true;
    }
    bool van_ures = false;
    for (int i = 0; i < _meret; ++i) {
        for (int j = 0; j < _meret; ++j) {
            if (_palya[i][j] == SENKI) van_ures = true;
        }
    }
    if (!van_ures) {
        _jatek_vege = true;
        _uzenet = "Döntetlen! Betelt a palya.";
        return true;
    }
    if (_aktualis_jatekos == X_JATEKOS) {
        _aktualis_jatekos = O_JATEKOS;
        _uzenet = "O jatekosa jon!";
    } else {
        _aktualis_jatekos = X_JATEKOS;
        _uzenet = "X jatekosa jon!";
    }
    return true;
}
