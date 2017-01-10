/*
   Source File : InputStringBufferStream.h


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

#include "IByteReaderWithPosition.h"
#include "MyStringBuf.h"

#include <sstream>
#include <string>



class PW_EXTERN InputStringBufferStream : public IByteReaderWithPosition
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	InputStringBufferStream(MyStringBuf* inBufferToReadFrom);
	~InputStringBufferStream(void);

	void Assign(MyStringBuf* inBufferToReadFrom);

	// IByteReaderWithPosition implementation
	virtual LongBufferSizeType Read(Byte* inBuffer,LongBufferSizeType inBufferSize);
	virtual bool NotEnded();
	virtual void Skip(LongBufferSizeType inSkipSize);
	virtual void SetPosition(LongFilePositionType inOffsetFromStart);
	virtual void SetPositionFromEnd(LongFilePositionType inOffsetFromEnd);
	virtual LongFilePositionType GetCurrentPosition();

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif
	MyStringBuf* mBufferToReadFrom;


};
