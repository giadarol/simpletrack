#ifndef NAN
  #include <math.h>
#endif

#ifndef  DRIFT_TRACK
  #define DRIFT_TRACK
#endif


typedef struct {
    REAL(length);
} Drift;

void Drift_track(ELEMENT_MEM Drift *el, PARTICLE(pp)){
    REAL(const length) = el->length;
    ELEMENT_START
        REAL(const xp) = PX(pp)*RPP(pp);
        REAL(const yp) = PY(pp)*RPP(pp);
        X(pp)+= xp * length;
        Y(pp)+= yp * length;
        ZETA(pp) += length*(RVV(pp)-(1+(xp*xp+yp*yp)/2));
    ELEMENT_STOP
};

void DriftExact_track(ELEMENT_MEM Drift *el, PARTICLE(pp)){
    REAL(const length) = el->length;
    ELEMENT_START
        REAL(const opd) = 1 + DELTA(pp);
        REAL(const px) = PX(pp);
        REAL(const py) = PY(pp);
        REAL(const lpzi) = length / sqrt(opd*opd- px*px- py*py);
        X(pp)+= px * length;
        Y(pp)+= py * length;
        ZETA(pp) += length*RVV(pp) - opd*lpzi;
    ELEMENT_STOP
};
