/*
   Source File : OutputFileStream.h


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
#include "IByteWriterWithPosition.h"

#include <string>
#include <stdio.h>
#ifdef __MINGW32__
#include <share.h>
#endif



class PW_EXTERN OutputFileStream : public IByteWriterWithPosition
{
public:
#ifdef _MSC_VER
#  pragma warning(default:4251)
#endif
	OutputFileStream(void);
	virtual ~OutputFileStream(void);

	// input file path is in UTF8
	OutputFileStream(const std::string& inFilePath,bool inAppend = false);

	// input file path is in UTF8
	PDFHummus::EStatusCode Open(const std::string& inFilePath,bool inAppend = false);
	PDFHummus::EStatusCode Close();

	// IByteWriter implementation
	virtual IOBasicTypes::LongBufferSizeType Write(const IOBasicTypes::Byte* inBuffer,IOBasicTypes::LongBufferSizeType inSize);

	// IByteWriterWithPosition implementation
	virtual IOBasicTypes::LongFilePositionType GetCurrentPosition();

private:
#ifdef _MSC_VER
#  pragma warning(disable:4251)
#endif

	FILE* mStream;
};
