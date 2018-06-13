#ifndef ROONJETSPDF
#define ROONJETSPDF

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
 
class RooNjetsPdf : public RooAbsPdf {
public:
  RooNjetsPdf() {} ; 
  RooNjetsPdf(const char *name, const char *title,
              RooAbsReal& _x,
              RooAbsReal& _p0,
              RooAbsReal& _p1,
              RooAbsReal& _p2,
              RooAbsReal& _p3);
  RooNjetsPdf(const RooNjetsPdf& other, const char* name=0) ;
  virtual TObject* clone(const char* newname) const { return new RooNjetsPdf(*this,newname); }
  inline virtual ~RooNjetsPdf() { };

protected:

  RooRealProxy x ;
  RooRealProxy p0 ;
  RooRealProxy p1 ;
  RooRealProxy p2 ;
  RooRealProxy p3 ;
  
  Double_t evaluate() const ;
  Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* rangeName=0) const;
  Double_t analyticalIntegral(Int_t code, const char* rangeName) const;

private:

  ClassDef(RooNjetsPdf,1) // Your description goes here...
};
 
#endif
