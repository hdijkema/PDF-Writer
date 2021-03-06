/*
   Source File : OutputStreamTraits.h


   Copyright 2011 Gal Kahana PDFWriter

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
#include "IOBasicTypes.h"

class PW_EXTERN IByteWriter;
class PW_EXTERN IByteReader;

using namespace IOBasicTypes;

class PW_EXTERN OutputStreamTraits
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	OutputStreamTraits(IByteWriter* inOutputStream);
	~OutputStreamTraits(void);


	PDFHummus::EStatusCode CopyToOutputStream(IByteReader* inInputStream);	
	PDFHummus::EStatusCode CopyToOutputStream(IByteReader* inInputStream,LongBufferSizeType inLength);	

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif

	IByteWriter* mOutputStream;
};
