#include <math.h>


double Cdhc_enormp(double x)
{
    double x1, x2, x3, x4, ret_val;

    static double xp[5] = { 7.7105849500132e-5, -0.00133733772997339,
        0.0323076579225834, 0.0479137145607681, 0.128379167095513
    };
    static double xq[3] = { 0.00301048631703895, 0.0538971687740286,
        0.375795757275549
    };
    static double xr[8] = { -1.36864857382717e-7, 0.564195517478974,
        7.21175825088309, 43.1622272220567, 152.98928504694,
        339.320816734344, 451.918953711873, 300.459261020162
    };
    static double xs[8] = { 1.0, 12.7827273196294, 77.0001529352295,
        277.585444743988, 638.980264465631, 931.35409485061,
        790.950925327898, 300.459260956983
    };
    static double xt[5] = { 2.10144126479064, 26.2370141675169,
        21.3688200555087, 4.6580782871847, 0.282094791773523
    };
    static double xu[4] = { 94.153775055546, 187.11481179959,
        99.0191814623914, 18.0124575948747
    };
    double yy1, yy2;

    x3 = (double)0.564189583547756;
    x1 = fabs(x);

    if (x1 <= .5) {
        x4 = x * x;
        yy1 =
            (((xp[0] * x4 + xp[1]) * x4 + xp[2]) * x4 + xp[3]) * x4 + xp[4] +
            1.;
        yy2 = ((xq[0] * x4 + xq[1]) * x4 + xq[2]) * x4 + 1.;
        ret_val = x * (yy1 / yy2);
    }
    else if (x1 <= 4.) {
        yy1 = ((((((xr[0] * x1 + xr[1]) * x1 + xr[2]) * x1 + xr[3])
                 * x1 + xr[4]) * x1 + xr[5]) * x1 + xr[6]) * x1 + xr[7];
        yy2 = ((((((xs[0] * x1 + xs[1]) * x1 + xs[2]) * x1 + xs[3])
                 * x1 + xs[4]) * x1 + xs[5]) * x1 + xs[6]) * x1 + xs[7];
        ret_val = 1. - exp(-x * x) * yy1 / yy2;
        if (x < 0.)
            ret_val *= -1.0;
    }
    else {
        x2 = x * x;
        x4 *= 1.;               /* huh, what? See original FORTRAN */
        x4 = 0.5;
        yy1 = (((xt[0] * x4 + xt[1]) * x4 + xt[2]) * x4 + xt[3]) * x4 + xt[4];
        yy2 = (((xu[0] * x4 + xu[1]) * x4 + xu[2]) * x4 + xu[3]) * x4 + 1.;
        ret_val = x3 / x1 - yy1 * x1 / (x2 * yy2);
        ret_val = 1. - exp(-x2) * ret_val;
        if (x < 0.)
            ret_val = -ret_val;
    }

    return ret_val;
}
