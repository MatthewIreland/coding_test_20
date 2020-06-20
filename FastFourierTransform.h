//
// Created by matthew on 20/06/2020.
//

#ifndef CODING_TEST_20_FASTFOURIERTRANSFORM_H
#define CODING_TEST_20_FASTFOURIERTRANSFORM_H


#include "IFourierTransform.h"

class FastFourierTransform : public IFourierTransform
{
public:
    void ForwardTransform(std::vector<std::complex<double>>& data) override;
    void ReverseTransform(std::vector<std::complex<double>>& data) override;
};


#endif //CODING_TEST_20_FASTFOURIERTRANSFORM_H
