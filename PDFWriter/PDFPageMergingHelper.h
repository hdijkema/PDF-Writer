/*
 Source File : PDFPageMergingHelper.h
 
 
 Copyright 2012 Gal Kahana PDFWriter
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 
 
 */
#pragma once
#include "PDFWriterGlobal.h"

#include "EStatusCode.h"

#include <string>



class PW_EXTERN PDFPage;
class PW_EXTERN IByteReaderWithPosition;
class PW_EXTERN PDFDocumentCopyingContext;
class PW_EXTERN PDFWriter;

class PW_EXTERN PDFPageMergingHelper
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif

    PDFPageMergingHelper(PDFPage* inPage);
	virtual ~PDFPageMergingHelper(void);
    
    PDFHummus::EStatusCode MergePageContent(PDFDocumentCopyingContext* inCopyingContext,unsigned long inPageIndex);
    PDFHummus::EStatusCode MergePageContent(PDFWriter* inWriter,const std::string& inPDFFilePath,unsigned long inPageIndex);
    PDFHummus::EStatusCode MergePageContent(PDFWriter* inWriter,IByteReaderWithPosition* inPDFStream,unsigned long inPageIndex);
    
private:
#    ifdef _MSC_VER
#      pragma warning(disable:4251)
#    endif
    
    PDFPage* mPage;
};
