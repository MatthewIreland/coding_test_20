//
// Created by matthew on 20/06/2020.
//

#ifndef CODING_TEST_20_IFOURIERTRANSFORM_H
#define CODING_TEST_20_IFOURIERTRANSFORM_H

#include <complex>
#include <vector>

class DataSizeNotAPowerOf2Exception : public std::exception
{

};

class IFourierTransform
{
public:
    /**
     * Computes the forward Fourier transform (in place) of a vector of complex numbers
     *
     * @param data vector of numbers to transform
     * @throws DataSizeNotAPowerOf2Exception if data.size() is not a power of 2
     */
    virtual void ForwardTransform(std::vector<std::complex<double>>& data) = 0;

    /**
     * Computes the inverse Fourier transform (in place) of a vector of complex numbers
     *
     * @param data vector of numbers to inverse transform
     * @throws DataSizeNotAPowerOf2Exception if data.size() is not a power of 2
     */
    virtual void ReverseTransform(std::vector<std::complex<double>>& data) = 0;
};

#endif //CODING_TEST_20_IFOURIERTRANSFORM_H
