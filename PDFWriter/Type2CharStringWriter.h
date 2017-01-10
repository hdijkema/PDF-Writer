/*
   Source File : Type2CharStringWriter.h


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

using namespace IOBasicTypes;

class PW_EXTERN IByteWriter;

class PW_EXTERN Type2CharStringWriter
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	Type2CharStringWriter(IByteWriter* inTargetStream);
	~Type2CharStringWriter(void);

	void Assign(IByteWriter* inTargetStream);

	PDFHummus::EStatusCode WriteHintMask(unsigned long inMask,unsigned long inMaskSize);
	PDFHummus::EStatusCode WriteIntegerOperand(long inOperand);
	PDFHummus::EStatusCode WriteOperator(unsigned short inOperatorCode);


private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif

	IByteWriter* mTargetStream;

	PDFHummus::EStatusCode WriteMaskBytes(unsigned long inMask,unsigned long inMaskByteSize);
	PDFHummus::EStatusCode WriteByte(Byte inValue);
};
