//
// Created by matthew on 20/06/2020.
//

#ifndef CODING_TEST_20_DISCRETEFOURIERTRANSFORM_H
#define CODING_TEST_20_DISCRETEFOURIERTRANSFORM_H


#include "IFourierTransform.h"

class DiscreteFourierTransform : public IFourierTransform
{
public:
    void ForwardTransform(std::vector<std::complex<double>>& data) override;
    void ReverseTransform(std::vector<std::complex<double>>& data) override;

};


#endif //CODING_TEST_20_DISCRETEFOURIERTRANSFORM_H
