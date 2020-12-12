#ifndef CANON_H
#define CANON_H


class canon
{
private:

    float h;
    float alpha;
    float rango;

public:

    //Constructor
    canon();

    //Métodos
    float getH() const;
    void setH(float value);
    float getAlpha() const;
    void setAlpha(float value);
    float getRango() const;
    void setRango(float value);
};

#endif // CANON_H
