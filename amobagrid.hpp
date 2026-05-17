#ifndef AMOBAGRID_HPP
#define AMOBAGRID_HPP

#include "widget.hpp"
#include "JatekMester.hpp"

class AmobaGrid : public widget {
private:
    JatekMester* _mester;
    int _cella_meret;

public:
    AmobaGrid(app* parent, int x, int y, int sx, int sy, JatekMester* mester);
    virtual void rajzol() override;
    virtual void handle(genv::event ev) override;
    virtual void novel() override;
    virtual void csokkent() override;
    virtual bool folottefel(int mx, int my) override;
    virtual bool folottele(int mx, int my) override;
};

#endif // AMOBAGRID_HPP
