///////////////////////////////////////////////////////////////////////////////
// PDFArrayIterator.h       Stefan Woerthmueller 2014  StefanWoe@googlemail.com
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "PDFWriterGlobal.h"
#include "PDFWriter.h"
#include "PDFObjectCast.h"
#include "PDFArray.h"

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
class PW_EXTERN PDFDictionaryIterator;

class PW_EXTERN PDFArrayIterator
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
    PDFArrayIterator(PDFParser &parser) :
                        mParser(parser)
    {
    }
    PDFArrayIterator(PDFParser &parser, PDFObjectCastPtr<PDFArray> &inArray) :
                        mArray(inArray),
                        mParser(parser)
    {
    }

    PDFDictionaryIterator DictAt(int ndx);
    unsigned long         GetLength();

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif
    PDFObjectCastPtr<PDFArray> mArray;
    PDFParser &mParser;
};
