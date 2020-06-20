//
// Created by matthew on 20/06/2020.
//

#include "DiscreteFourierTransform.h"

void DiscreteFourierTransform::ForwardTransform(std::vector<std::complex<double>> &dataVec)
{
    if (0 != (dataVec.size() & (dataVec.size() - 1)))
    {
        throw DataSizeNotAPowerOf2Exception();
    }

    auto result = std::vector<std::complex<double>>(dataVec.size());

    for (int k=0; k<dataVec.size(); ++k)
    {
        result[k] = std::complex<double>(0, 0);
        for (int i=0; i<dataVec.size(); ++i)
        {
            result[k] += dataVec[i] * (
                                              std::complex<double>(
                                                      cos(2.0*M_PI*k*i/dataVec.size()),
                                                      -sin(2.0*M_PI*k*i/dataVec.size())
                                              )
                    );
        }
    }

    for (int i=0; i<dataVec.size(); ++i)
    {
        dataVec[i] = result[i];
    }
}

void DiscreteFourierTransform::ReverseTransform(std::vector<std::complex<double>> &dataVec)
{
    if (0 != (dataVec.size() & (dataVec.size() - 1)))
    {
        throw DataSizeNotAPowerOf2Exception();
    }

    auto result = std::vector<std::complex<double>>(dataVec.size());

    for (int k=0; k<dataVec.size(); ++k)
    {
        result[k] = std::complex<double>(0, 0);
        for (int i=0; i<dataVec.size(); ++i)
        {
            result[k] += dataVec[i] * (
                                              std::complex<double>(
                                                      cos(2.0*M_PI*k*i/dataVec.size()),
                                                      sin(2.0*M_PI*k*i/dataVec.size())
                                              )
                    );
        }
    }

    for (int i=0; i<dataVec.size(); ++i)
    {
        dataVec[i] = 1.0 / dataVec.size() * result[i];
    }
}
