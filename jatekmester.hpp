#ifndef JATEKMESTER_HPP
#define JATEKMESTER_HPP

#include <vector>
#include <string>

enum Jatekos { SENKI, X_JATEKOS, O_JATEKOS };

class JatekMester {
private:
    int _meret;
    std::vector<std::vector<Jatekos>> _palya;
    Jatekos _aktualis_jatekos;
    bool _jatek_vege;
    std::string _uzenet;
    bool ellenoriz_irany(int sor, int oszlop, int d_sor, int d_oszlop);
public:
    JatekMester(int meret = 15);
    void uj_jatek();
    bool lep(int sor, int oszlop);
    Jatekos get_cella(int sor, int oszlop) const { return _palya[sor][oszlop]; }
    Jatekos get_aktualis() const { return _aktualis_jatekos; }
    int get_meret() const { return _meret; }
    bool vege_van() const { return _jatek_vege; }
    std::string get_uzenet() const { return _uzenet; }
};

#endif // JATEKMESTER_HPP
