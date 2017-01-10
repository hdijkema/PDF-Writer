/*
   Source File : InputCharStringDecodeStream.h


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
#include "IByteReader.h"
#include "EStatusCode.h"
 

using namespace IOBasicTypes;


class PW_EXTERN InputCharStringDecodeStream : public IByteReader
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	InputCharStringDecodeStream(IByteReader* inReadFrom,unsigned long inLenIV=4);
	~InputCharStringDecodeStream(void);

	void Assign(IByteReader* inReadFrom,unsigned long inLenIV=4);

	// IByteReader implementation

	virtual LongBufferSizeType Read(Byte* inBuffer,LongBufferSizeType inBufferSize);
	virtual bool NotEnded();

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif
	IByteReader* mReadFrom;
	unsigned short mRandomizer;


	void InitializeCharStringDecode(unsigned long inLenIV);
	PDFHummus::EStatusCode ReadDecodedByte(Byte& outByte);
	Byte DecodeByte(Byte inByteToDecode);

};
