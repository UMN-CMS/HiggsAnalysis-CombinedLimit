How to prepare the QCD CR systematic inputs
===========================================

### Overview

The code in this directory performs a 2nd-order polynomial fit of the QCD CR
systematic histogram for each year, MVA-bin combination.  The polynomial
fit parameters are transformed using a matrix composed of the eigenvectors
of the covariance matrix to a space where the three parameters are uncorrelated.
This allows the fit to be represented by three uncorrelated, Gaussian-constrained
nuisance parameters.


