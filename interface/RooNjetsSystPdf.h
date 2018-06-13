#ifndef ROONJETSSYSTPDF
#define ROONJETSSYSTPDF

#include "RooAbsPdf.h"
#include "RooRealProxy.h"
#include "RooCategoryProxy.h"
#include "RooAbsReal.h"
#include "RooAbsCategory.h"
#include "TH1D.h"
 
class RooNjetsSystPdf : public RooAbsPdf {
public:
  RooNjetsSystPdf() {} ; 
  RooNjetsSystPdf(const char *name, const char *title,
              RooAbsReal& _x,
              RooAbsReal& _p0,
              RooAbsReal& _p1,
              RooAbsReal& _p2,
	      RooAbsReal& _p3,
	      RooAbsReal& _np,
	      TH1D _syst);
  RooNjetsSystPdf(const RooNjetsSystPdf& other, const char* name=0);
  virtual TObject* clone(const char* newname) const { return new RooNjetsSystPdf(*this,newname); }
  //inline virtual ~RooNjetsSystPdf() { };

protected:

  RooRealProxy x ;
  RooRealProxy p0 ;
  RooRealProxy p1 ;
  RooRealProxy p2 ;
  RooRealProxy p3 ;
  RooRealProxy np ;
  mutable TH1D syst ;
  
  Double_t evaluate() const ;
  Int_t getAnalyticalIntegral(RooArgSet& allVars, RooArgSet& analVars, const char* rangeName=0) const;
  Double_t analyticalIntegral(Int_t code, const char* rangeName) const;

private:

  ClassDef(RooNjetsSystPdf,1) // Your description goes here...
};
 
#endif
