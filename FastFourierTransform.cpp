//
// Created by matthew on 20/06/2020.
//

#include "FastFourierTransform.h"

void FastFourierTransform::ForwardTransform(std::vector<std::complex<double>> &dataVec)
{
    if (0 != (dataVec.size() & (dataVec.size() - 1)))
    {
        throw DataSizeNotAPowerOf2Exception();
    }

    auto data = new double[dataVec.size()*2];

    for (int i=0; i<dataVec.size(); ++i)
    {
        data[2*i] = dataVec[i].real();
        data[2*i+1] = dataVec[i].imag();
    }

    unsigned long n, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;

    // reverse-binary reindexing
    auto nn = dataVec.size();
    n = nn<<1u;
    j=1;
    for (i=1; i<n; i+=2) {
        if (j>i) {
            auto tmpD = data[j-1];
            data[j-1] = data[i-1];
            data[i-1] = tmpD;

            tmpD = data[j];
            data[j] = data[i];
            data[i] = tmpD;
        }
        m = nn;
        while (m>=2 && j>m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    };

    // here begins the Danielson-Lanczos section
    mmax=2;
    while (n>mmax) {
        istep = mmax<<1u;
        theta = -(2*M_PI/mmax);
        wtemp = sin(0.5*theta);
        wpr = -2.0*wtemp*wtemp;
        wpi = sin(theta);
        wr = 1.0;
        wi = 0.0;
        for (m=1; m < mmax; m += 2) {
            for (i=m; i <= n; i += istep) {
                j=i+mmax;
                tempr = wr*data[j-1] - wi*data[j];
                tempi = wr * data[j] + wi*data[j-1];

                data[j-1] = data[i-1] - tempr;
                data[j] = data[i] - tempi;
                data[i-1] += tempr;
                data[i] += tempi;
            }
            wtemp=wr;
            wr += wr*wpr - wi*wpi;
            wi += wi*wpr + wtemp*wpi;
        }
        mmax=istep;
    }

    for (auto k=0; k<dataVec.size(); ++k)
    {
        dataVec[k] = std::complex<double>(data[2*k], data[2*k+1]);
    }
}

void FastFourierTransform::ReverseTransform(std::vector<std::complex<double>> &dataVec)
{
    if (0 != (dataVec.size() & (dataVec.size() - 1)))
    {
        throw DataSizeNotAPowerOf2Exception();
    }

    auto data = new double[dataVec.size()*2];

    for (int i=0; i<dataVec.size(); ++i)
    {
        data[2*i] = dataVec[i].real();
        data[2*i+1] = -1 * dataVec[i].imag();
    }

    unsigned long n, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;

    // reverse-binary reindexing
    auto nn = dataVec.size();
    n = nn<<1u;
    j=1;
    for (i=1; i<n; i+=2) {
        if (j>i) {
            auto tmpD = data[j-1];
            data[j-1] = data[i-1];
            data[i-1] = tmpD;

            tmpD = data[j];
            data[j] = data[i];
            data[i] = tmpD;
        }
        m = nn;
        while (m>=2 && j>m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    };

    // here begins the Danielson-Lanczos section
    mmax=2;
    while (n>mmax) {
        istep = mmax<<1u;
        theta = -(2*M_PI/mmax);
        wtemp = sin(0.5*theta);
        wpr = -2.0*wtemp*wtemp;
        wpi = sin(theta);
        wr = 1.0;
        wi = 0.0;
        for (m=1; m < mmax; m += 2) {
            for (i=m; i <= n; i += istep) {
                j=i+mmax;
                tempr = wr*data[j-1] - wi*data[j];
                tempi = wr * data[j] + wi*data[j-1];

                data[j-1] = data[i-1] - tempr;
                data[j] = data[i] - tempi;
                data[i-1] += tempr;
                data[i] += tempi;
            }
            wtemp=wr;
            wr += wr*wpr - wi*wpi;
            wi += wi*wpr + wtemp*wpi;
        }
        mmax=istep;
    }


    for (auto k=0; k<dataVec.size(); ++k)
    {
        dataVec[k] = 1.0/dataVec.size() * std::complex<double>(data[2*k], -1 * data[2*k+1]);
    }
}
